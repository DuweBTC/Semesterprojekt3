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
#include "I2C.h"
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        if(I2C_1_SlaveStatus() & I2C_1_SSTAT_RD_CMPLT)
        {
            int byteToBeSent;
            byteToBeSent = I2C_1_SlaveGetReadBufSize(); // number of bytes to be read
            
            if(byteToBeSent == I2C_1_slRdBufSize) // Check if Master has finished reading all the bytes from the rdBuf
            {
                I2C_1_SlaveClearReadStatus();
                writeI2C();
            }
        }
    }
}

/* [] END OF FILE */
