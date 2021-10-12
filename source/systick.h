/**
 * @file: systick.h
 * @brief: consists of 6 functions for configuring
 * and using the Systick Timer
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo and
 * KL25Z Reference Manual.
 */

#include <stdio.h>

#ifndef SYSTICK_H_
#define SYSTICK_H_

typedef uint32_t ticktime_t;

/**
 * @brief: this Init function is used to configure the clock
 * by loading the counter value as per the requirement.
 * Here 10msec has been taken as 1 count value, hence load
 * value becomes (0.01 x 48000000)/16
 *
 * @param: NULL
 * @return: NULL
 */
void Init_Systick();

/**
 * @brief: function becomes active as soon as the Systick is enabled
 * keeps incrementing the values of timer and counter.
 *
 * @param: NULL
 * @return: NULL
 */
void SysTick_Handler();

/**
 * @brief: function checks if the capacitive sensor's
 * value if greater than the threshold.
 *
 * @param: NULL
 * @return: gives the current time since startup by returning
 * the value of timer. To get the correct time, timer should be multipled
 * by 10 since one count equals 10msec.
 */
ticktime_t Now();

/**
 * @brief: function stores the current time in reset variable.
 *
 * @param: NULL
 * @return: NULL
 */
void Reset_Timer();

/**
 * @brief: function return the time passed since the last
 * call to reset
 *
 * @param: NULL
 * @return: returns ticks since the last call to Reset_Timer()
 */
ticktime_t Get_Timer();

/**
 * @brief: function is used to toggle to LED between 750msec and
 * 250msec by resetting the counter value to zero.
 *
 * @param: NULL
 * @return: NULL
 */
void Reset_Counter();

/**
 * @brief: function is used to toggle to LED between 750msec and
 * 250msec by keep tracking of time passed since the last call
 * to Reset_Counter().
 *
 * @param: NULL
 * @return: NULL
 */
ticktime_t Get_Counter();

#endif /* SYSTICK_H_ */
