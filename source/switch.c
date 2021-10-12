/*
 * @file: switch.c
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo and
 * KL25Z Reference Manual.
 */

#include <stdio.h>
#include "common.h"

#define SWITCH_POS (7)
#define MASK(x) (1UL << (x))

extern volatile state_e state;

void Init_Interrupt(void)
{
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;		//setting the clock for PORTD
	PORTD->PCR[SWITCH_POS] = PORT_PCR_MUX(1) | PORT_PCR_PS_MASK
			| PORT_PCR_PE_MASK | PORT_PCR_IRQC(10);
	NVIC_SetPriority(PORTD_IRQn,2);			//set interrupt source PORTD_IRQn to priority 2
	NVIC_ClearPendingIRQ(PORTD_IRQn);		//clear interrupt pending flag for PORTD_IRQn
	NVIC_EnableIRQ(PORTD_IRQn);				//enable interrupt of type PORTD_IRQn
	__enable_irq();
}

void PORTD_IRQHandler(void)
{
	if((PORTD->ISFR & MASK(SWITCH_POS)) && state!=CROSSWALK && state!=CROSSWALK_TRANSITION)
	{
		state = CROSSWALK_TRANSITION;
		LOG("BUTTON PRESSED IS DETECTED AT %u msec \n\r",Now()*10);
	}
	PORTD->ISFR = 0xFFFFFFFF;		//clear status flags
}
