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

static void LiquidLEDOn()
{
    LED_Pin_Write(1);
}

static void spiWarning()
{
    
}

CY_ISR(ISR_LiquidSensor_handler)
{
    UART_1_PutString("Liquid Sensor Interrupt Happened");
    LiquidLEDOn();    // turn on warning led.
    spiWarning();   // send warning message to client.
}

/* [] END OF FILE */
