#include "main.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#ifndef __UART_3_H
#define __UART_3_H

// 串口3接收中断初始化
void UART3_Init(void);
// 串口3接收完成回调函数
void UART3_RxCpltCallback(UART_HandleTypeDef *huart);
// 串口3空闲中断回调函数
void UARTx3_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);
// 串口3错误回调
void UART3_ErrorCallback(UART_HandleTypeDef *huart);
void Usart3DmaPrintf(const char *format,...);
#endif // !__UART_3_H
