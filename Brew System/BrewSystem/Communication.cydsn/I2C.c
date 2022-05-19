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

#include "I2C.h"

#include <stdbool.h>

    uint8 address = 0x00;
    uint8 bufSize = 8;
    uint8 rdBuf[8];
    uint8 wrBuf[8];
    bool lastIngredientReceived = false;

void initI2C()
{

    I2C_1_Start();         //Initering af I2C
    I2C_1_SlaveSetAddress(address);
    I2C_1_SlaveInitReadBuf((uint8*)rdBuf, bufSize);
    I2C_1_SlaveInitWriteBuf((uint8*)wrBuf, bufSize);
    I2C_1_SlaveClearReadBuf();
    I2C_1_SlaveClearWriteBuf();
}

void writeI2C()
{
    /*
    uint8 sendMessage = 0;
    sendMessage = I2C_1_slRdBufSize;
    */
    
    bool glassStatus = true; //= InPut fra glas sensor();
    bool bottle1Status = true; //= checkLiquid1(); InPut fra flaske1 sensor
    bool bottle2Status = true; //= InPut fra flaske2 sensor();
    bool bottle3Status = true; //= InPut fra flaske3 sensor();
    bool bottle4Status = true; //= InPut fra flaske4 sensor();
    //Glas
    rdBuf[0] = 0;
    rdBuf[1] = 0;
    if(glassStatus == true)
    {
        rdBuf[2] = 1;
    }
    else
    {
        rdBuf[2] = 0;
    }
    //Flaske1
    if(bottle1Status == true)
    {
        rdBuf[3] = 1;
    }
    else
    {
        rdBuf[3] = 0;
    }
    //Flase2
    if(bottle2Status == true)
    {
        rdBuf[4] = 1;
    }
    else
    {
        rdBuf[4] = 0;
    }
    
    //Flaske3
    if(bottle3Status == true)
    {
        rdBuf[5] = 1;
    }
    else
    {
        rdBuf[5] = 0;
    }
    
    if(bottle4Status == true)
    {
        rdBuf[6] = 1;
    }
    else
    {
        rdBuf[6] = 0;
    }
    /*
    if(lastIngredientReceived == true && drinkDone == true)
    {
        rdBuf[7] = 0;
        return lastIngredientReceived false;
    }
    else
    {
        rdBuf[7] = 1;
    }
    */
}

void readI2C()
{
    
}


/* [] END OF FILE */
