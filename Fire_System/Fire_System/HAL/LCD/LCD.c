/*
 * LCD.c
 *
 *  Created on: Sep 3, 2023
 *      Author: eman adel
 */

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"
#include "LCD_INTERFACE.h"
#include "LCD_CFG.h"

/*TO DO ANY PULE AFTER DATA*/
void LCD_EnClock(){
		DIO_WritePin(EN,HIGH);
		_delay_ms(1);
		DIO_WritePin(EN,LOW);
		_delay_ms(1);
}

#if LCD_MODE== _8_BIT

	/*LCD INST*/
	void LCD_Init(){
	_delay_ms(50);
	WriteIns(0x38);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	WriteIns(0x01);//clear screen NEED 2 MS DELAY
	_delay_ms(1);
	WriteIns(0x06);// increment DDRAM address, no shift
	}
	/*HELP TO SET DATA FOR ANY PIN*/
	static void LCD_SetData(u8 data){
	    for (u8 i=0;i<7;i++)
	    {
			DIO_WritePin(LCD_8BITArray[i],(DIO_PinVoltage_type)READ_BIT(data,i));
	    }
   }
	/*PRIVATE TO WRITE ANY INSTRUCTION*/
	void WriteIns(u8 ins){
		//RS FOR INST 0 AND FOR SEND DATA 1
		DIO_WritePin(RS,LOW);
		//INS == INSTRUCTION MUST SEND
		LCD_SetData(ins);
		//enable import to make micro in LCD received data send
		LCD_EnClock();
	}
	/*PRIVATE TO WRITE ANY DATA*/
	void WriteData(u8 data){
		//RS FOR INST 0 AND FOR SEND DATA 1
		DIO_WritePin(RS,HIGH);
		//SEND DATA
		LCD_SetData(data);
		//enable import to make micro in LCD received data send
		LCD_EnClock();
	}
	///// END

#elif LCD_MODE ==_4_BIT

	/*LCD INST*/
	void LCD_Init(){
		_delay_ms(50);
		//INS FOR 4 BIT DIFFRENCE IN THIS LINE MUST SEND 02 THEN 28
		WriteIns(0x02);
		WriteIns(0x28);//5*7 2 lines
		WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
		WriteIns(0x01);//clear screen
		_delay_ms(1);
		WriteIns(0x06);// increment DDRAM address, NO SHIFT , WRITE ENGLISH
		//WriteIns(0x04);// TO WRITE ARABIC
	}
	/*HELP TO SET DATA FOR ANY PIN*/
	void  LCD_SetData(u8 data){
		for (u8 i=0;i<4;i++)
		{
			DIO_WritePin(LCD_4BITArray[i],(DIO_PinVoltage_type)READ_BIT(data,i));
		}
	}
	/*PRIVATE TO WRITE ANY INSTRUCTION*/
	void WriteIns(u8 ins){
		//RS FOR INST 0 AND FOR SEND DATA 1
		DIO_WritePin(RS,LOW);
		//INS == INSTRUCTION MUST SEND
		LCD_SetData(ins>>4);
		//enable import to make micro in LCD received data send
		LCD_EnClock();
		LCD_SetData(ins);
		LCD_EnClock();
	}
	/*PRIVATE TO WRITE ANY DATA*/
	void WriteData(u8 data){
		//RS FOR INST 0 AND FOR SEND DATA 1
		DIO_WritePin(RS,HIGH);
		//SEND DATA
		LCD_SetData(data>>4);
		//enable import to make micro in LCD received data send
		LCD_EnClock();
		LCD_SetData(data);
		LCD_EnClock();
	}
	///// END

#endif


/*MUST SEND ADDRESS IN DDRAM AFTER USE THIS FUNCTION*/
void LCD_WriteChar(u8 ch){
	WriteData(ch);
}


/*#define   NULLPTR  ((void*)0)*/
void LCD_WriteString(u8 str[])
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}

}

// WRITE DDRAM
void LCD_SetCursor(u8 line,u8 cell)
{
	if (line==0)
	{
		WriteIns(0x80|cell); // 0x80 include necessary to write in DDRAM
	}
	else if (line ==1)
	{
		//LINE TWO START FROM 0X40
		WriteIns(0x80+0x40+cell); //OR CAN DO PROBLEM IF TWO ONE THE SAME POSITION
	}

}

void LCD_Clear(void)
{
	//0X01 INST CLEAR
	WriteIns(0x01);
	//MUST WAIT DELAY FOR THIS INSTRUCTION
	_delay_ms(1);
}

void LCD_WriteNumber(s32 num)
{
	u8 str[50],i=0,j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		num=num*(-1);
		LCD_WriteChar('-');
	}

	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	/*from I=J DUE IT STRING IS REVERSE*/
	for (j=i;j>0;j--)
	{
		LCD_WriteChar(str[j-1]);
	}

}


void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar(READ_BIT(num,i)+'0');
	}
}

void LCD_ClearLoc(u8 line ,u8 cell,u8 num)
{
	u8 i;
	LCD_SetCursor(line,cell);
	for (i=0;i<num;i++)
	{
		LCD_WriteChar(' ');
	}

}

void LCD_WriteNumber_4D(u16 num)
{
	//LCD_WriteChar(((num%100000)/10000)+'0');
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

//WRITE IN CGRAM BUT NOT PRINT IF YOU NEED PRINT CALL WriteChar(loc)
void LCD_CustomChar(u8 loc,u8*pattern)
{
	WriteIns(0x40+loc*8);
	for(u8 i=0;i<8;i++)
	{
		WriteData(pattern[i]);
	}
	// IMPORTENT TO RETRUN CURSOR TO DDRAM
	WriteIns(0x80);
}

u8 LCD_StrLength(s32* str){
	u8 i=0;
	while (str[i])
	{
		i++;
	}
	return i;
}

void LCD_WriteHex(u8 num){
	s8 i;
	u8 str[8];
	u8 c1,c2;
	for (i=7;i>=0;i--)
	{
		str[i]=(READ_BIT(num,i));
	}
	c1=str[4]*1+str[5]*2+str[6]*4+str[7]*8;
	c2=str[0]*1+str[1]*2+str[2]*4+str[3]*8;
	(c1 >= 10)?LCD_WriteChar(c1+55):LCD_WriteNumber(c1);
	(c2 >= 10)?LCD_WriteChar(c2+55):LCD_WriteNumber(c2);
}
