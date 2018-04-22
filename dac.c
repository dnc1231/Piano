// dac.c
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){
	SYSCTL_RCGC2_R |= 0x10; //Activate Port E
	//GPIO_PORTE_CR_R |= 0x0F;
	GPIO_PORTE_PUR_R = 0x00;
	GPIO_PORTE_DIR_R |= 0x0F;    // make PE3-0 out
  GPIO_PORTE_AFSEL_R &= ~0x0F; // disable alt func on PE3-0
  GPIO_PORTE_DEN_R |= 0x0F;    // enable digital I/O on PE3-0
	                               // configure PE3-0 as GPIO
  GPIO_PORTE_PCTL_R = 0x00;
  GPIO_PORTE_AMSEL_R &= ~0x0F; // disable analog functionality on PE3-0
	
	SYSCTL_RCGC2_R |= 0x20; //Activate Port F
	//GPIO_PORTE_CR_R |= 0x0F;
	GPIO_PORTF_PUR_R = 0x00;
	GPIO_PORTF_DIR_R |= 0x08;    // make PF3 out
  GPIO_PORTF_AFSEL_R &= ~0x08; // disable alt func on PF3
  GPIO_PORTF_DEN_R |= 0x08;    // enable digital I/O on PF3
	                               // configure PF3
  GPIO_PORTF_PCTL_R = 0x00;
  GPIO_PORTF_AMSEL_R &= ~0x08; // disable analog functionality on PF3
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(uint32_t data){
	GPIO_PORTE_DATA_R = data;
	return;
}


