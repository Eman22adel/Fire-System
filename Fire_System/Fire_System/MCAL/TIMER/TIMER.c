
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "avr/io.h"
#include "TIMER.h"

static void (*TIMER_PFTimer0OVF) (void) ;
static void (*TIMER_PFTimer0CTC) (void) ;

void TIMER0_voidTimer0OVFInit(void)
{
	/* Choose Normal mode */
	CLR_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);

	/* Enable Timer/Counter0 Overflow */
	SET_BIT(TIMSK , TOIE0);

	/* Initial Preload value ==> Desired Time = 1S */
	TCNT0 = 192 ;

	/* Select clock " CLK \ 8" ==> Prescaler */
	CLR_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLR_BIT(TCCR0 , CS02);

}

void TIMER0_voidTimer0CTCInit(void)
{
	/* Choose CTC mode */
	CLR_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);

	/* Enable Timer/Counter0 CTC AND OVF */
	SET_BIT(TIMSK , OCIE0);

	/*Initial Compare match value ==> OCR = 100 & Desired Time = 1S */
	OCR0 = 99 ;

	/*Select clock " CLK \ 8" ==> Prescaler */
	CLR_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLR_BIT(TCCR0 , CS02);

}
void TIMER0_voidTimer0OVFSetCallBack (void (*Copy_PFvoidTimer0OVF)(void))
{
	TIMER_PFTimer0OVF = Copy_PFvoidTimer0OVF ;
}

void TIMER0_voidTimer0CTCSetCallBack (void (*Copy_PFvoidTimer0CTC) (void))
{
	TIMER_PFTimer0CTC = Copy_PFvoidTimer0CTC ;
}

ISR (TIMER0_OVF_vect)
{
	static u16 Local_u8OVFCounter = 0 ;
	Local_u8OVFCounter ++ ;
	if (Local_u8OVFCounter == 3907)
	{
		/* Clear Local_u8OVFCounter */
		Local_u8OVFCounter = 0 ;
		/* Initial Preload value */
		TCNT0 = 192 ;
		/*Action*/
		TIMER_PFTimer0OVF() ;
	}
}
/*
ISR(TIMER0_COMP_vect)
{
	static u16 Local_u8OVCTCCounter = 0 ;
	Local_u8OVCTCCounter ++ ;
	if (Local_u8OVCTCCounter == 10000)
	{
		/*Action*/
		//TIMER_PFTimer0CTC() ;

		/* Clear Local_u8OVFCounter */
		//Local_u8OVCTCCounter = 0 ;
	//}
//}


