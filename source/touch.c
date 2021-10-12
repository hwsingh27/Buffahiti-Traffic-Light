/*
 * @file: touch.c
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

uint32_t touch_val;

void Touch_Init(void)
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK;		//setting the clock for TSI
	TSI0->GENCS = TSI_GENCS_MODE(0u) | 		//operating in non-noise mode
			TSI_GENCS_REFCHRG(0u) | 		//reference oscillator charge and discharge value 500nA
			TSI_GENCS_DVOLT(0u) | 			//oscillator voltage rails set to default
			TSI_GENCS_EXTCHRG(0u) | 		//electrode oscillator charge and discharge value 500nA
			TSI_GENCS_PS(0u) | 				//frequency clock divided by one
			TSI_GENCS_NSCN (31u) | 			//scanning the electrode 32 times
			TSI_GENCS_TSIEN_MASK | 			//enabling the TSI module
			TSI_GENCS_EOSF_MASK; 			//writing one to clear the end of scan flag
}

int Touch_Scan_Lh(void)
{
	unsigned int scan=0; 							//initializing the value of scan as '0'
	TSI0->DATA = TSI_DATA_TSICH(10u); 				//selecting channel 10
	TSI0->DATA |= TSI_DATA_SWTS_MASK; 				//software trigger to start the scan
	while(!(TSI0->GENCS & TSI_GENCS_EOSF_MASK)); 	//waiting for the scan to complete 32 times
	scan = TSI0->DATA & 0xFFFF; 					//macro for extracting the count from data register
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK; 			//writing one to clear the end of the flag
	return scan;
}

int Touch_Detect(void)
{
	touch_val=0;
	touch_val=Touch_Scan_Lh();
	if(touch_val>650)
	{
		return 1;
	}
	return 0;
}
