

#include "usart_it_config.h"

/**
 * @description: 串口接收中断初始化(总)
 * @return {*}Debug_Init
 */
void USART_IT_Config(void)
{
    //串口1接收中断初始化
    //USART1_Init();
    //串口2接收中断初始化
    //USART2_Init();
    //串口3接收中断初始化
    USART3_Init();
}

//串口接收完成回调函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1)
    {
        //UART1_RxCpltCallback(huart);
    }
    else if(huart->Instance == USART2)
    {
        //UART2_RxCpltCallback();
    }
    else if(huart->Instance == USART3)
    {
        UART3_RxCpltCallback(huart);
    }
    }


//错误回调  
 void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)   
{       
    if(huart->Instance == USART1)
    {
        UART1_ErrorCallback(huart);
    }
    else if(huart->Instance == USART2)
    {
        UART2_ErrorCallback(huart);
    }
    else if(huart->Instance == USART3)
    {
        UART3_ErrorCallback(huart);
    } 
}

