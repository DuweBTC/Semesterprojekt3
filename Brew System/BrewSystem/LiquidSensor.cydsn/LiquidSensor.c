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

bool checkLiquid()
{
    bool checkLiquid = false;

    int liquid = LiquidSensorInput_Read();
    
    if (liquid == 1)
    {
        UART_1_PutString("Full\n");
        checkLiquid = true;
    }
    if (liquid == 0)
    {
        UART_1_PutString("Empty\n");
        checkLiquid = false ;
    }
    
    return checkLiquid;
}


static void LiquidLEDOn()
{
    //LED_Pin_Write(1);
}

static void spiWarning()
{
    
}

/* [] END OF FILE */
