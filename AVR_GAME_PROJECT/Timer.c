/*
 * Timer.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Mohamed
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include<avr/interrupt.h>

#include"TIMER.h"

static void (*TIM_FUN[2])(void);

void TIM0_VidInt()
{
#if Mode==OVF
	/*OVF MODE*/
	CLEAR_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	/*OVF interrupt*/
	SET_BIT(TIMSK,TOIE0);
	/*Pre load*/
	TCNT0=192;
	/*CLK /8 */
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);

#elif Mode==CTC
	/*CTC MODE*/
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*Compare Match interrupt*/
	SET_BIT(TIMSK,OCIE0);
	/*CTC value*/
	OCR0=250;
	/*CLK /8 */
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
#endif

}

void TIM0_SetCallBack(void(*Copy_Tim0)(void),u8 Copy_Mode)
{
	TIM_FUN[Copy_Mode]=Copy_Tim0;
}

ISR(TIMER0_OVF_vect)
{
	static u16 counter=0;
	counter++;

	if(counter==800)
	{
		counter=0;
		TCNT0=192;
		TIM_FUN[0]();
	}
}


ISR(TIMER0_COMP_vect)
{
	static u16 count=0;
	count++;
	if(count==800)
	{
		count=0;
		TIM_FUN[1]();
	}

}
