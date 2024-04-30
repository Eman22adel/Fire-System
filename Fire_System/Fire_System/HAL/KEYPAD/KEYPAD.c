/*
 * KEYPAD.c
 *
 *  Created on: Sep 6, 2023
 *      Author: eman adel
 */

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "avr/io.h"
#include "util/delay.h"
#define   PRO_CFG1 1
#include "KEYPAD_CFG.h"
#include "KEYPAD_Interface.h"



//FIRST STEP SET HIGH FOR ALL PIN
void KEYPAD_Init(){
	for (u8 row = 0; row < ROWS;row++)
	{
		DIO_WritePin(KPD_ROWS[row],HIGH);
	}
}

u8 KEYPAD_GetKey(){
	u8 row,col,key='N';

	for(row=0;row<ROWS;row++){
		DIO_WritePin(KPD_ROWS[row],LOW);
		for(col=0;col<COLS;col++){
			if(DIO_ReadPin(KPD_COLS[col]) == 0){
				key = Key_Array[row][col];
				while(DIO_ReadPin(KPD_COLS[col]) == LOW);
			}
		}
		DIO_WritePin(KPD_ROWS[row],HIGH);
	}
	return key;
}

