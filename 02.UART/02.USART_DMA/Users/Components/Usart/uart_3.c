/*
 * @Author: DuRuofu duruofu@qq.com
 * @Date: 2023-07-13 17-13-53
 * @LastEditors: DuRuofu
 * @LastEditTime: 2024-02-13 11-42-29
 * @FilePath: \MDK-ARMd:\duruofu\Project\STM32G070_Demo\04.USART_DMA\Users\Components\Usart\uart_3.c
 * @Description: 串口3逻辑
 * Copyright (c) 2023 by duruofu@foxmail.com All Rights Reserved.
 */

#include "uart_3.h"

#define RXBUFFERSIZE_3 256 // 最大接收字节数

// 定义串口句柄,使用串口1
#define UART_HANDLE huart3

// 定义数据缓冲区
uint8_t RxBuffer_3[RXBUFFERSIZE_3];
uint8_t Uart_RxBuffer_3;   // 接收中断缓冲
uint8_t Uart_Rx_Cnt_3 = 0; // 接收缓冲计数

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
  HAL_UART_Receive_DMA(&UART_HANDLE, &Uart_RxBuffer_3, 1);
}

// 串口3接收完成回调函数
void UART3_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */

  if (Uart_Rx_Cnt_3 >= 255) // 溢出判断
  {
    Uart_Rx_Cnt_3 = 0;
    memset(RxBuffer_3, 0x00, sizeof(RxBuffer_3));
    Usart3DmaPrintf("数据溢出");
  }
  else
  {
    RxBuffer_3[Uart_Rx_Cnt_3++] = Uart_RxBuffer_3;
    // 单字符判断

    if ((RxBuffer_3[Uart_Rx_Cnt_3 - 1] == 0x0A) && (RxBuffer_3[Uart_Rx_Cnt_3 - 2] == 0x0D)) // 判断结束位
    {
        char str[256];
        sprintf(str, "%s", RxBuffer_3);
        Usart3DmaPrintf(str); //将收到的信息发送出去

        // 复位
        Uart_Rx_Cnt_3 = 0;
        memset(RxBuffer_3, 0x00, sizeof(RxBuffer_3)); // 清空数组
    }
  }

  HAL_UART_Receive_DMA(&UART_HANDLE, (uint8_t *)&Uart_RxBuffer_3, 1); // 因为接收中断使用了一次即关闭，所以在最后加入这行代码即可实现无限使用
}

// 串口3错误回调函数(主要用来清除溢出中断)
//  void UART3_ErrorCallback(UART_HandleTypeDef *huart)
//  {
//    if(HAL_UART_ERROR_ORE)
//    {
//       uint32_t temp = huart->Instance->SR;
//       temp = huart->Instance->DR;
//    }
//  }


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

