#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:Mohamed";
void main(void){
	UART_sendstring(string_buffer);
}