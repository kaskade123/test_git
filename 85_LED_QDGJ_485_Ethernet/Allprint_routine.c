#include<vxWorks.h> 
#include<stdio.h>
#include<taskLib.h>
#include<sysLib.h>
#include"print_error_lib.h"
#include"Allprt_test.h"

/*负责统一打印所有测试任务通过队列传来的异常运行次数*/
void Allprt_ErrorCnt(void)
{
	while (1)
	{
		LED_ERROR_print();

		QDGJ_ERROR_print();

		RS485_ERROR_print();

		ETHERNET_ERROR_print();
		
		taskDelay(sysClkRateGet() * 2);
	}
}
