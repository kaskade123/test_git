#include<vxWorks.h> 
#include<stdio.h>
#include"xd_globals.h"
#include<logLib.h>
#include"print_error_lib.h"

/*各测试函数打印错误输出接口*/
void LED_ERROR_print()
{
	logMsg("[LED] is setting ON. /Error times: [ %d ]\n",
			G_ERROR.LEDOn, 0, 0, 0, 0, 0);
	logMsg("[LED] is setting OFF. /Error times: [ %d ]\n",
			G_ERROR.LEDOff, 0, 0, 0, 0, 0);
}

void QDGJ_ERROR_print()
{
	logMsg("[GJ] is requesting feedback. /Error times: [ %d ]\n",
			G_ERROR.GJ_fdback, 0, 0, 0, 0, 0);
	
	logMsg("[QD] is requesting feedback. /Error times: [ %d ]\n",
			G_ERROR.QD_fdback, 0, 0, 0, 0, 0);
}

void RS485_ERROR_print()
{
	logMsg("[485] is sending package. /Error times: [ %d ]\n",
			G_ERROR.Send485, 0, 0, 0, 0, 0);
	logMsg("[485] is receiving package. /Retried ticks: [ %d ]\n",
			G_ERROR.Recv485_tic, 0, 0, 0, 0, 0);
	
	logMsg("[485] has received [ %d ] pkgs. /Wrong pkgs: [ %d ]\n",
			G_ERROR.Bit485_sum / 8, G_ERROR.Recv485_pkg, 0, 0, 0, 0);
	logMsg("[%d]b received, [ %d ] error. /Error rate: [ %.2f ]\n",
			G_ERROR.Bit485_sum, G_ERROR.Bit485_count,
			(float) G_ERROR.Bit485_count / G_ERROR.Bit485_sum, 0, 0, 0);
}

void ETHERNET_ERROR_print()
{
	logMsg("[Ethernet] is sending package. /Error times: [ %d ]\n",
			G_ERROR.EtherSend, 0, 0, 0, 0, 0);

	logMsg("[Ethernet] is receiving package. /Error times: [ %d ]\n\n\n",
			G_ERROR.EtherRecv, 0, 0, 0, 0, 0);
}

