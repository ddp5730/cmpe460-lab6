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

#define USER_PROMPT "\r\nPlease enter a string (255 char or less):\t"
#define STRING_PROMPT "\r\nYou entered the following string:\t\t"
#define NEW_LINE "\r\n"
#define MAX_STR_LENGTH 255

void delay(int del);
void init_GPIO(void);
void set_coil_states(int on, int off1, int off2, int off3);

int main(void) {
	// Initialize UART and PWM
	uart_init();

	// Simple Echo Program test for uart code
	uart0_put("Running... \n\r");
	
	// Handle User input
	for (;;) {
		
		uart0_put(USER_PROMPT);
		
		// Set up variables for this user input
		int current_str_len = 0;
		char user_input_str[MAX_STR_LENGTH + 1] = {0};	// + 1 for null byte
		
		// Loop to accept new user input chars until max length is reached
		char* current_input_char;
		do {
			
			uart0_getchar(current_input_char);
			
			// Break out if user enters carriage return char
			if (*current_input_char == '\r') {
				// Do nothing once max length reached.
			}
			// Only save the string if the max length hasn't been reached.
			else if (current_str_len <= MAX_STR_LENGTH) {
				// Print input back to user
				uart0_putchar(*current_input_char);				
				// Append new value to user_input_str and increment index
				user_input_str[current_str_len++] = *current_input_char;
			}
			
			
		} while (*current_input_char != '\r');
		
		user_input_str[current_str_len] = '\0'; // Add null byte to end of used string buffer
		
		uart0_put(STRING_PROMPT);
		uart0_put(user_input_str);
		uart0_put(NEW_LINE);

	return 0;
	}
}
