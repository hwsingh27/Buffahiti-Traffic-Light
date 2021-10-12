/**
 * @file: statemachine.h
 * @brief: file has few #defines, an enum declaration
 * along with two functions i.e. Statemachine(void)
 * and State_To_String(state_e state)
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo, the code
 * example shared by Prof. Howdy Pierce on Slack Channel
 * and KL25Z Reference Manual
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#define STOP_RED 	(0x61)  //starting value of RED at STOP state
#define STOP_GREEN 	(0x1E)	//starting value of GREEN at STOP state
#define STOP_BLUE 	(0x3C)	//starting value of BLUE at STOP state

#define GO_RED 		(0x22)	//starting value of RED at GO state
#define GO_GREEN 	(0x96)	//starting value of GREEN at GO state
#define GO_BLUE 	(0x22)	//starting value of BLUE at GO state

#define WARN_RED 	(0xFF)	//starting value of RED at WARNING state
#define WARN_GREEN 	(0xB2)	//starting value of GREEN at WARNING state
#define WARN_BLUE 	(0x00)	//starting value of BLUE at WARNING state

#define CROSS_RED 	(0x00)	//starting value of RED at CROSSWALK state
#define CROSS_GREEN (0x10)	//starting value of GREEN at CROSSWALK state
#define CROSS_BLUE 	(0x30)	//starting value of BLUE at CROSSWALK state

#define DELAY_TRANSITION  (100)		//1msec while transition
#define DELAY_CROSS 	  (1000)	//10sec while in CROSSWALK state

#define DELAY_CROSS_ON 	(75)	//750msec for toggling the LED in CROSSWALK state
#define DELAY_CROSS_OFF (100)	//1000msec for toggling the LED in CROSSWALK state

#ifdef DEBUG
#define DELAY_STATE 	(500)	//5sec stay in STOP and GO state in DEBUG mode
#define DELAY_WARNING 	(300)	//3sec stay in WARNING state in DEBUG mode
#else
#define DELAY_STATE 	(2000)	//20sec stay in STOP and GO state in PRODUCTION mode
#define DELAY_WARNING 	(500)	//5sec stay in WARNING state in PRODUCTION mode
#endif

typedef enum
{
	STOP,
	STOP_GO_TRANSITION,
	GO,
	GO_WARNING_TRANSITION,
	WARNING,
	WARNING_STOP_TRANSITION,
	CROSSWALK_TRANSITION,
	CROSSWALK,
	CROSSWALK_GO_TRANSITION
}state_e;

/**
 * @brief: this is the main statemachine function with total of 9 states,
 * it begins with checking the condition for the capacitive slider, if the
 * condition is true, it changes the state to CROSSWALK_TRANSITION and performs
 * the task. Otherwise, the loop runs from STOP->STOP_GO_TRANSITION->GO->GO_WARNING_TRANSITION->
 * WARNING->WARNING_STOP_TRANSITION->STOP and so on.
 * In each state, the START and END values of the color change for computing the
 * color using mathematical equation.
 *
 * @param: NULL
 * @return: while in DEBUG, the LED remains ON for 5sec in STOP and GO state and
 * remains ON for 3sec in WARNING state. In PRODUCTION, the LED remains ON for 20sec
 * in STOP and GO state and 5sec in WARNING state.
 * LED remains ON for 10sec in CROSSWALK state (toggling between 750msec and 250msec)
 * in both DEBUG and PRODUCTION. Transition happens for only 1sec.
 */
void Statemachine(void);

/**
 * @brief: function is used to get the string corresponding to the state
 * to print the diagnostic output in the terminal window of MCUXpresso.
 *
 * @param: takes enum state_e as a parameter
 * @return: returns the string corresponding to the state
 */
char* State_To_String(state_e state);


#endif /* STATEMACHINE_H_ */
