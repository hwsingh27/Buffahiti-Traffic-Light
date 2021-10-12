/**
 * @file: switch.h
 * @brief: consists of two functions including the
 * interrupt handler. Init_Interrupt() is used to
 * configure the interrupt.
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean and and KL25Z Reference Manual.
 */

#ifndef SWITCH_H_
#define SWITCH_H_

/**
 * @brief: function is used to configure the interrupt
 * for the switch (GPIO). Pin 7 of PORTD is used to
 * connect the external switch. Configured PORTD bit
 * SWITCH_POS to generate an interrupt on the falling
 * edge of input signal.
 *
 * @param: NULL
 * @return: returns NULL
 */

void Init_Interrupt(void);

/**
 * @brief: function is used to perform the
 * task when interrupt is detected.
 * When the external switch is pressed, the state
 * changes to the CROSSWALK_TRANSITION state and
 * the message is printed stating the change of state.
 *
 * @param: NULL
 * @return: returns NULL
 */
void PORTD_IRQHandler(void);

#endif /* SWITCH_H_ */
