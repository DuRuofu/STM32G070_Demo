#include "main.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>

#ifndef __USART_3_H
#define __USART_3_H

// 串口3接收中断初始化
void  USART3_Init(void);
// 串口3接收完成回调函数
void USART3_RxCpltCallback(UART_HandleTypeDef *huart);
// 串口3错误回调
void USART3_ErrorCallback(UART_HandleTypeDef *huart);

#endif // !__USART_3_H
