/*
 * HelloWorld.c
 *
 * Created: 9/9/2025 10:43:27 AM
 * Author : Alin
 */ 



#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"

int main(void) {  

  int input;  

  uart_init(); // open the communication to the microcontroller
  io_redirect(); // redirect input and output to the communication

    
  while(1) {
		
	  printf("Hello World \n");
	  _delay_ms(1000);

  }
  
  return 0;
}
