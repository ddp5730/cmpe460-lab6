#ifndef __UART_H
#define __UART_H

#include "MK64F12.h"

void uart_init(void);
int uart0_putchar(char c);
int uart0_getchar(char* c);
int uart0_put(char* c);
int uart0_get(char **str, int n);

int uart3_putchar(char c);
int uart3_getchar(char* c);
int uart3_put(char* c);
int uart3_get(char **str, int n);

#endif
