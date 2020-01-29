#include<vxWorks.h> 
#include<stdio.h>
#include<sacDev.h>
#include<stdlib.h>
#include<string.h>
#include<semLib.h>
#include<sysLib.h>
#include<taskLib.h>
#include<time.h>
#include<kernelLib.h>
#include<net/if.h>
#include"Ethernet_test.h"
#include"Lib.h"
#include"xd_globals.h"

#define ETHERNET_DEVICE_NAME "mms3"

/******************以太网测试任务——发包任务**********************/
int task_EthConfig(SEM_ID EthSend_sem, SEM_ID EthRecv_sem)
{
	UINT32 flags = 0;
	INT32 Freq_Send = 1000, Freq_Recv = 1000, hdr_Eth = 0, hdr_timer_one = 0,
			hdr_timer_two = 0;

	/*寻找以太网设备*/
	hdr_Eth = Ethernet_DeviceSearch(ETHERNET_DEVICE_NAME);
	if (hdr_Eth < 0)
	{
		logMsg("Eth device handler requested failed!\n", 0, 0, 0, 0, 0, 0);
		return -EFAULT;
	}
	if (EthernetFlagsGet(hdr_Eth, &flags))
	{
		logMsg("Flags get failed!\n", 0, 0, 0, 0, 0, 0);
		if (hdr_Eth > 0)
			DeviceRelease(hdr_Eth);
		return -EFAULT;
	}
	/*以太网混杂模式设置*/
	flags |= IFF_PROMISC;
	if (EthernetFlagsSet(hdr_Eth, flags))
	{
		logMsg("Flags set failed\n", 0, 0, 0, 0, 0, 0);
		if (hdr_Eth > 0)
			DeviceRelease(hdr_Eth);
		return -EFAULT;
	}
	/*以太网工作模式设置为查询模式*/
	EthernetWorkmodeSet(hdr_Eth, SAC_ETHERNET_POLLING);
	/*钩子不使能*/
	if (EthernetHookDisable(hdr_Eth))
	{
		logMsg("Disable hooks failed\n", 0, 0, 0, 0, 0, 0);
		if (hdr_Eth > 0)
			DeviceRelease(hdr_Eth);
		return -EFAULT;
	}
	/*注册接收回调函数*/
	if (EthernetRecvHook(hdr_Eth, hookFuncFor_EthRecvPrint))
	{
		logMsg("Receive hook register failed\n", 0, 0, 0, 0, 0, 0);
		if (hdr_Eth > 0)
			DeviceRelease(hdr_Eth);
		return -EFAULT;
	}
	/*钩子使能*/
	if (EthernetHookEnable(hdr_Eth))
	{
		logMsg("Enable hooks failed\n", 0, 0, 0, 0, 0, 0);
		if (hdr_Eth > 0)
			DeviceRelease(hdr_Eth);
		return -EFAULT;
	}
	/*****收发定时器句柄获取******/
	hdr_timer_one = Timer_configuration(Freq_Send, EthSend_sem);
	hdr_timer_two = Timer_configuration(Freq_Recv, EthRecv_sem);
	/*判断返回的定时器句柄是否有效*/
	if (hdr_timer_one < 0 || hdr_timer_two < 0)
	{
		logMsg("The timer request failed!\n", 0, 0, 0, 0, 0, 0);
		if (hdr_Eth > 0)
			DeviceRelease(hdr_Eth);
		if (hdr_timer_one > 0)
			DeviceRelease(hdr_timer_one);
		if (hdr_timer_two > 0)
			DeviceRelease(hdr_timer_two);
		return -EFAULT;
	}
	return hdr_Eth;
}

/*********************以太网回环测试——发包任务**********************/
int task_EthSend(SEM_ID EthSend_sem, UINT32 hdr_Eth)
{
	UINT8 *package = NULL;
	UINT32 package_len = 1000, pkg_cnt = 0;
	package = (UINT8*) malloc(sizeof(UINT8) * package_len);/*申请待发数据缓冲区*/
	/*待发数据1000*/
	for (pkg_cnt = 0; pkg_cnt < package_len; pkg_cnt++)
		package[pkg_cnt] = pkg_cnt;
	
	/*以太网发报程序测试*/
	while (1)
	{
		semTake(EthSend_sem, WAIT_FOREVER);
		if (EthernetSendPkt(hdr_Eth, package, package_len))
		{
			logMsg("Ethernet Send Failed!\n", 0, 0, 0, 0, 0, 0);
			G_ERROR.EtherSend += 1;
		}
		/*logMsg("This shows the EthSend is running successfully !\n",0,0,0,0,0,0);*/
	}
	if (package != NULL)
		free(package);
	if (hdr_Eth > 0)
		DeviceRelease(hdr_Eth);
}
/***********************以太网回环测试——收包任务************************/
void task_EthRecv(SEM_ID EthRecv_sem, UINT32 hdr_Eth)
{
	static UINT32 package_limit = 100;
	int Eth_ret = 0;
	
	while (1)
	{	
		/*等待中断释放信号量*/
		semTake(EthRecv_sem, WAIT_FOREVER);
		package_limit = 100;
		Eth_ret = EthernetRecvPoll(hdr_Eth, &package_limit);
		if (Eth_ret != 0 && Eth_ret != -EAGAIN)
		{
			logMsg("Ethernet Receive Failed ! %d\n", Eth_ret, 0, 0, 0, 0, 0);
			G_ERROR.EtherRecv += 1;
		}
		/*logMsg("This shows the EthRecv is running successfully !\n",0,0,0,0,0,0);*/
	}
	}

