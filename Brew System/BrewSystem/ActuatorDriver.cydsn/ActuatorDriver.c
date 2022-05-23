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

static void openValveNr(int valveNumber);
static void closeValves();

int CONTAINER;
int AMOUNT;

bool DONE = false;


CY_ISR(timer_inter_handler)
{
    DONE = true;
}

int pour()
{
    float time;
    float timerVariabel = 24;
    float x = 156; // skal ændres når ventiler er blevet testet.
    
    time = AMOUNT * x * timerVariabel;
    
    DONE = false;
    
    Pour_Timer_WriteCounter(0); // makes sure timer counter is 0
    Pour_Timer_WritePeriod(time); // Writes periode to timer
    
    openValveNr(CONTAINER); // Opens valve for specific container
    
    Pour_Timer_Start();
    while (DONE != true)
    {
        /* Waiting for time until pour is done */
    }
    
    closeValves(); // Close all valves
    
    Pour_Timer_Stop(); // Stops timer;
        
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
        case '1': // Valve 1
        {
            v1_Write(1);
            v2_Write(0);
            v3_Write(0);
            v4_Write(0);
        }
        case '2': // Valve 2
        {
            v1_Write(0);
            v2_Write(1);
            v3_Write(0);
            v4_Write(0);
        }
        case '3': // Valve 3
        {
            v1_Write(0);
            v2_Write(0);
            v3_Write(1);
            v4_Write(0);
        }
        case '4': // Valve 4
        {
            v1_Write(0);
            v2_Write(0);
            v3_Write(0);
            v4_Write(1);
        }
    }
}

static void closeValves()
{
    v1_Write(0);
    v2_Write(0);
    v3_Write(0);
    v4_Write(0);
}

/* [] END OF FILE */
