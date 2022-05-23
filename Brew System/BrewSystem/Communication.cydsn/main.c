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
#include <stdbool.h>

#define ARRAY_SIZE 8

int firstMessage[ARRAY_SIZE];
int secondMessage[ARRAY_SIZE];
int slaveMessage[ARRAY_SIZE];
bool firstMessageRecieved = false;
CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
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
        writeUart();
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
    for(int i=0;i<8;++i)
    {
        if(firstMessage[i]==secondMessage[i])
        {
            UART_1_WriteTxData(firstMessage[i]);
            firstMessage[i]=0;
            secondMessage[i]=0;
        }
    }
}

/* [] END OF FILE */
