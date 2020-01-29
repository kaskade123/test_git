#include<vxWorks.h>
#include<stdio.h>
#include<sacDev.h>
#include<stdlib.h>
#include<string.h>
#include<sysLib.h>
#include<taskLib.h>
#include<time.h>
#include"QDGJ_test.h"
#include"Lib.h"
#include"xd_globals.h"

#define QG_N 6 /*启动告警待申请句柄设备数*/
#define GJ_OUT 0
#define GJ_OUT2 1
#define GJ_IN 2
#define QD_OUT 3
#define QD_OUT2 4
#define QD_IN 5

/************************启动告警信号任务测试程序******************/
INT32 task_QD_GJ(void)
{
	INT32 hdr_QG[QG_N] = { 0 }, h_cnt = 0, n_cnt = 0,
		  rl_cnt = 0, ret = 0;
	char *QG_DEVICE_NAME[QG_N] = { "GJ_OUT", "GJ_OUT2", "GJ_IN",
								"QD_OUT", "QD_OUT2", "QD_IN" };
	
	/*按照名称依次申请启动告警句柄*/
	for (h_cnt = 0; h_cnt < QG_N; h_cnt++)
	{
		hdr_QG[h_cnt] = QD_GJ_DeviceSearch(QG_DEVICE_NAME[n_cnt++]);
		if (hdr_QG[h_cnt] < 0)
		{
			ret = -EFAULT;
			goto Release_QD_GJ;
		}
	}
	/*启动告警信号置1并读取反馈值*/
	while (1)
	{
		if (GPIOSet(hdr_QG[GJ_OUT], 1) || GPIOSet(hdr_QG[GJ_OUT2], 1)
				|| GPIOSet(hdr_QG[QD_OUT], 1) || GPIOSet(hdr_QG[QD_OUT2], 1))
		{
			logMsg("The GPIOSet Error\n", 0, 0, 0, 0, 0, 0);
			continue;
		}
		taskDelay(sysClkRateGet());
		if (!GPIOGet(hdr_QG[GJ_IN]))
		{
			logMsg("The GJ_IN is not 1\n", 0, 0, 0, 0, 0, 0);
			G_ERROR.GJ_fdback += 1;
		}
		if (!GPIOGet(hdr_QG[QD_IN]))
		{
			/*logMsg("The QD_IN is not 1\n", 0, 0, 0, 0, 0, 0);*/
			G_ERROR.QD_fdback += 1;
		}

	}
	
	Release_QD_GJ: 
					for (rl_cnt = 0; rl_cnt < QG_N; rl_cnt++)
					{
						if (hdr_QG[rl_cnt] > 0)
							DeviceRelease(hdr_QG[rl_cnt]);
					}
					return ret;
}

