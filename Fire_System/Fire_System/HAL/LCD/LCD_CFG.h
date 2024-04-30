/*
 * LCD_CFG.h
 *
 *  Created on: Sep 3, 2023
 *      Author: eman adel
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

/*MUST PUT IN PRIVATE*/
#define _4_BIT   0
#define _8_BIT   1

/*CHANGE MODE _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT


// HELP TO CHANGE CONNECT
#define  RS PINC_0
#define  EN PINC_1


/*IF _8_BIT SET POSITION OF 8PIN*/
const DIO_Pin_type LCD_8BITArray[]={
	PINB_0,
	PINB_1,
	PINB_2,
	PINB_3,
	PINB_4,
	PINB_5,
	PINB_6,
	PINB_7
};

/*IF _4_BIT SET POSITION OF 4PIN*/
const DIO_Pin_type LCD_4BITArray[]={
	PINC_2,
	PINC_3,
	PINC_4,
	PINC_5
};

#endif /* HAL_LCD_LCD_CFG_H_ */
