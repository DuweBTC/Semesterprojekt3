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

#include "project.h"
#include "motorDriver.h"


int delay = 10;



void full()
{
    fullA1B2();
    fullB2A2();
    fullA2B1();
    fullB1A1();
    CyDelay(delay);
}

void Bfull()
{
    fullB1A1();
    fullA2B1();
    fullB2A2();
    fullA1B2();
    CyDelay(delay);
}


void fullA1B2()
{
    A1_Write(1);
    A2_Write(0);
    B1_Write(0);
    B2_Write(1);
    CyDelay(delay);
    
}

void fullB2A2()
{
    A1_Write(0);
    A2_Write(1);
    B1_Write(0);
    B2_Write(1);
    CyDelay(delay);   
}

void fullA2B1()
{
    A1_Write(0);
    A2_Write(1);
    B1_Write(1);
    B2_Write(0);
    CyDelay(delay);
}

void fullB1A1()
{
    A1_Write(1);
    A2_Write(0);
    B1_Write(1);
    B2_Write(0);
    CyDelay(delay);
}

/* [] END OF FILE */
