#ifndef _LIB_H_
#define _LIB_H_

extern BOOL hookFuncFor_EthRecvPrint(void *pDev, UINT8 *buffer, UINT32 bufLen);

extern INT32 Timer_DeviceSearch(const INT32 freq_timer);

extern INT32 Timer_configuration(INT32 freq_timer, SEM_ID ETH_ID);

extern INT32 LED_DeviceSearch(const char *color);

extern INT32 QD_GJ_DeviceSearch(const char *device_name);

extern INT32 UART_DeviceSearch(const char *device_name);

extern INT32 Ethernet_DeviceSearch(const char* device_name);

extern void ISR_Ethernet_semgive(int ETH_ID);


extern VOID Delay_Time(INT32 BaudRate, UINT8 bufLen);


#endif
