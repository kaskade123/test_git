#include<vxWorks.h> 
#include<stdio.h>
#include<sacDev.h>
#include<stdlib.h>
#include<string.h>
#include<sysLib.h>
#include<taskLib.h>
#include<time.h>
#include"485_test.h"
#include"Lib.h"
#include"xd_globals.h"

#define MAX_RETRY 60 /*UARTRecv最大重发taskDelay(1)次数*/
#define PACKAGE_BIT 8
#define ERRORTABLE_SIZE 256
/*************************485通信任务*****************************/
UINT8 task_485(void)
{
	UINT8 *pBuf_Send = NULL, *pBuf_Recv = NULL, bufLen = 0, RESULT = 0, 
			cnt = 0, data_loca = 0, retry = 0;
	INT32 hdr485_1 = 0, hdr485_2 = 0, temp = 0, baudrate = 9600, ret = 0;
	UINT8 ErrorTable[ERRORTABLE_SIZE] =
	{ 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
			2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3,
			4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5,
			5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4,
			5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4,
			3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3,
			4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5,
			5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6,
			4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7,
			8 };
	pBuf_Send = (UINT8*) malloc(sizeof(UINT8) * 256);
	pBuf_Recv = (UINT8*) malloc(sizeof(UINT8) * 256);
	srand((unsigned) time(NULL));

	/* 查找两个485句柄*/
	hdr485_1 = UART_DeviceSearch("RS0");
	hdr485_2 = UART_DeviceSearch("RS1");
	if (hdr485_1 < 0)
		goto Release;
	if (hdr485_2 < 0)
		goto Release;
	logMsg("The 485 handler request success!\n", 0, 0, 0, 0, 0, 0);

	/*配置两个485的UART参数*/
	if (UARTConfig(hdr485_1, baudrate, UART_PARITY_NONE))
	{
		logMsg("UART Configuration Failed\n", 0, 0, 0, 0, 0, 0);
		ret = -EFAULT;
		goto Release;
	}
	if (UARTConfig(hdr485_2, baudrate, UART_PARITY_NONE))
	{
		logMsg("UART Configuration Failed\n", 0, 0, 0, 0, 0, 0);
		ret = -EFAULT;
		goto Release;
	}
	/* 485数据收发及数据校验 */
	while (1)
	{
		/*485随机数据长度*/
		bufLen = rand() % 255+1;/*随机数范围限定在1-256*/
		/*485随机数据*/
		for (cnt = 0; cnt < bufLen; cnt++)
		{
			pBuf_Send[cnt] = rand();
		}
		/*485发是否成功检查*/
		if (UARTSend(hdr485_1, pBuf_Send, bufLen) < 0)
		{
			logMsg("UARTSend Failed\n", 0, 0, 0, 0, 0, 0);
			G_ERROR.Send485 += 1;
			continue;
		}
		/*Delay_Time(baudrate, bufLen);*/
		retry = 0;/*485接收完成所等待taskDelay(1)次数*/
		while (UARTRecv(hdr485_2, pBuf_Recv, bufLen) < 0)
		{
			retry++;
			taskDelay(1);
			if (retry >= MAX_RETRY)/*最大retry接收判断次数*/
			{
				logMsg("UARTRecv had been retrying %d times! \n", MAX_RETRY, 0, 0, 0, 0, 0);
				continue;
			}
		}
		G_ERROR.Recv485_tic=retry;
		/*logMsg("This shows the 485 is running successfully!\n",0,0,0,0,0,0);*/
		/*统计485通信过程中的数据出错情况*/
		for (data_loca = 0; data_loca < bufLen; data_loca++)
		{
			if ((RESULT = (pBuf_Send[data_loca] ^ pBuf_Recv[data_loca])) != 0)
			{
				G_ERROR.Recv485_pkg+=1;
				/*查表得到异或结果中1个数*/
				G_ERROR.Bit485_count = G_ERROR.Bit485_count + ErrorTable[RESULT]; 
				logMsg("%d bits of the %dth data received are wrong!\n",
							ErrorTable[RESULT], data_loca, 0, 0, 0, 0);
			}
		}
		temp = temp + bufLen;
		G_ERROR.Bit485_sum = temp * PACKAGE_BIT;/*485接收到总数据bit位和*/
	}
	Release: 
				if (hdr485_1 >= 0)
					DeviceRelease(hdr485_1);
				if (hdr485_2 >= 0)
					DeviceRelease(hdr485_2);
				if (pBuf_Send != NULL)
					free(pBuf_Send);
				if (pBuf_Recv != NULL)
					free(pBuf_Recv);
				return ret;
}

