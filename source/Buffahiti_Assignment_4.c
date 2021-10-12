/*
 * @file: Buffahiti_Assignment_4.c
 * @brief: main(void) calls the statemachine
 * after the print statement.
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo
 * and KL25Z Reference Manual.
 */

#include <stdio.h>
#include "common.h"

int main(void)
{
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    Init_Interrupt();
	Init_Systick();
	Touch_Init();
	Init_Pwm();

	LOG("MAIN LOOP IS STARTING\n\r");
	Statemachine();

    return 0 ;
}
