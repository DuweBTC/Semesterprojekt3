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
//#include "UART.h"
CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    UART_1_PutString("program started\r\n");
    UART_1_PutString("1:Hello world\r\n");
    /*UART_1_PutString("0: Setting first/secondMessage[0]\r\n");
    UART_1_PutString("1: Setting first/secondMessage[1]\r\n");
    UART_1_PutString("2: Setting first/secondMessage[2]\r\n");
    UART_1_PutString("3: Setting first/secondMessage[3]\r\n");
    UART_1_PutString("4: Setting first/secondMessage[4]\r\n");
    UART_1_PutString("5: Setting first/secondMessage[5]\r\n");
    UART_1_PutString("6: Setting first/secondMessage[6]\r\n");
    UART_1_PutString("7: Setting first/secondMessage[7]\r\n");
    UART_1_PutString("8: Message ended\r\n");
    */
    
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
        
    }
    break;
    case '2':
    {
        //driveForwards();
    }
    break;
    case '3':
    {
        //driveBackwards();
    }
    break;
    case '4':
    {
        //stop();

    }
    break;
    case '5':
    {
        //start();
        
    }
    break;
    case '6':
    {
        //driveBackwards();
    }
    break;
    case '7':
    {
        //driveBackwards();
    }
    break;
    case '8':
    {
        //driveBackwards();
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

/* [] END OF FILE */
