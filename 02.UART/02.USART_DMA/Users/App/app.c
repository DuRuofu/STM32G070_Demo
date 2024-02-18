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
	Usart3DmaPrintf("test!!!\n");
	HAL_Delay(2000);
}
