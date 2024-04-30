/*
 * FIRE_SYSTEM.h
 *
 *  Created on: Sep 7, 2023
 *      Author: eman adel
 */

#ifndef APP_FIRE_SYSTEM_H_
#define APP_FIRE_SYSTEM_H_


#define RELAY PINB_1
/********************* fire_interface ******************/

void FIRE_Init(void);
void FIRE_Runnable(void);

typedef enum{
	FINE,
	HEAT,
	FIRE
}FIRE_state_type;


/********************* static **************************/
static FIRE_state_type  state = FINE;




static void fine_state(void);
static void heat_state(void);
static void fire_state(void);


void FIRE_INIT(void);

int FIRE_CHECK_PASS(void);

void FIRE_SYSTEM(int);

void FireSystem_CaseFine(u16 temp);

void FireSystem_CaseHeat(u16 temp);

void FireSystem_CaseFire(u16 temp);

#endif /* APP_FIRE_SYSTEM_H_ */
