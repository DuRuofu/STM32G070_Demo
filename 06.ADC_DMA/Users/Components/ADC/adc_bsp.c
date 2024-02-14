#include "adc_bsp.h"

#include "uart_3.h"

uint32_t ADC_Value[2]={0,0}; //转换数据缓存数组  
float ad1,ad2;        // PA0(转换通道 0),PA1(转换通道 1) 的电压值

extern DMA_HandleTypeDef hdma_adc1;

void ADC_init(void)
{
    // ADC校准
    HAL_ADCEx_Calibration_Start(&hadc1);
    //以 DMA 方式开启 ADC 装换。HAL_ADC_Start_DMA() 函数第二个参数为数据存储起始地址，第三个参数为 DMA 传输数据的长度。
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&ADC_Value, 2);
}

// ADC测量
void ADC_Meas(void)
{
    
    ad1 = (float)ADC_Value[0] * (3.3/4096);
    ad2 = (float)ADC_Value[1] * (3.3/4096);

    Usart3DmaPrintf("AD1_value=%1.3f,AD2_value=%1.3f\r\n", ad1*1000,ad2*1000);
    HAL_Delay(10);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&ADC_Value, 2);
}
