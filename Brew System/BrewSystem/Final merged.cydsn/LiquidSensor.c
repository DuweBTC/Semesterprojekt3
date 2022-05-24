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

bool checkAllLiquid()
{
    bool liquidState = true;
    
    if (LiquidSensorInput_1_Read() == 0)
    {
        return false;
    }
    
    /*
    if (LiquidSensorInput_2_Read() == 0)
    {
        return false;
    }
    if (LiquidSensorInput_3_Read() == 0)
    {
        return false;
    }
    if (LiquidSensorInput_4_Read() == 0)
    {
        return false;
    }
    */
    
    return liquidState;
     
}

bool checkLiquid_1()
{
    int liquid = LiquidSensorInput_1_Read();
    
    if (liquid == 1)
    {
        return true;
    } else {
        return false;
    }
}
bool checkLiquid_2()
{
    int liquid = LiquidSensorInput_2_Read();
    
    if (liquid == 1)
    {
        return true;
    } else {
        return false;
    }
}
bool checkLiquid_3()
{
    int liquid = LiquidSensorInput_3_Read();
    
    if (liquid == 1)
    {
        return true;
    } else {
        return false;
    }
}
bool checkLiquid_4()
{
    int liquid = LiquidSensorInput_4_Read();
    
    if (liquid == 1)
    {
        return true;
    } else {
        return false;
    }
}

/*
static void LiquidLEDOn()
{
    LiquidLED_Write(1); // Turn on warning LED
}

static void LiquidLEDoff()
{
    LiquidLED_Write(0); // Turn off warning LED
}
*/
/* [] END OF FILE */
