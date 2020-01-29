#include<vxWorks.h> 
#include<stdio.h>
#include<sacDev.h>
#include<stdlib.h>
#include<string.h>
#include<sysLib.h>
#include<taskLib.h>
#include<time.h>
#include"LED_test.h"
#include"Lib.h"
#include"xd_globals.h" /*全局结构体，用来存放各测试程序错误统计信息*/

#define LED_NAME 3 /*LED设备个数*/
#define LED1 0
#define LED2 1
#define LED3 2

/*************************LED闪烁任务测试程序**********************/
INT32 task_LED(void)
{
	INT32 hdr_LED[LED_NAME] = { 0 }, led_cnt = 0;
	const char * PLed[LED_NAME] = { "LED1", "LED2", "LED3" };
	
	/*三个LED灯设备句柄申请*/
	for (led_cnt = 0; led_cnt < LED_NAME; led_cnt++)
	{
		hdr_LED[led_cnt] = LED_DeviceSearch(PLed[led_cnt]);
		if (hdr_LED[led_cnt] < 0)
		{
			logMsg("The %s handler request failed!\n",
					(_Vx_usr_arg_t) PLed[led_cnt], 0, 0, 0, 0, 0);
			goto release_LED;
		}
		else
			logMsg("The LED handler request success!\n", 0, 0, 0, 0, 0, 0);
	}
	/*每隔0.5秒点亮和熄灭LED灯*/
	while (1)
	{
		/*同时点亮三个LED灯*/
		if (LightOn(hdr_LED[LED1]) && LightOn(hdr_LED[LED2]) 
				&& LightOn(hdr_LED[LED3]))
		{
			logMsg("The LED LightOn configuration failed !\n", 
					0, 0, 0, 0, 0, 0);
			G_ERROR.LEDOn += 1;
			continue;
		}
		taskDelay(sysClkRateGet() / 2);
		/*同时熄灭三个LED灯*/
		if (LightOff(hdr_LED[LED1]) && LightOff(hdr_LED[LED2]) 
			  && LightOff(hdr_LED[LED3]))
		{
			logMsg("The LED LightOff configuration failed !\n", 0, 0, 0, 0, 0, 0);
			G_ERROR.LEDOff += 1;
			continue;
		}
		taskDelay(sysClkRateGet() / 2);
		/*logMsg("This shows the LED is running successfully!\n", 0, 0, 0, 0, 0, 0);*/
	}
	
	release_LED:
				if (hdr_LED[LED1] >= 0)
					DeviceRelease(hdr_LED[LED1]);
				if (hdr_LED[LED2] >= 0)
					DeviceRelease(hdr_LED[LED2]);
				if (hdr_LED[LED3] >= 0)
					DeviceRelease(hdr_LED[LED3]);
				return 0;
}

