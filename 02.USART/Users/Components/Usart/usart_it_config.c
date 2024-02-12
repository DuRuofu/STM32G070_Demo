/*
 * @Author: DuRuofu duruofu@qq.com
 * @Date: 2024-02-12 16-22-52
 * @LastEditors: DuRuofu
 * @LastEditTime: 2024-02-12 17-09-01
 * @FilePath: \MDK-ARMd:\duruofu\Project\STM32G070_Demo\02.USART\Users\Components\Usart\usart_it_config.c
 * @Description: 串口中断配置(HAL)
 * Copyright (c) 2024 by duruofu@foxmail.com All Rights Reserved. 
 */

#include "usart_it_config.h"

/**
 * @description: 串口接收中断初始化(总)
 * @return {*}Debug_Init
 */
void USART_IT_Init(void)
{
    //串口1接收中断初始化
    //USART1_Init();
    //串口2接收中断初始化
    //USART2_Init();
    //串口3接收中断初始化
    USART3_Init();
}

// 串口接收完成回调函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1)
    {
        //USART1_RxCpltCallback(huart);
    }
    else if(huart->Instance == USART2)
    {
        //USART2_RxCpltCallback();
    }
    else if(huart->Instance == USART3)
    {
        USART3_RxCpltCallback(huart);
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

