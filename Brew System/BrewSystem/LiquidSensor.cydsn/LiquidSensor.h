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
#pragma once
#include "project.h"

CY_ISR_PROTO(ISR_LiquidSensor_handler);

/* Public Functions */

/* Private Functions */
static void LiquidLED(); // function for turn on warning LED.
static void spiWarning(); // funtion for spi warning to client.

/* [] END OF FILE */
