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
#include "ActuatorDriver.h"

CY_ISR_PROTO(ISR_UART_rx_handler);
CY_ISR_PROTO(timer_inter_handler);

void handleByteReceived(uint8_t byteReceived);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    
    UART_1_Start();
    timer_isr_StartEx(timer_inter_handler);
    Timer_1_Enable();
    
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
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 'b' :
        {
            pour();
            setIngredient(1,2);
            break;
        }
        case 'n' :
        {
            setIngredient(1, 10);
            pour();
            break;
        }
    }
    
}

/* [] END OF FILE */
