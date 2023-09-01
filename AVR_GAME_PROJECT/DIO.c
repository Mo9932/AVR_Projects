#include<avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"


void DIO_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	if(Copy_u8Direction==1)
	{
		switch(Copy_u8Port)
		{
			case 0: SET_BIT(DDRA,Copy_u8Pin);break;
			case 1: SET_BIT(DDRB,Copy_u8Pin);break;
			case 2: SET_BIT(DDRC,Copy_u8Pin);break;
			case 3: SET_BIT(DDRD,Copy_u8Pin);break;
		}
	}
	else if(Copy_u8Direction==0)
	{
		switch(Copy_u8Port)
		{
			case 0: CLEAR_BIT(DDRA,Copy_u8Pin);break;
			case 1: CLEAR_BIT(DDRB,Copy_u8Pin);break;
			case 2: CLEAR_BIT(DDRC,Copy_u8Pin);break;
			case 3: CLEAR_BIT(DDRD,Copy_u8Pin);break;
		}
	}
}

void DIO_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	if(Copy_u8Value==1)
	{
		switch(Copy_u8Port)
		{
			case 0: SET_BIT(PORTA,Copy_u8Pin);break;
			case 1: SET_BIT(PORTB,Copy_u8Pin);break;
			case 2: SET_BIT(PORTC,Copy_u8Pin);break;
			case 3: SET_BIT(PORTD,Copy_u8Pin);break;
		}
	}
	else if(Copy_u8Value==0)
	{
		switch(Copy_u8Port)
		{
			case 0: CLEAR_BIT(PORTA,Copy_u8Pin);break;
			case 1: CLEAR_BIT(PORTB,Copy_u8Pin);break;
			case 2: CLEAR_BIT(PORTC,Copy_u8Pin);break;
			case 3: CLEAR_BIT(PORTD,Copy_u8Pin);break;
		}
	}
}

void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction)
{
	switch(Copy_u8Port)
	{
		case 0: DDRA=Copy_u8Direction;break;
		case 1: DDRB=Copy_u8Direction;break;
		case 2: DDRC=Copy_u8Direction;break;
		case 3: DDRD=Copy_u8Direction;break;
	}
}

void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case 0: PORTA=Copy_u8Value;break;
		case 1: PORTB=Copy_u8Value;break;
		case 2: PORTC=Copy_u8Value;break;
		case 3: PORTD=Copy_u8Value;break;
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 tmp;
	
	switch(Copy_u8Port)
	{
		case 0: tmp = GET_BIT(PINA,Copy_u8Pin);break;
		case 1: tmp = GET_BIT(PINB,Copy_u8Pin);break;
		case 2: tmp = GET_BIT(PINC,Copy_u8Pin);break;
		case 3: tmp = GET_BIT(PIND,Copy_u8Pin);break;
	}
	return tmp;
}

void DIO_VidTogglePin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case 0: TOGGLE_BIT(PORTA,Copy_u8Pin);break;
		case 1: TOGGLE_BIT(PORTB,Copy_u8Pin);break;
		case 2: TOGGLE_BIT(PORTC,Copy_u8Pin);break;
		case 3: TOGGLE_BIT(PORTD,Copy_u8Pin);break;
	}
}

