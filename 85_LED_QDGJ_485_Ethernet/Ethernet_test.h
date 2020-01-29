#ifndef _ETHERNET_TEST_H_
#define _ETHERNET_TEST_H_

extern int task_EthConfig(SEM_ID EthSend_sem, SEM_ID EthRecv_sem);

extern int task_EthSend(SEM_ID EthSend_sem, UINT32 hdr_Eth);

extern void task_EthRecv(SEM_ID EthRecv_sem, UINT32 hdr_Eth);

#endif
