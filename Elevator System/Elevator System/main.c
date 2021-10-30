/*
 * Elevator System.c  
 --------------------
  Target-> Atmega16a   
  
  Simple elevator system consists of
  1-LCD to display some words
  2-KeyPad to enter the floor number
  3- SevenSegment to display the current floor
  
  Interface  
  ----------
 * LCD Interface 
 * LCD Data -> PortA , LCD control -> Port D 
 * KeyPad Interface -> portC  
 * SevenSegment Interface - > PortB 
------------------------------------------------------------- 
 
 * Created: 30/10/2021 07:23:41 م
 * Author : mohamed khaled
 */ 

#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>
#include "KEYBAD.h"
#include "LCD.h" 
#include "SevenSegment.h"

int prevValue = 0; // Flag to remember the last floor that we are in

int main(void) {
	
	char x = 'g';
	int i;
	// INTERFACES INIT APIS 
	KeyPadInit();
	LCD_INIT();
	SevenSegmentInit();
	
	while(1){
		
		// Get the key pressed from the elevator KeyPad 
		x = KeyPadgetkeypressed();   
		// print the number of current floor 
		SevenSegmentUpdate(prevValue);
		// Print words on the elevator screen 
		LCD_SEND_A_STRING("welcome");
		LCD_CLEAR();
		
		// Check the which floor the user want to reach 
		if (x == '0' || x == '1' | x == '2' ||x == '3' ||x == '4' ||x == '5' ||x == '6' ||x == '7' ||x == '8' ||x == '9' )
		{
			int y = (int) x - 48 ;
			//check flag to up
			if ( y > prevValue){
				while (y != prevValue){
					prevValue++;
					for (i = 0 ; i < 100 ; i++ )   SevenSegmentUpdate(prevValue);
					LCD_SEND_A_STRING("welcome");
					LCD_CLEAR();
					
				}
				for (i = 0 ; i < 100 ; i++ ) SevenSegmentUpdate(prevValue);
			}
			
			// check flag to down
			if ( y < prevValue){
				while (y != prevValue){
					prevValue--;
					for (i = 0 ; i < 100 ; i++ ) SevenSegmentUpdate(prevValue);
					LCD_SEND_A_STRING("welcome ");
					LCD_CLEAR();
				}
				for (i = 0 ; i < 100 ; i++ ) SevenSegmentUpdate(prevValue);
			}
			_delay_ms(100);
			
		}
		
		
		
	}
	
	
}



