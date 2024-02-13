/*
 * @Author: DuRuofu duruofu@qq.com
 * @Date: 2023-07-13 17-13-53
 * @LastEditors: DuRuofu
 * @LastEditTime: 2024-02-13 12-07-26
 * @FilePath: \STM32G070_Demo\04.USART_IDLE\Users\Components\Usart\uart_3.c
 * @Description: 串口3逻辑
 * Copyright (c) 2023 by duruofu@foxmail.com All Rights Reserved.
 */

#include "uart_3.h"

extern DMA_HandleTypeDef hdma_usart3_rx;

// 定义串口句柄,使用串口3
#define UART_HANDLE huart3

// 接收缓冲区
#define RXBUFFERSIZE_3 256 // 最大接收字节数
uint8_t RxBuffer_3[RXBUFFERSIZE_3];

// 发送缓冲区
#define UART_TX_BUF_SIZE 256
uint8_t UartTxBuf[UART_TX_BUF_SIZE];


void UART3_Init(void)
{
  /*串口硬件配置代码(使用cudeMX则不需要此部分)
  Init the GPIO of USART1
  */
  // 使能 USART1 的接收中断
  __HAL_UART_ENABLE_IT(&UART_HANDLE, UART_IT_RXNE);
  // 开启 USART1 的连续接收中断，并指定接收缓冲区的地址和长度
  HAL_UARTEx_ReceiveToIdle_DMA(&UART_HANDLE, RxBuffer_3, RXBUFFERSIZE_3);
  __HAL_DMA_DISABLE_IT(&hdma_usart3_rx, DMA_IT_HT);
}

// 串口3空闲中断回调函数
void UARTx3_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  UNUSED(Size);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */
  
  // 将数据发送回去
  HAL_UART_Transmit_DMA(&UART_HANDLE, RxBuffer_3,Size );


  // 重新开启连续接收中断
  HAL_UARTEx_ReceiveToIdle_DMA(&UART_HANDLE, RxBuffer_3, RXBUFFERSIZE_3);
  //
  __HAL_DMA_DISABLE_IT(&hdma_usart3_rx, DMA_IT_HT);

    
}

/**
 * @description: 串口3发送函数
 * @param {char} *format
 * @return {*}
 */
void Usart3DmaPrintf(const char *format,...)
{
	uint16_t len;
	va_list args;	
	va_start(args,format);
	len = vsnprintf((char*)UartTxBuf,sizeof(UartTxBuf),(char*)format,args);
	va_end(args);
	HAL_UART_Transmit_DMA(&huart3, UartTxBuf, len);
}

