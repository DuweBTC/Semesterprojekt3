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

void initI2C()
{
    uint8 address = 0x00;
    uint8 bufSize = 8;
    uint8 *rdBuf;
    uint8 *wrBuf;
    I2C_1_Start();         //Initering af I2C
    I2C_1_SlaveSetAddress(address);
    I2C_1_SlaveInitReadBuf(rdBuf, bufSize);
    I2C_1_SlaveInitWriteBuf(wrBuf, bufSize);
    I2C_1_SlaveClearReadBuf();
    I2C_1_SlaveClearWriteBuf();
}

/* [] END OF FILE */
