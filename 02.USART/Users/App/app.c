#include "main.h"
#include "app.h"

// 引入自定义模块
#include "usart_it_config.h"
#include "usart_3.h"

#define TAG "APP"

/**
 * @description: 系统应用初始化
 * @return {*}
 */
void App_Init(void)
{
	// 串口中断初始化
    USART_IT_Init();
}


/**
 * @description: 系统应用循环任务
 * @return {*}
 */
void App_Task(void)
{
	printf("你好!!!");
	HAL_Delay(100);
}
