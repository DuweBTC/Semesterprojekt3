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
#include <stdbool.h>

CY_ISR_PROTO(timer_inter_handler);

static void openValveNr(int valveNumber);
static void closeValves();

int CONTAINER = 1;
int AMOUNT = 2;

CY_ISR(timer_inter_handler)
{
    DONE = true;
    closeValves();
    Timer_1_Stop();
}

int pour()
{
    float time;
    float timerVariabel = 24;
    float x = 156; // skal ændres når ventiler er blevet testet.
    
    time = AMOUNT * x * timerVariabel;
    
    Timer_1_Start();
    
    openValveNr(CONTAINER);
        
    Timer_1_WriteCounter(time); // makes sure timer counter is 0
    Timer_1_WritePeriod(time); // Writes periode to timer

    return 0; // Success
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
        
        case 1 : // Valve 1
        {
            v1_Write(0);    
        }
        
    }
}

void closeValves()
{
    v1_Write(1);
}

/* [] END OF FILE */
