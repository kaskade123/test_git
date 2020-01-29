#include<vxWorks.h> 
#include<stdio.h>
#include<sacDev.h>
#include<stdlib.h>
#include<string.h>
#include<semLib.h>
#include<sysLib.h>
#include<taskLib.h>
#include<logLib.h>
#include"Ethernet_test.h"

#define ETH_SEND 200
#define ETH_RECV 50
#define STACK_SIZE 20000

/*****************启动多任务主程序main入口*****************/
UINT32 task_Ethernet()
{
	UINT32 hdr_Ethernet;
	SEM_ID EthSend_sem, EthRecv_sem;/*定义信号量*/
	/*以太网收发所用两个信号量创建*/
	EthSend_sem = semBCreate(SEM_Q_PRIORITY, SEM_EMPTY);
	EthRecv_sem = semBCreate(SEM_Q_PRIORITY, SEM_EMPTY);
	
	/*以太网参数配置和句柄申请*/
	hdr_Ethernet = task_EthConfig(EthSend_sem, EthRecv_sem);
	if (hdr_Ethernet < 0)
	{
		logMsg("The Ethernet and Timer configuration failed!\n", 
				0, 0, 0, 0, 0, 0);
		return -EFAULT;
	}
	else
		logMsg("The Ethernet handler request success!\n", 0, 0, 
				0, 0, 0, 0);
	
/*以下为创建的测试任务，传入函数参数有：信号量变量，以太网句柄*/
	/*创建以太网收发包任务*/
	taskSpawn("EthSend", ETH_SEND, 0, STACK_SIZE, (FUNCPTR) task_EthSend,
					(_Vx_usr_arg_t) EthSend_sem, (_Vx_usr_arg_t) hdr_Ethernet,
					0, 0, 0, 0, 0, 0, 0, 0);
	taskSpawn("EthRecv", ETH_RECV, 0, STACK_SIZE, (FUNCPTR) task_EthRecv,
					(_Vx_usr_arg_t) EthRecv_sem, (_Vx_usr_arg_t) hdr_Ethernet,
					0, 0, 0, 0, 0, 0, 0, 0);
	return 0;
}
