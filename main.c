/*
 * 7SEG_TASK.c
 *
 * Created: 9/8/2024 5:22:06 PM
 * Author : ahmed
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "SevenSeg.h"
#define F_CPU 16000000UL
#include <util/delay.h>





int main(void)
{

	SevenSEG_voidInitt();
	while (1) {
		
		
		
		for (u8 hundreds = 0; hundreds < 10; hundreds++) {
			for (u8 tens = 0; tens < 10; tens++) {
				for (u8 ones = 0; ones < 10; ones++) {
					for (u8 i = 0; i < 100; i++) {  
						
						
						PrintSEG1(ones);
						_delay_us(300);  
						Disable_SEG1();
						
						
						PrintSEG2(tens);
						_delay_us(300);   
						Disable_SEG2();

						
						PrintSEG3(hundreds);
						_delay_us(300); 
						Disable_SEG3();
					}
					
					//_delay_ms(1);
				}
			}
		}
	}
    
}
