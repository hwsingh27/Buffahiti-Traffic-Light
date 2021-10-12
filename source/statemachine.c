/*
 * @file: statemachine.c
 *
 * @author: Harshwardhan Singh
 * @date: October 11th 2021
 *
 * @tools: MCUXpresso IDE and FRDM-KL25Z Development Board
 * @Credits: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers (Textbook)
 * by Alexander G.Dean, GitHub repo, the code
 * example shared by Prof. Howdy Pierce on Slack Channel
 * and KL25Z Reference Manual.
 */

#include <stdio.h>
#include "common.h"

int start_red;
int end_red;
int start_green;
int end_green;
int start_blue;
int end_blue;

volatile state_e state=STOP;

#ifdef DEBUG
char* State_To_String(state_e state)
{
	char *str;
	switch(state)
	{
		case STOP:
			str = "STOP";
			break;
		case STOP_GO_TRANSITION:
			str = "TRANSITION";
			break;
		case GO:
			str = "GO";
			break;
		case GO_WARNING_TRANSITION:
			str = "TRANSITION";
			break;
		case WARNING:
			str = "WARNING";
			break;
		case WARNING_STOP_TRANSITION:
			str = "TRANSITION";
			break;
		case CROSSWALK_TRANSITION:
			str = "TRANSITION";
			break;
		case CROSSWALK:
			str = "CROSSWALK";
			break;
		case CROSSWALK_GO_TRANSITION:
			str = "TRANSITION";
			break;
	}
	return str;
}
#endif

void Statemachine(void)
{
	state_e prev_state=state;

	while(1)
	{
		if(Touch_Detect() && state!=CROSSWALK && state!=CROSSWALK_TRANSITION)
		{
			LOG("BUTTON PRESSED IS DETECTED AT %u msec \n\r",Now()*10);
			state=CROSSWALK_TRANSITION;
		}

		if(state != prev_state)
		{
			LOG("MOVING FROM %s STATE TO %s STATE AT %u msec\n\r",State_To_String(prev_state),State_To_String(state),Now()*10);
			prev_state=state;
			Reset_Timer();
		}

		switch(state)
		{
		case STOP:
			if(Get_Timer()>DELAY_STATE)
			{
				state=STOP_GO_TRANSITION;
			}
			start_red=STOP_RED;
			start_green=STOP_GREEN;
			start_blue=STOP_BLUE;

			Set_Color(STOP_RED,STOP_GREEN,STOP_BLUE);
			break;

		case STOP_GO_TRANSITION:
			if(Get_Timer()>DELAY_TRANSITION)
			{
				state=GO;
			}
			start_red=STOP_RED;
			end_red=GO_RED;
			start_green=STOP_GREEN;
			end_green=GO_GREEN;
			start_blue=STOP_BLUE;
			end_blue=GO_BLUE;

			Color_Transition();
			break;

		case GO:
			if(Get_Timer()>DELAY_STATE)
			{
				state=GO_WARNING_TRANSITION;
			}
			start_red=GO_RED;
			start_green=GO_GREEN;
			start_blue=GO_BLUE;

			Set_Color(GO_RED,GO_GREEN,GO_BLUE);
			break;

		case GO_WARNING_TRANSITION:
			if(Get_Timer()>DELAY_TRANSITION)
			{
				state=WARNING;
			}
			start_red=GO_RED;
			end_red=WARN_RED;
			start_green=GO_GREEN;
			end_green=WARN_GREEN;
			start_blue=GO_BLUE;
			end_blue=WARN_BLUE;

			Color_Transition();
			break;

		case WARNING:
			if(Get_Timer()>DELAY_WARNING)
			{
				state=WARNING_STOP_TRANSITION;
			}
			start_red=WARN_RED;
			start_green=WARN_GREEN;
			start_blue=WARN_BLUE;

			Set_Color(WARN_RED,WARN_GREEN,WARN_BLUE);
			break;

		case WARNING_STOP_TRANSITION:
			if(Get_Timer()>DELAY_TRANSITION)
			{
				state=STOP;
			}
			start_red=WARN_RED;
			end_red=STOP_RED;
			start_green=WARN_GREEN;
			end_green=STOP_GREEN;
			start_blue=WARN_BLUE;
			end_blue=STOP_BLUE;

			Color_Transition();
			break;

		case CROSSWALK_TRANSITION:
			if(Get_Timer()>DELAY_TRANSITION)
			{
				state=CROSSWALK;
				Reset_Counter();
			}
			end_red=CROSS_RED;
			end_green=CROSS_GREEN;
			end_blue=CROSS_BLUE;

			Color_Transition();
			break;

		case CROSSWALK:
			if(Get_Timer()>DELAY_CROSS)
			{
				state=CROSSWALK_GO_TRANSITION;
			}
			if(Get_Counter()<=DELAY_CROSS_ON)
			{
				Set_Color(CROSS_RED,CROSS_GREEN,CROSS_BLUE);
			}
			else if(Get_Counter()>DELAY_CROSS_ON && Get_Counter()<=DELAY_CROSS_OFF)
			{
				Set_Color(0,0,0);
			}
			else
				Reset_Counter();
			break;

		case CROSSWALK_GO_TRANSITION:
			if(Get_Timer()>DELAY_TRANSITION)
			{
				state=GO;
			}
			start_red=CROSS_RED;
			end_red=GO_RED;
			start_green=CROSS_GREEN;
			end_green=GO_GREEN;
			start_blue=CROSS_BLUE;
			end_blue=GO_BLUE;

			Color_Transition();
			break;
		}
	}
}
