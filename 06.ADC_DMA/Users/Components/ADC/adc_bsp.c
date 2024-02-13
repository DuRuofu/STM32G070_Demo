#include "adc_bsp.h"

#include "uart_3.h"
uint32_t ADC_Value[100]; //转换数据缓存数组
uint8_t i;               
uint32_t ad1,ad2;        // PA0(转换通道 0),PA1(转换通道 1) 的电压值


void ADC_init(void)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&ADC_Value, 2);
    //面以 DMA 方式开启 ADC 装换。HAL_ADC_Start_DMA() 函数第二个参数为数据存储起始地址，第三个参数为 DMA 传输数据的长度。
}

// ADC测量
void ADC_Meas(void)
{
    for(i = 0,ad1 =0,ad2=0; i < 100;){
    ad1 += ADC_Value[i++];
    ad2 += ADC_Value[i++];
    }
    ad1 /= 50;
    ad2 /= 50;

    Usart3DmaPrintf("AD1_value=%1.3f,AD2_value=%1.3f\r\n", ad1*3.3f/4096,ad2*3.3f/4096);
}
