// Piano.c
// This software configures the off-board piano keys
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
#include "tm4c123gh6pm.h"

// **************Piano_Init*********************
// Initialize piano key inputs, called once 
// Input: none 
// Output: none
void Piano_Init(void){
	SYSCTL_RCGC2_R |= 0x01;    //Activate Port A
	GPIO_PORTA_CR_R = 0x3C;
	GPIO_PORTA_PUR_R = 0x00;
	GPIO_PORTA_DIR_R &= ~0x3C;    // make PA5-2 in
  GPIO_PORTA_AFSEL_R &= ~0x3C; // disable alt func on PA5-2
  GPIO_PORTA_DEN_R |= 0x3C;    // enable digital I/O on P5-2
	                               // configure PA5-2 as GPIO
  GPIO_PORTA_PCTL_R = 0x00;
  GPIO_PORTA_AMSEL_R &= ~0x3C; // disable analog functionality on PA5-2
}

// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 7 depending on keys
// 0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2
uint32_t Piano_In(void){
	GPIO_PORTA_DATA_R |= 0x3C;
	return GPIO_PORTA_DATA_R;
}
