// Lab6.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// MOOC lab 13 or EE319K lab6 starter
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********


#include <stdint.h>
#include "tm4c123gh6pm.h"//sets microcontroller to run 80MHz
#include "Sound.h"//Allows the file to be accessed from here
#include "Piano.h"//same
#include "TExaS.h"//same
#include "Dac.h"//same
#define clockspeed 80000000
#define DACprec	32
#define F4 (clockspeed/(DACprec * 349))//calculated frequency
#define A4 (clockspeed/(DACprec * 440))
#define G3 (clockspeed/(DACprec * 196))
// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts


int main(void)
{      
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    //sets bus clock at 80 MHz
  Piano_Init();//calls in that certain function for this program
  Sound_Init(25000);//currently no input, so no so
	DAC_Init();
  // other initialization
  EnableInterrupts();
	unsigned long Data = 0;//Data variable is defined 
	int var = 0;
  while(1){
    Data = Piano_In();	//Data will contain the keys pressed
		if ( Data == 0x05 ){
			Sound_Play(F4);//Bit 2 (key 1) in PA will play F4
			//for (var = 0 ; var < 1000000 ; var++){
				//var = var + 0;
			
		}
		else if (Data == 0x11){
			Sound_Play(A4);//Bit 3 (key 2) in PA will play A4
			//for (var = 0 ; var < 1000000 ; var++){
				//var = var + 0;
			
		}
		else if (Data == 0x09){
			Sound_Play(G3);//Bit 4 (key 3) in PA will play G3
		//for (var = 0 ; var < 1000000 ; var++){
				//var = var + 0;
			
		}
		else {
			Sound_Play(0);//Don't play anything if button not pressed
		//	for (var = 0 ; var < 1000000 ; var++){
				//var = var + 0;
			}
		
	}          
}	

