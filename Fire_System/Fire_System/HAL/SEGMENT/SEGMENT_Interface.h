/*
 * SEGMENT_Interface.h
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */

#ifndef HAL_SEGMENT_SEGMENT_INTERFACE_H_
#define HAL_SEGMENT_SEGMENT_INTERFACE_H_

#define SEG_DDR    DDRA
#define SEG_PORT   PORTA

/* MACROS FOR ONE SEG BCD*/
#define SEG_PIN1            DIO_PIN0
#define SEG_PIN2            DIO_PIN1
#define SEG_PIN3            DIO_PIN2
#define SEG_PIN4            DIO_PIN3

/* MACROS FOR TWO SEG BDC */
#define SEG_PIN5            DIO_PIN4
#define SEG_PIN6            DIO_PIN5
#define SEG_PIN7            DIO_PIN6
#define SEG_PIN8            DIO_PIN7

#define ZERO        0b00111111
#define ONE         0b00000110
#define TWO         0b01011011
#define THREE       0b01001111
#define FOUR        0b01100110
#define FIVE        0b01101101
#define SIX         0b01111101
#define SEVEN       0b00000111
#define EIGHT       0b01111111
#define NINE        0b01101111

/* MACRO FOR 7SEGMENT */
void SEG_INT(void);
void SEG1BCD_VoidSetVale(int start,int end);
void SEG2BCD_VoidSetVale(int start ,int end);


#endif /* HAL_SEGMENT_SEGMENT_INTERFACE_H_ */
