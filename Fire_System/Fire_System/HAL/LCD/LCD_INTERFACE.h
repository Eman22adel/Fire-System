/*
 * LCD_INTERFACE.h
 *
 *  Created on: Sep 3, 2023
 *      Author: eman adel
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

void LCD_Init();
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8 * str);
void LCD_WriteNumber(s32 num);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);
void LCD_SetCursor(u8 line,u8 cell);
void LCD_Clear(void);
void LCD_ClearLoc(u8 line ,u8 cell,u8 num);

u8 LCD_StrLength(s32 * str);
//TO WRITE DATA IN CGRAM IF YOU NEED PRINT CALL WRITEDATA(loc)

void LCD_CustomChar(u8 loc,u8*pattern);


/*private*/
void WriteData(u8 data);
void WriteIns(u8 ins);
void LCD_EnClock(void);
void LCD_SetData(u8 data);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
