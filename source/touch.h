/**
 * @file: touch.h
 * @brief: consists of three functions
 * namely Touch_Init(), Touch_Scan_Lh()
 * and Touch_Detect(void);
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean and GitHub repo
 * @Link: https://github.com/alexander-g-dean/ESF/tree/
 * master/NXP/Misc/Touch%20Sense/TSI/src
 */

#ifndef TOUCH_H_
#define TOUCH_H_

/**
 * @brief: function is used to set the
 * clock for TSI and set the configurations
 * for TSI
 *
 * @param: NULL
 * @return: returns NULL
 */
void Touch_Init(void);

/**
 * @brief: function is used to extract the value
 * from the touch capacitive sensor and stores
 * the value in 'scan' variable.
 *
 * @param: NULL
 * @return: returns the touch sensor value
 * through scan variable.
 */
int Touch_Scan_Lh(void);

/**
 * @brief: function checks if the capacitive sensor's
 * value if greater than the threshold.
 *
 * @param: NULL
 * @return: returns 1 if the capacitive sensor's
 * value i.e. touch_val is greater than the threshold (650)
 * else it returns 0.
 */
int Touch_Detect(void);

#endif /* TOUCH_H_ */
