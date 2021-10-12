/**
 * @file: pwm.h
 * @brief: file has 3 functions Init_Pwm(), Set_Color()
 * and Color_Transition() for configuring, setting the colors and
 * for transition using the provided mathematical equation
 * respectively.
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo
 * and KL25Z Reference Manual.
 */

#ifndef PWM_H_
#define PWM_H_

/**
 * @brief: function configures the TPM for RGB
 * to  control the LEDs using PWM. Clock source
 * for TPM is set as 48MHz.
 *
 * @param: NULL
 * @return: NULL
 */
void Init_Pwm(void);

/**
 * @brief: function is used to switch LED on and off
 * using the CONTROL register of red, green and blue color.
 * Computes the values of RGB out of 48000 since it is maximum
 * value that can be set to glow the LED to its brightest level.
 *
 * @param: takes RGB colors as parameters
 * @return: NULL
 */
void Set_Color(int r, int g, int b);

/**
 * @brief: function is used to compute the values of RGB for
 * the transition period of 1sec using the mathematical equation
 * with the starting and ending values of RGB for each state.
 *
 * @param: NULL
 * @return: NULL
 */
void Color_Transition();

#endif /* PWM_H_ */
