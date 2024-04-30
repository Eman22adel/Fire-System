/*
 * LED.c
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */


#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/io.h>
#include "LED_Interface.h"

void ON_LED(u8 PORT ,u8 PIN){
    if (PORT == PORT_A){
	SET_BIT(DDRA,PIN);
	SET_BIT(PORTA,PIN);
    }else if (PORT == PORT_B){
	SET_BIT(DDRB,PIN);
	SET_BIT(PORTB,PIN);
    }else if (PORT == PORT_C){
	SET_BIT(DDRC,PIN);
	SET_BIT(PORTC,PIN);
    }else if(PORT == PORT_D){
	SET_BIT(DDRD,PIN);
	SET_BIT(PORTD,PIN);
    }
}
void OFF_LED(u8 PORT ,u8 PIN){
	if (PORT == PORT_A){
		SET_BIT(DDRA,PIN);
		CLR_BIT(PORTA,PIN);
	    }else if (PORT == PORT_B){
		SET_BIT(DDRB,PIN);
		CLR_BIT(PORTB,PIN);
	    }else if (PORT == PORT_C){
		SET_BIT(DDRC,PIN);
		CLR_BIT(PORTC,PIN);
	    }else if(PORT == PORT_D){
		SET_BIT(DDRD,PIN);
		CLR_BIT(PORTD,PIN);
	    };
}
