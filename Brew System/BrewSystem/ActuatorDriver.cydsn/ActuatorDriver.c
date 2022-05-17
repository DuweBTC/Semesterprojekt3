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

void openValveNr(int valveNumber)
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

void closeValveNr()
{
    v1_Write(0);
    v2_Write(0);
    v3_Write(0);
    v4_Write(0);
}



/* [] END OF FILE */
