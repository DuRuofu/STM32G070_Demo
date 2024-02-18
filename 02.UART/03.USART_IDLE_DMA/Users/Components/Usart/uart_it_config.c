/*
 * @Author: DuRuofu duruofu@qq.com
 * @Date: 2024-02-12 16-22-52
 * @LastEditors: DuRuofu
 * @LastEditTime: 2024-02-13 12-07-12
 * @FilePath: \STM32G070_Demo\04.USART_IDLE\Users\Components\Usart\uart_it_config.c
 * @Description: 串口中断配置(HAL)
 * Copyright (c) 2024 by duruofu@foxmail.com All Rights Reserved. 
 */

#include "uart_it_config.h"

/**
 * @description: 串口接收中断初始化(总)
 * @return {*}Debug_Init
 */
void UART_IT_Init(void)
{
    //串口1接收中断初始化
    //USART1_Init();
    //串口2接收中断初始化
    //USART2_Init();
    //串口3接收中断初始化
    UART3_Init();
}

// 串口接收完成回调函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1)
    {
        //UART1_RxCpltCallback(huart);
    }
    else if(huart->Instance == USART2)
    {
        //UART2_RxCpltCallback(huart);
    }
    else if(huart->Instance == USART3)
    {
        //UART3_RxCpltCallback(huart);
    }
}


// 串口空闲中断回调函数
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if(huart->Instance == USART1)
    {
        //UARTx1_RxEventCallback(huart);
    }
    else if(huart->Instance == USART2)
    {
        //UARTx2_RxEventCallback();
    }
    else if(huart->Instance == USART3)
    {
        UARTx3_RxEventCallback(huart,Size);
    }
}

//错误回调  
 void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)   
{       
    if(huart->Instance == USART1)
    {
        //USART1_ErrorCallback(huart);
    }
    else if(huart->Instance == USART2)
    {
        //USART2_ErrorCallback(huart);
    }
    else if(huart->Instance == USART3)
    {
        //USART3_ErrorCallback(huart);
    } 
}

