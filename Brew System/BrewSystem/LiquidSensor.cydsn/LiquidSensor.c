/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "LiquidSensor.h"

void LiquidLED()
{
    
}
void spiWarning()
{
    
}

CY_ISR(ISR_LiquidSensor_handler)
{
    UART_1_PutString("Liquid Sensor Interrupt Happened");
    /* Kode til LED her */
    
    /* SPI kode til at skrive til client her */ 
}

/* [] END OF FILE */
