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

bool checkLiquid_1()
{
    int liquid = LiquidSensorInput_1_Read();
    
    if (liquid == 1)
    {
        LiquidLEDoff();
        return true;
    } else {
        LiquidLEDOn();
        return false;
    }
}

static void LiquidLEDOn()
{
    LiquidLED_Write(1); // Turn on warning LED
}

static void LiquidLEDoff()
{
    LiquidLED_Write(0); // Turn off warning LED
}

/* [] END OF FILE */
