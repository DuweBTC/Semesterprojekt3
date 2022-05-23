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

#include "WeightSensor.h"
#include <stdio.h>

bool checkForGlass()
{
    bool placed = true;
    float weight;
    
    /*
    ADC_SAR_1_Start(); // Start ADC_SAR_1
    ADC_SAR_1_StartConvert(); // Start ADC_SAR_1 converter
    */
    /*
    if (ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT))
    {
        //Modtager Hex værdi fra vægt
        uint16_t result = ADC_SAR_1_GetResult16(); 
                                    
        // Omregner resultat værdien, til den egentlig vægt, efter kalibering test.
        weight = result * 0.7646 - 226.64;                
    }
    */
    /*
    if ( weight > 2 )
    {
        placed = true;
    } else {
        placed = false;
    }
    
    ADC_SAR_1_Stop();
    ADC_SAR_1_StopConvert();
    */
    
    return placed;
}

/* [] END OF FILE */
