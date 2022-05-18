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

/* Prototyper */
static void LiquidLEDOn();
static void LiquidLEDoff();
static void spiWarning();

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
        LiquidLEDOn();
        checkLiquid = false ;
    }
    
    while ( LiquidSensorInput_Read() != 1 )
    {
        /* Do nothing just wait */
    }
    
    LiquidLEDoff();
    
    return checkLiquid;
}


static void LiquidLEDOn()
{
    LiquidLED_Write(1); // Turn on warning LED
}

static void LiquidLEDoff()
{
    LiquidLED_Write(0); // Turn off warning LED
}

static void spiWarning()
{
    
}

/* [] END OF FILE */
