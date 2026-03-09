#include "SDU_SHIELD.h"

void set_all_buttons_to_input() {

    //set as input
    BTN_DDR &= ~(1 << BTN_1);
    BTN_DDR &= ~(1 << BTN_2);
    BTN_DDR &= ~(1 << BTN_3);
    BTN_DDR &= ~(1 << BTN_4);

    //pull up resistors:   
    BTN_PORT |= 1 << BTN_1;
    BTN_PORT |= 1 << BTN_2;
    BTN_PORT |= 1 << BTN_3;
    BTN_PORT |= 1 << BTN_4;
}
void set_all_leds() {

  LED_DDR |= 1 << LED_1;
  LED_DDR |= 1 << LED_2;
  LED_DDR |= 1 << LED_3;
  LED_DDR |= 1 << LED_4;

}

void read_xy_values(void); //checking which button is pressed
void show_output(void); //showing current state + state variables on the screen
void state_transition(void); //advancing to the new state by implementing transition equations

unsigned char x, y, z1, z2; // inputs and outputs
unsigned char q0, q1, q2, q0_next, q1_next, q2_next = 0;

int main(void) {  


  uart_init(); 
  io_redirect(); 
  set_all_buttons_to_input();
  

    
  while(1) {
		
	  read_xy_values();
    state_transition();
    show_output();
    _delay_ms(1000);

  }
  
  return 0;
}


void read_xy_values() {

  x = (BTN_PIN >> BTN_3) & 1U ? 0 : 1;
  y = (BTN_PIN >> BTN_4) & 1U ? 0 : 1;

}

void state_transition() {


  q0_next = (!q1 & x) | (q0 & !x) | (!q2);
  q1_next = (!q2 & q0 & x) | (q1 & !x) | (q2 & q1);
  q2_next = (q2 & !q0) & (q1 & !x) | (q2 & q1);


  LED_PORT |= 1 << LED_2;
  _delay_ms(100);
  LED_PORT &= ~(1 << LED_2);

}

void show_output() {

  printf("X = %u \n", x);
  printf("Y = %u \n", y);

}