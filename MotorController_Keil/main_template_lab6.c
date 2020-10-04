/*
 * Main module for testing the PWM Code for the K64F
 * 
 * Author:  
 * Created:  
 * Modified: Carson Clarke-Magrab <ctc7359@rit.edu> 
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "MK64F12.h"
#include "uart.h"
#include "PWM.h"

#define BUF_SIZE 100

void delay(int del);
void init_GPIO(void);
void set_coil_states(int on, int off1, int off2, int off3);
void get_user_string(char* buffer, int max_size);

int main(void) {
	// Initialize UART and PWM
	FTM0_init();
	FTM2_init();
	uart_init();

	// Print welcome over serial
	uart0_put("\r\n\nRunning... \n\r");
	
	char buf[BUF_SIZE];
	while(1) {
		
		
		uart0_put("Please choose a motor to control\r\n");
		uart0_put("'s' servo\r\n'd' DC Motor\r\n'o' all off\r\n");
		uart0_put("> ");
		
		get_user_string(buf, BUF_SIZE);
		
		if (!strncmp(buf, "s", BUF_SIZE - 1)) {
			uart0_put("Servo\r\n");
			uart0_put("Please enter duty cycle: ");
			get_user_string(buf, BUF_SIZE);
			int duty_cycle = atoi(buf);
			
			uart0_put("Please enter frequency: ");
			get_user_string(buf, BUF_SIZE);
			int frequency = atoi(buf);
			
			int is_valid_duty = (duty_cycle >= 0 && duty_cycle <= 100);
			int is_valid_freq = (frequency >= 0 && frequency <= 50000);
			
			if (is_valid_duty && is_valid_freq) {
				sprintf(buf, "Setting Servo to duty cycle: %d, and frequency: %d", duty_cycle, frequency);
				uart0_put(buf);
				FTM2_set_duty_cycle(duty_cycle, frequency);
			}
			else {
				uart0_put("Invalid values");
			}
			uart0_put("\r\n");
		}
		else if (!strncmp(buf, "d", BUF_SIZE - 1)) {
			uart0_put("DC Motor\r\n");
			uart0_put("Servo\r\n");
			
			uart0_put("Please enter duty cycle: ");
			get_user_string(buf, BUF_SIZE);
			int duty_cycle = atoi(buf);
			
			uart0_put("Please enter frequency: ");
			get_user_string(buf, BUF_SIZE);
			int frequency = atoi(buf);
			
			uart0_put("Please enter a direction (1) forwards (0) backwards: ");
			get_user_string(buf, BUF_SIZE);
			int direction = atoi(buf);
			
			int is_valid_duty = (duty_cycle >= 0 && duty_cycle <= 100);
			int is_valid_freq = (frequency >= 0 && frequency <= 50000);
			int is_valid_dir = (direction >= 0 && direction <= 1);
			
			if (is_valid_duty && is_valid_freq && is_valid_dir) {
				sprintf(buf, "Setting DC Motors to duty cycle: %d, frequency: %d, and direction: %d", duty_cycle, frequency, direction);
				uart0_put(buf);
				FTM0_set_duty_cycle(duty_cycle, frequency, direction);
			}
			else {
				uart0_put("Invalid values");
			}
			uart0_put("\r\n");
		}
		else if (!strncmp(buf, "o", BUF_SIZE - 1)) {
			uart0_put("Turning all motors OFF\r\n\n");
			FTM0_set_duty_cycle(0, 10000, 0);
			FTM2_set_duty_cycle(0, 50);
		}
		else {
			uart0_put("INVALID INPUT\r\n");
		}
		
	}

	return 0;
}

void get_user_string(char* buffer, int max_size) {
	char c;
	for (int i = 0; i < max_size;) {
		if (!uart0_getchar(&c)) {
			if (i != max_size - 2 && (c != '\r')) {
				uart0_putchar(c);
				buffer[i++] = c;
			}
			if (c == '\r') {
				uart0_put("\r\n");
				buffer[i]='\0';
				i = 0;
				return;
			}
		}
	}
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
