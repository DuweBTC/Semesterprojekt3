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
//#include "I2C.h"
#include "UART.h"
#include "ActuatorDriver.h"
#include "WeightSensor.h"
#include "LiquidSensor.h"
#include <stdbool.h>


#define ARRAY_SIZE 8

uint8 firstMessage[ARRAY_SIZE];
uint8 secondMessage[ARRAY_SIZE];
uint8 slaveMessage[ARRAY_SIZE];
bool firstMessageRecieved = false;
bool lastIngr;

CY_ISR_PROTO(ISR_UART_rx_handler);
CY_ISR_PROTO(timer_inter_handler);

void handleByteReceived(uint8_t byteReceived);
bool checkUart();
void readMasterMess();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    timer_isr_StartEx(timer_inter_handler);
    UART_1_Start();
    Timer_1_Enable();
    firstMessage[0]=0;
    secondMessage[0]=0;
    UART_1_PutString("program started\r\n");
    UART_1_PutString("0: Setting first/secondMessage[0]\r\n");
    UART_1_PutString("1: Setting first/secondMessage[1]\r\n");
    UART_1_PutString("2: Setting first/secondMessage[2]\r\n");
    UART_1_PutString("3: Setting first/secondMessage[3]\r\n");
    UART_1_PutString("4: Setting first/secondMessage[4]\r\n");
    UART_1_PutString("5: Setting first/secondMessage[5]\r\n");
    UART_1_PutString("6: Setting first/secondMessage[6]\r\n");
    UART_1_PutString("7: Setting first/secondMessage[7]\r\n");
    UART_1_PutString("8: Message ended checking and sending return message\r\n");
    
    
    for(;;)
    {
        /* Place your application code here. */
        
        /*if(I2C_1_SlaveStatus() & I2C_1_SSTAT_RD_CMPLT)
        {
            int byteToBeSent;
            byteToBeSent = I2C_1_SlaveGetReadBufSize(); // number of bytes to be read
            
            if(byteToBeSent == I2C_1_slRdBufSize) // Check if Master has finished reading all the bytes from the rdBuf
            {
                I2C_1_SlaveClearReadStatus();
                writeI2C();
            }
        }*/
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch (byteReceived)
    {
    case '0':
    {
        UART_1_PutString("Hello World\r\n");
    }
    break;
    case '1':
    {
        if(firstMessage[1] == 1)
        {
            secondMessage[1]=1;
        }
        else
        {
            firstMessage[1]=1;
        }
    }
    break;
    case '2':
    {
        if(firstMessage[2] == 1)
        {
            secondMessage[2]=1;
        }
        else
        {
            firstMessage[2]=1;
        }
    }
    break;
    case '3':
    {
        if(firstMessage[3] == 1)
        {
            secondMessage[3]=1;
        }
        else
        {
            firstMessage[3]=1;
        }
    }
    break;
    case '4':
    {
        if(firstMessage[4] == 1)
        {
            secondMessage[4]=1;
        }
        else
        {
            firstMessage[4]=1;
        }

    }
    break;
    case '5':
    {
        if(firstMessage[5] == 1)
        {
            secondMessage[5]=1;
        }
        else
        {
            firstMessage[5]=1;
        }
        
    }
    break;
    case '6':
    {
        if(firstMessage[6] == 1)
        {
            secondMessage[6]=1;
        }
        else
        {
            firstMessage[6]=1;
        }
    }
    break;
    case '7':
    {
        if(firstMessage[7] == 1)
        {
            secondMessage[7]=1;
        }
        else
        {
            firstMessage[7]=1;
        }
    }
    break;
    case '8':
    {        
        if ( checkUart() == true)
        {
            readMasterMess();
            pour();
        }
        //writeUart();
    }
    case 'b' :
    {
        firstMessage[0] = 0;
        firstMessage[1] = 0;
        firstMessage[2] = 1;
        firstMessage[3] = 0;
        firstMessage[4] = 0;
        firstMessage[5] = 1;
        firstMessage[6] = 0;
        firstMessage[7] = 1;
        
        secondMessage[0] = 0;
        secondMessage[1] = 0;
        secondMessage[2] = 1;
        secondMessage[3] = 0;
        secondMessage[4] = 0;
        secondMessage[5] = 1;
        secondMessage[6] = 0;
        secondMessage[7] = 1;
    }
    break;
    
    case 'n' :
    {
        firstMessage[0] = 0;
        firstMessage[1] = 0;
        firstMessage[2] = 1;
        firstMessage[3] = 0;
        firstMessage[4] = 1;
        firstMessage[5] = 1;
        firstMessage[6] = 0;
        firstMessage[7] = 1;
        
        secondMessage[0] = 0;
        secondMessage[1] = 0;
        secondMessage[2] = 1;
        secondMessage[3] = 0;
        secondMessage[4] = 1;
        secondMessage[5] = 1;
        secondMessage[6] = 0;
        secondMessage[7] = 1;
    }
    break;
    
    default:
    {
        
    }
    break;
    }
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back

        handleByteReceived(byteReceived);

        bytesToRead--;
    }
}

void writeUart()
{
    if (checkUart() == true )
    {
        slaveMessage[1] = 1;
    } else {
        slaveMessage[1] = 0;
    }
    
    if (checkForGlass() == true)
    {
        slaveMessage[2] = 1;
    } else {
        slaveMessage[2] = 0;
    }
    if (checkLiquid_1() == true)
    {
        slaveMessage[3] = 1;
    } else {
        slaveMessage[3] = 0;
    }
    /* udkommenteret da der ikke er sensore på dem
    if (checkLiquid_2() == true)
    {
        slaveMessage[4] = 1;
    } else {
        slaveMessage[4] = 0;
    }
    if (checkLiquid_3() == true)
    {
        slaveMessage[5] = 1;
    } else {
        slaveMessage[5] = 0;
    }
    if (checkLiquid_4() == true)
    {
        slaveMessage[6] = 1;
    } else {
        slaveMessage[6] = 0;
    }
    */
    if (lastIngr == true )
    { 
        slaveMessage[7] = 1;
    } else {
        slaveMessage[7] = 0;
    }
    
    for(int i=0;i<8;++i)
    {
        if(firstMessage[i]==secondMessage[i])
        {
            UART_1_WriteTxData(slaveMessage[i]);
            
            //UART_1_PutChar(firstMessage[i]);
            firstMessage[i]=0;
            secondMessage[i]=0;           
        }
    }
}

bool checkUart()
{
    bool BeskedEns;
    
    for(int i=0;i<8;++i)
    {
        if(firstMessage[i]==secondMessage[i])
        {
            BeskedEns = true;
            slaveMessage[1] = 1;           
        } else {
            BeskedEns = false;
            slaveMessage[1] = 0;
            break;
        }
    }
    return BeskedEns;
}

void readMasterMess()
{
    int flask = 0;
    int maengde = 0;
    
    if (firstMessage[2] == 1)
    {
        flask += 1;
    }
    if (firstMessage[1] == 1)
    {
        flask += 2;
    }
    
    if (firstMessage[6] == 1)
    {
        maengde += 1;
    }
    if (firstMessage[5] == 1)
    {
        maengde += 2;
    } 
    if (firstMessage[4] == 1)
    {
        maengde += 4;
    }
    if (firstMessage[3] == 1)
    {
        maengde += 8;
    }
    if (firstMessage[7] == 1)
    {
        lastIngr = true;
    } else {
        lastIngr = false;
    }
    
    setIngredient(flask, maengde);
}

/* [] END OF FILE */
