/*
 * SEGMENT.c
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/io.h>
#include <util/delay.h>
#include "SEGMENT_Interface.h"

void  SEG_INT(void){
	DIO_WritePort(SEG_DDR,0XFF);
}
void SEG1BCD_VoidSetVale(int start , int end){

	for(int i= start ; i<= 9 && i <= end ;i++){
		SEG_PORT = i;
	 _delay_ms(800);
	}
}
void SEG2BCD_VoidSetVale(int start , int end){
	for(int i = start ; i <= end;i++){
		SEG_PORT = i%10;
		SEG_PORT = PORTA | ((i/10)<<4);
		_delay_ms(500);
	}
}
