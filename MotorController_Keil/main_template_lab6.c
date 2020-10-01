/*
 * Main module for testing the PWM Code for the K64F
 * 
 * Author:  
 * Created:  
 * Modified: Carson Clarke-Magrab <ctc7359@rit.edu> 
 */

#include "MK64F12.h"
#include "uart.h"
#include "PWM.h"

void delay(int del);

int main(void) {
	// Initialize UART and PWM
	FTM0_init();
	uart_init();

	// Print welcome over serial
	uart_put("Running... \n\r");
	
	/* Part 1 - UNCOMMENT THIS
	// Generate 20% duty cycle at 10kHz
	FTM0_set_duty_cycle(60, 10000, 0);
	
	for(;;) ;  //then loop forever
	*/
	
	// Part 2 - UNCOMMENT THIS
	for(;;)  //loop forever
	{
		uint16_t dc = 0;
		uint16_t freq = 10000; // Frequency = 10 kHz 
		uint16_t dir = 0;
		char c = 48;
		int i=0;
		
		// 0 to 100% duty cycle in forward direction
		for (i=0; i<100; i++) {
		    FTM0_set_duty_cycle(i, freq, dir);
			
			delay(10);
		}
		
		// 100% down to 0% duty cycle in the forward direction
		for (i=100; i>=0; i--) {
		    FTM0_set_duty_cycle(i, freq, dir);
			
			delay(10);
		}
		
		dir = !dir;
		
		// 0 to 100% duty cycle in reverse direction
		for (i=0; i<100; i++) {
		    FTM0_set_duty_cycle(i, freq, dir);
			
			delay(10);
		}
		
		// 100% down to 0% duty cycle in the reverse direction
		for (i=100; i>=0; i--) {
		    FTM0_set_duty_cycle(i, freq, dir);
			
			delay(10);
		}

	}

	return 0;
}


/**
 * Waits for a delay (in milliseconds)
 * 
 * del - The delay in milliseconds
 */
void delay(int del){
	int i;
	for (i=0; i<del*50000; i++){
		// Do nothing
	}
}
