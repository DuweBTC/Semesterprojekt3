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
#include "LiquidSensor.h"

CY_ISR_PROTO(ISR_UART_rx_handler);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ISR_LiquidSensor_StartEx(ISR_LiquidSensor_handler);
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

// Interrupt funcation for writing in terminal
CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        bytesToRead--;
    }
}

/* [] END OF FILE */
