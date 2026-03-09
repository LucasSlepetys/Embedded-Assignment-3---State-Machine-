#ifndef SDU_SHIELD
#define SDU_SHIELD

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>
#include "usart.h"
//#include "lcd.h"
//#include "i2cmaster.h"
//#include "lm75.h"

//DDR PORT PIN for BTN & LED

#define BTN_DDR   DDRC
#define BTN_PORT  PORTC
#define BTN_PIN  PINC

#define LED_DDR   DDRD
#define LED_PORT  PORTD
#define LED_PIN   PIND

//Bit in registors for BTNs & LEDs

#define BTN_1 PC0
#define BTN_2 PC1
#define BTN_3 PC2
#define BTN_4 PC3

#define LED_1 PD4
#define LED_2 PD5
#define LED_3 PD6
#define LED_4 PD7




#endif //SDU_SHIELD
