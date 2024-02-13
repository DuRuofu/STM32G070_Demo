#include "main.h"
#include "app.h"

#define TAG "APP"

/**
 * @description: 系统应用初始化
 * @return {*}
 */
void App_Init(void)
{
	// 串口中断初始化
    UART_IT_Init();
}


/**
 * @description: 系统应用循环任务
 * @return {*}
 */
void App_Task(void)
{
	uint32_t AD_Value = ADC_IN0_Meas();
	Usart3DmaPrintf("v=%.1f\r\n",AD_Value*3300.0/4096);//打印日志
}
