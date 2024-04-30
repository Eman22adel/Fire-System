/*
 * FIRE_SYSTEM.c
 *
 *  Created on: Sep 6, 2023
 *      Author: eman adel
 */

#include "../SERVICES/BIT_MATH.h"
#include "../SERVICES/STD_TYPES.h"
#include <avr/io.h>
#include "util/delay.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KEYPAD_Interface.h"
#include "../HAL/SENSOR/SENSOR_Inerface.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/TIMER/TIMER.h"
#include "FIRE_SYSTEM.h"

u16 temp;
u8 press;
char password[5];
char check[5];
static u32 count = 0;

void FIRE_INIT(void){

	u8 key ='0';
	int max = 0;
	LCD_SetCursor(0,0);
	LCD_WriteString("FIRE SYSTEM");
	_delay_ms(200);

	for(signed int x = 15 ; x >= 0 ; x--){
		LCD_SetCursor(0,x);
		LCD_WriteChar(' ');
		_delay_ms(40);
	}
	LCD_SetCursor(0,0);
	LCD_WriteString("ENTER PASSWORD");

	LCD_SetCursor(1,0);
	while(max < 5){

		key = KEYPAD_GetKey();
		if(key == '\n'){
			break;

		}else{
			if(key != 'N'){
				LCD_WriteChar(key);
				password[max] = key;
				max++;
			}
		}
	}
	_delay_ms(100);
	LCD_Clear();
}


int FIRE_CHECK_PASS(void){
	int i = 0,flag=1,flag2=0;
	int max = 0;
	char key;
	LCD_Clear();
	LCD_WriteString("enter password");
	LCD_SetCursor(1,0);

	while(max < 5){
		key = KEYPAD_GetKey();

		if(key != 'N'){
			LCD_WriteChar(key);
			check[max]= key;
			max++;
			flag2=1;
		}else{
			if(flag2 == 0){
				_delay_ms(1);
				count++;
				if(count > 8000){
					UART_Send('8');
					count = 0;
					break;
				}
			}
		}
	}
	LCD_SetCursor(0,0);
	for(i = 0 ; i < 4 ;i++){
		if(check[i] != password [i]){
			LCD_WriteChar(check[i]);
			LCD_WriteChar(password[i]);
			flag = 0;
			return flag;
		}
	}
	return flag;
}


void FIRE_SYSTEM(int check){
	if(check == 0){
		LCD_Clear();
		LCD_WriteString("NOT CORRECT");
		_delay_ms(700);
		LCD_Clear();
	}else{
		LCD_Clear();
		LCD_WriteString("CORRECT PASSWORD");
		_delay_ms(700);
	}
	LCD_Clear();
}


void FIRE_Runnable(void)
{
	switch(state)
	{
		case FINE:
		fine_state();
		break;

		case HEAT:
		heat_state();
		break;

		case FIRE:
		fire_state();
		break;
	}
}


static void fine_state(void)
{
	u16 temp;
	LCD_Clear();
	while(1)
	{
		LCD_SetCursor(0,0);
		LCD_WriteString("Temp  : ");
		temp = Temp_Read();
		LCD_WriteNumber(temp/10);
		LCD_WriteChar('.');
		LCD_WriteNumber(temp%10);
		LCD_WriteString("  C  ");

		LCD_SetCursor(1,0);
		LCD_WriteString("State : ");
		LCD_WriteString("Fine    ");
		if((temp/10) >= 45)
		{
			state = HEAT;
			break;
		}
		_delay_ms(700);
	}
}


static void heat_state(void)
{
	u16 temp;
	LCD_Clear();
	while(1)
	{
		temp = Temp_Read();
		LCD_SetCursor(0,0);
		LCD_WriteString("Temp  : ");
		LCD_WriteNumber(temp/10);
		LCD_WriteChar('.');
		LCD_WriteNumber(temp%10);
		LCD_WriteString("  C  ");
		LCD_SetCursor(1,0);
		LCD_WriteString("State : ");
		LCD_WriteString("Heat    ");
		if((temp/10) >= 60)
		{
			state = FIRE;
			break;
		}
		if((temp/10) < 45){
			state = FINE;
			break;
		}
	}
}


static void fire_state(void)
{
	u16 temp;
	LCD_Clear();
	while(1)
	{
		DIO_WritePin(RELAY,HIGH);
		temp = Temp_Read();
		LCD_SetCursor(0,0);
		LCD_WriteString("Temp  : ");
		LCD_WriteNumber(temp/10);
		LCD_WriteChar('.');
		LCD_WriteNumber(temp%10);
		LCD_WriteString("  C  ");
		LCD_SetCursor(1,0);
		LCD_WriteString("State : ");
		LCD_WriteString("Fire    ");
		if(FIRE_CHECK_PASS() == 1 ){
			FIRE_SYSTEM(1);
			if((temp/10) < 60)
			{
				state = HEAT;
				DIO_WritePin(RELAY,LOW);
			}
			if((temp/10) < 45){
				state = FINE;
				DIO_WritePin(RELAY,LOW);
			}
			break;
		}else{
			FIRE_SYSTEM(0);
		}

	}
}
