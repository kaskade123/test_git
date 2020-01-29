#ifndef  _XD_GLOBALS_H_
#define  _XD_GLOBALS_H_


typedef struct globals_ErrorCnt
		{
			UINT32 LEDOn; 		/*统计LED灯点亮出错次数*/
			UINT32 LEDOff;		/*统计LED灯熄灭出错次数*/
			UINT32 GJ_fdback;	/*统计GJ反馈出错次数*/
			UINT32 QD_fdback;	/*统计QD反馈出错次数*/
			UINT32 Send485; 		/*统计485发错误执行次数*/
			UINT32 Recv485_tic; /*统计485收延时的ticks数*/
			UINT32 Recv485_pkg;	/*统计485收到的错包次数*/
			UINT32 Bit485_count;/*统计485收到的所有错误bit数*/
			UINT32 Bit485_sum;	/*统计485收到的所有bit数总和*/
			UINT32 EtherSend;	/*统计以太网发错误执行次数*/
			UINT32 EtherRecv;	/*统计以太网收错误执行次数*/
		}ERROR_CNT;
		
/*typedef struct globals_Ether_Sem_hdr
		{
			SEM_ID EthRecv_sem; 
			SEM_ID EthSend_sem;
			INT32    hdr_Eth;
		}SEM_HDR_FOR_ETHERNET;*/
		
		extern ERROR_CNT G_ERROR;

#endif
