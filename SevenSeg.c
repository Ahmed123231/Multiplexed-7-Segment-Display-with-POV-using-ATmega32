/*
 * _7SEG_prog.c
 *
 * Created: 9/9/2024 8:36:29 AM
 *  Author: ahmed
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"



u8 sevenSegmentDigits[10] = {
	0b11000000, // 0: a, b, c, d, e, f (all on, g off)
	0b11111001, // 1: b, c (all others off)
	0b10100100, // 2: a, b, d, e, g
	0b10110000, // 3: a, b, c, d, g
	0b10011001, // 4: b, c, f, g
	0b10010010, // 5: a, c, d, f, g
	0b10000010, // 6: a, c, d, e, f, g
	0b11111000, // 7: a, b, c
	0b10000000, // 8: a, b, c, d, e, f, g (all on)
	0b10010000  // 9: a, b, c, d, f, g
};


void SevenSEG_voidInitt(void){

	DIO_voidSetPortDir(DIO_PORTD, 0x7F);  // Set PORTD as output for 7-segment
	DIO_voidSetPortVal(DIO_PORTD, 0x00);  // Clear PORTD

	// Set PD0, PD1, PD2 as output (for controlling the displays)
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN0, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN1, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, DIO_PIN2, OUTPUT);
	
	
	
}










void PrintSEG1(u8 Start_num){
	
	DIO_voidSetPinVal(DIO_PORTC, DIO_PIN0, HIGH);
	DIO_voidSetPortVal(DIO_PORTD, sevenSegmentDigits[Start_num]);
	
}

void Disable_SEG1(void){
	DIO_voidSetPinVal(DIO_PORTC, DIO_PIN0, LOW);
}


void PrintSEG2(u8 Start_num) {
	
	DIO_voidSetPinVal(DIO_PORTC, DIO_PIN1, HIGH);
	
	
	DIO_voidSetPortVal(DIO_PORTD, sevenSegmentDigits[Start_num]);
	
	
}

void Disable_SEG2(void){
	DIO_voidSetPinVal(DIO_PORTC, DIO_PIN1, LOW);
}

void PrintSEG3(u8 Start_num){
	
	DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2, HIGH);
	
	
	DIO_voidSetPortVal(DIO_PORTD, sevenSegmentDigits[Start_num]);
	
	
}

void Disable_SEG3(void){
	
	DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2, LOW);
	
}