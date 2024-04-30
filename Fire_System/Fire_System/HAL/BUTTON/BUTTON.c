/*
 * BUTTON.c
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "BUTTON_Interface.h"


Button_Status Button_IsPressed(DIO_Pin_type pin){
     Button_Status Button;
     DIO_PinStatus_type Status = DIO_ReadStatus_CfgPin(pin);
	 switch(Status){
		 case  INPULL:
			 if(DIO_ReadPin(pin) == 0) {
				 Button = PRESSED;
			 }else{
				 Button = NOTPRESSED;
			 }
		 break;
	     case INFREE:
			 if(DIO_ReadPin(pin) == 1){
				 Button = PRESSED;
			 }else{
				 Button = NOTPRESSED;
			 }
		 break;
	     case OUTPUT:
	     break;
		 }
	 return Button;
}
