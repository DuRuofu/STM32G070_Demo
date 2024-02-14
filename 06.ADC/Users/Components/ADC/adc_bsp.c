#include "adc_bsp.h"

void ADC_init(void)
{
    // ADC校准
    HAL_ADCEx_Calibration_Start(&hadc1);
}

// ADC 0号通道测量
uint32_t ADC_IN0_Meas(void)
{
    HAL_ADC_Start(&hadc1);//启动ADC装换
    HAL_ADC_PollForConversion(&hadc1, 50);//等待转换完成，第二个参数表示超时时间，单位ms.
    if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
        {
    return HAL_ADC_GetValue(&hadc1);//读取ADC转换数据，数据为12位
}
}
