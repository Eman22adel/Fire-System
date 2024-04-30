/*
 * KEYPAD_CFG.h
 *
 *  Created on: Sep 6, 2023
 *      Author: eman adel
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

#define  ROWS   4
#define  COLS   3

	#ifdef PRO_CFG1
	const	DIO_Pin_type KPD_COLS[3] = {PINB_0,PIND_2,PIND_3};
	const	DIO_Pin_type KPD_ROWS[4] = {PIND_4,PIND_5,PIND_6,PIND_7};
		/*CHANGE DRAW*/
	u8 Key_Array[ROWS][COLS] = 			{{'1','2','3'},
										{'4','5','6'},
										{'7','8','9'},
										{'*','0','#'}};
	#endif

#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
