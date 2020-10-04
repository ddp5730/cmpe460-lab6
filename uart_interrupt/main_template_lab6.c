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
	
	uart0_put("yolo\r\n");
	
	char buf[10];
	int i = 0;
	while(1)
	{
		char c;
		if(!uart0_getchar(&c))
		{
			
			if(i != sizeof(buf) - 2) 
			{
				uart0_putchar(c);
				buf[i++] = c;
			}
			if(c == '\r') 
			{
				uart0_putchar('\n');
				buf[i] = 0;
				uart0_put(buf);
				i = 0;
				uart0_putchar('\n');
			}
		}
	}
}