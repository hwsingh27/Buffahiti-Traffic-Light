/**
 * @file: log.h
 * @brief: .h file for conditional compiling
 * in DEBUG and PRODUCTION mode.
 * Defined LOG to replace printf() with LOG()
 * in the program and use it for printing
 * the diagnostic output on terminal window
 * of MCUXpresso IDE
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Howdy Pierce's lecture notes
 */

#ifndef LOG_H_
#define LOG_H_

#ifdef DEBUG
#define LOG printf
#else
#define LOG(...)
#endif

#endif /* LOG_H_ */
