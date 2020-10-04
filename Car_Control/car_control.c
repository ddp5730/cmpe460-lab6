/*
 * Main module for running motor control for the car
 *
 * Author: Dan Popp & Alex Guan
 * Created: 10/3/20
 */
 
 #include "MK64F12.h"
 #include "uart.h"
 #include "PWM.h"
 
 void delay(int del);
 
 int main(void) {
	 
	 // Initialize Devices
	 uart_init();
	 FTM0_init();	// PWM for DC motors
	 
	 uart_put("Starting up motors....\n\r");
	 
	 // TODO -- Add UART control vs. hard coding
	 
	 // Generate PWM for motors
	 
	 uint16_t dc_freq = 10000; // 10 kHz DC motor PWM
	 uint16_t servo_freq = 50; // 50 Hz servo PWM
	 
	 
	 while (1) {
			// Run DC motor reusing sample code
		 for (int i=0; i<100; i++) {
		    FTM0_set_duty_cycle(i, dc_freq, 0);
			
			delay(2);
		}
		
		// 100% down to 0% duty cycle in the forward direction
		for (int i=100; i>=0; i--) {
		    FTM0_set_duty_cycle(i, dc_freq, 0);
			
			delay(2);
		}
	 }
	 
	 // Generate PWM for Servo
	 
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