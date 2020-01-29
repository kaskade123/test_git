#include<vxWorks.h> 
#include<stdio.h>
#include<sacDev.h>
#include<string.h>
#include<sysLib.h>
#include<logLib.h>
#include<semLib.h>
#include<taskLib.h>
#include"Lib.h"

/*（LED闪烁任务调用）——LED闪烁程序句柄查找*/
INT32 LED_DeviceSearch(const char *color) {
	INT32 hdr_led = 0;
	INDICATOR_DEV_S *pDev = NULL;
	do {
		pDev = DescriptionGetByType(SAC_DEVICE_TYPE_INDICATOR, pDev);
		if(pDev == NULL)
			break;
		if (strcmp(pDev->color, color) == 0) {
			logMsg("The LED name is %s\n", (_Vx_usr_arg_t)pDev->color, 
					0, 0, 0, 0, 0);
			break;
		}
	} while (pDev != NULL);
	if (pDev == NULL) {
		return -ENODEV;
	}
	hdr_led = DeviceRequest(pDev);
	return hdr_led;
}

/*（启动告警任务调用）——启动告警信号句柄查找*/
INT32 QD_GJ_DeviceSearch(const char *device_name) {
	GPIO_DEV_S *pDev_QG = NULL;
	INT32 hdr_QG = 0;
	do {
		pDev_QG = DescriptionGetByType(SAC_DEVICE_TYPE_GPIO, pDev_QG);
		if(pDev_QG == NULL)
			break;
		if (!strcmp(pDev_QG->name, device_name)) {
			logMsg("The GPIO name is %s \n", (_Vx_usr_arg_t)pDev_QG->name, 
					0, 0, 0, 0, 0);
			break;
		}
	} while (pDev_QG != NULL);
	hdr_QG = DeviceRequest(pDev_QG);
	return hdr_QG;
}

/*（485通信任务调用）——485通信句柄查找*/
INT32 UART_DeviceSearch(const char *device_name) {
	UART_DEV_S *pDev_485 = NULL;
	INT32 hdr_485 = 0;
	do {
		pDev_485 = DescriptionGetByType(SAC_DEVICE_TYPE_UART, pDev_485);
		if (pDev_485 == NULL) {
			logMsg("The searching completed!\n", 0, 0, 0, 0, 0, 0);
			break;
		}
		if (!strcmp(pDev_485->name, device_name)) {
			logMsg("UART device name is %s\n", (_Vx_usr_arg_t)pDev_485->name,
					0, 0, 0, 0, 0);
			break;
		}
	} while (pDev_485 != NULL);
	hdr_485 = DeviceRequest(pDev_485);
	return hdr_485;
}

/*（以太网回环任务调用）——hook函数对接收的以太网数据进行打印*/
BOOL hookFuncFor_EthRecvPrint(void *pDev, UINT8 *buffer, UINT32 bufLen) {
	return FALSE;
}
/*（以太网回环任务调用）——以太网回环程序句柄查找 */
INT32 Ethernet_DeviceSearch(const char* device_name) {
	ETHERNET_DEV_S *pDev_eth = NULL;
	int hdr_eth = 0;
	do {
		pDev_eth = DescriptionGetByType(SAC_DEVICE_TYPE_ETHERNET, pDev_eth);
		if (pDev_eth == NULL) {
			logMsg("The searching completed.\n", 0, 0, 0, 0, 0, 0);
			break;
		}
		if (!strcmp(pDev_eth->name, device_name)) {
			logMsg("Ethx device is %s \n", (_Vx_usr_arg_t)pDev_eth->name, 
					0, 0, 0, 0, 0);
			break;
		}
	} while (pDev_eth != NULL);
	if (pDev_eth == NULL)
		return -EFAULT;
	hdr_eth = DeviceRequest(pDev_eth);
	return hdr_eth;
}

/*（定时器中断服务子程序）——定时释放信号量给以太网任务*/
void ISR_Ethernet_semgive(int ETH_ID) {
	semGive((SEM_ID) ETH_ID);
}
/*（定时器设备句柄申请）*/
INT32 Timer_DeviceSearch(const INT32 freq_timer) {
	TIMER_DEV_S *pDev_timer = NULL;
	INT32 hdr_timer;
	do {
		pDev_timer = DescriptionGetByType(SAC_DEVICE_TYPE_TIMER, pDev_timer);
		if (pDev_timer == NULL)
			break;
		hdr_timer = DeviceRequest(pDev_timer);
		if (hdr_timer < 0)
			continue;
		else
		{
			logMsg("The timer request success!\n",0,0,0,0,0,0);
			break;
		}
	} while (pDev_timer != NULL);
	
	if (hdr_timer < 0) {
		logMsg("All timers are occupied!\n", 0, 0, 0, 0, 0, 0);
		return -EFAULT;
	}
	return hdr_timer;
}
/*（定时器配置函数）——定时器申请和参数配置函数*/
INT32 Timer_configuration(const INT32 freq_timer, SEM_ID ETH_ID) {
	INT32 hdr_timer;
	hdr_timer=Timer_DeviceSearch(freq_timer);
	/*定时器参数设置*/
	TimerFreqSet(hdr_timer, freq_timer);
	TimerISRSet(hdr_timer, ISR_Ethernet_semgive, (int) ETH_ID);
	TimerEnable(hdr_timer);
	return hdr_timer;
}

/***********暂时未使用*************/
/*（485通信任务调用）——等待串口至485数据发送完成*/
VOID Delay_Time(INT32 BaudRate, UINT8 bufLen) {
	int delay_ticks = 0;
	delay_ticks = sysClkRateGet() * (bufLen * 11) / BaudRate;
	if (delay_ticks <= 0)
		taskDelay(1);
	else
		taskDelay(delay_ticks);
}
