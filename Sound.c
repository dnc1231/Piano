// Sound.c
// This module contains the SysTick ISR that plays sound
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data
#include <stdint.h>
#include "dac.h"
#include "tm4c123gh6pm.h"
const unsigned short wave[32] = {8,9,10,12,13,14,14,15,15,15,14,14,13,12,10,9,8,6,5,3,2,1,1,0,0,0,1,1,2,3,5,6};;

// **************Sound_Init*********************
// Initialize Systick periodic interrupts
// Called once, with sound initially off
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
// Output: none
void Sound_Init(uint32_t period){
	//Enable Periodic systick interrupts
	NVIC_ST_CTRL_R = 0; //disable the interrupt during setup
	NVIC_ST_RELOAD_R = period - 1; //reload value
	NVIC_ST_CURRENT_R = 0; //clears data in current
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; //priority 2
	NVIC_ST_CTRL_R = 0x00000007; //Enable the interrupts
}


// **************Sound_Play*********************
// Start sound output, and set Systick interrupt period 
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
//         input of zero disable sound output
// Output: none
void Sound_Play(uint32_t period){

	NVIC_ST_RELOAD_R = period;//Inserts the reload value to produce that fre
}

int var = 0;//implement the interrupt before outputting each element
void SysTick_Handler (void)
{	var = (var+1)&31;
	GPIO_PORTF_DATA_R ^= 0x08;
	DAC_Out(wave[var]); //Output the current element in the array (sine wave)
	//var = (var+1)&31; //Incrememnt to the next element in the array
	GPIO_PORTF_DATA_R ^= 0x08; //heartbeat
};