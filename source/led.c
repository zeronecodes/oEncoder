#include "reg_map.h"
#include "led.h"

void init_led(void) {
	DDRB = DDRB | 0x3F;
}

void on_led1() {
	PORTB |= 0x01;
}

void off_led1() {
	PORTB &= ~0x01;
}

void on_led2() {
	PORTB |= 0x02;
}

void off_led2() {
	PORTB &= ~0x02;
}

void on_led3() {
	PORTB |= 0x04;
}

void off_led3() {
	PORTB &= ~0x04;
}

void on_led4() {
	PORTB |= 0x08;
}

void off_led4() {
	PORTB &= ~0x08;
}

void on_led5() {
	PORTB |= 0x10;
}

void off_led5() {
	PORTB &= ~0x10;
}

void on_led6() {
	PORTB |= 0x20;
}

void off_led6() {
	PORTB &= ~0x20;
}