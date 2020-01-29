#ifndef _G_MSG_H_
#define _G_MSG_H_

/*定义队列接收和发送的结构体类型
 * id用来标识该测试设备类型（LED，485，等）
 * 其中error_one等这些变量供各测试程序存放错误数据统计用
 * 所有测试程序和任务共用这一个结构体类型*/

typedef struct msg_error
{
	int id;
	int error_one;
	int error_two;
	int error_three;
	int error_count;/*485通信过程中的数据出错个数*/
	int error_sum;/*485接收到的所有数据*/
}MSG;

#endif




