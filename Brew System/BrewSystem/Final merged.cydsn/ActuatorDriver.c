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

#include "ActuatorDriver.h"
#include "WeightSensor.h"
#include "LiquidSensor.h"
#include <stdbool.h>

CY_ISR_PROTO(timer_inter_handler);

static void openValveNr(int valveNumber);
static void closeValves();

int CONTAINER = 1;
int AMOUNT;

CY_ISR(timer_inter_handler)
{
    closeValves();
    Timer_1_Stop();
}

void pour()
{
    float time;
    float timerVariabel = 24;
    float x = 156; // skal ændres når ventiler er blevet testet.    
    
    if (checkForGlass() == true && checkAllLiquid() == true)
    {
    
        time = AMOUNT * x * timerVariabel; // calculate open time.
        
        Timer_1_Start(); // Starts timer
            
        openValveNr(CONTAINER); // Open specific container
            
        Timer_1_WriteCounter(time); // makes sure timer counter is 0
        Timer_1_WritePeriod(time); // Writes periode to timer
    }
    
}

void setIngredient(int _container, int _amount)
{
    CONTAINER = _container;
    AMOUNT = _amount;
}

static void openValveNr(int valveNumber)
{
    switch(valveNumber)
    {
        case 0: // valve 0
        {
            v0_Write(0);
            break;
        }
        
        case 1 : // Valve 1
        {
            v1_Write(0);
            break;
        }
        
        case 2: // valve 2
        {
            v2_Write(0);
            break;
        }
        
        case 3: // valve 3
        {
            v3_Write(0);
            break;
        }
    }
}

void closeValves()
{
    v0_Write(1);
    v1_Write(1);
    v2_Write(1);
    v3_Write(1);
}

/* [] END OF FILE */
