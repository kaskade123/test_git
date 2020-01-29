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
#include<logLib.h>
#include"LED_test.h"
#include"QDGJ_test.h"
#include"485_test.h"
#include"Ethernet_test.h"
#include"Allprt_test.h"/*调用各测试程序错误统计的打印接口*/
#include "taskSpawn_Eth.h"
#include"Lib.h"/*各测试设备的句柄查找等接口函数*/

#define LED_PRI   203
#define QDGJ_PRI  202
#define RS485_PRI 201
#define ETH_PRI   200
#define PRINT_PRI 204
#define STACK_SIZE 20000
/*****************启动多任务主程序main入口*****************/
int task_start()
{
	/*以下为创建的各测试任务，传入函数参数有：信号量变量，以太网句柄*/

	/*创建LED闪烁任务*/
	taskSpawn("LEDBlink", LED_PRI, 0, STACK_SIZE, (FUNCPTR) task_LED, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	/*创建启动告警任务*/
	taskSpawn("_QDGJ_", QDGJ_PRI, 0, STACK_SIZE, (FUNCPTR) task_QD_GJ, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	/*创建485通信任务*/
	taskSpawn("task_485", RS485_PRI, 0, STACK_SIZE, (FUNCPTR) task_485,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	/*创建以太网收发包任务*/
	taskSpawn("task_Eth", ETH_PRI, 0, STACK_SIZE, (FUNCPTR) task_Ethernet, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	/*调用各测试程序的错误打印接口，作统一打印*/
	taskSpawn("RESULT:", PRINT_PRI, 0, 20000, (FUNCPTR) Allprt_ErrorCnt,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	
	return 0;
}
