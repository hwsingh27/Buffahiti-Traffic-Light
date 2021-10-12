/*
 * @file: systick.c
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
#include "core_cm0plus.h"

/*
 * Made the variables counter, reset and timer as static volatile
 * as suggested by Varun Mehta.
 */
static volatile ticktime_t counter=0;
static volatile ticktime_t reset=0;
static volatile ticktime_t timer=0;

void Init_Systick()
{
	SysTick->LOAD = (48000000/16)/100; 									//10msecx48Mhz/16
	NVIC_SetPriority(SysTick_IRQn,1);  									//interrupt priority is set to 1
	SysTick->VAL=0;					   									//force load of reload value
	SysTick->CTRL=SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;	//enable interrupt and systick timer with alternative clock source
}

void SysTick_Handler()
{
	timer++;
	counter++;
}

ticktime_t Now()
{
	return timer;
}

void Reset_Timer()
{
	reset=Now();
}

ticktime_t Get_Timer()
{
	return (timer-reset);
}

void Reset_Counter()
{
	counter=0;
}

ticktime_t Get_Counter()
{
	return counter;
}
