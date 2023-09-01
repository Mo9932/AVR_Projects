/*
 * main.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Mohamed
 */

#include<avr/io.h>
#include <avr/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Special.h"
#include "TIMER.h"
#include "DIO_INT.h"

u8 State=0;

void Set_State(void);
int main(void)
{
	u8 Key=KPD_CHEK;
	DIO_VidSetPinDirection(PORT_D,PIN_3,DIO_IN);
	DIO_VidSetPinValue(PORT_D,PIN_2,DIO_HIGH);
	LCD_VidInt();
	KPD_VidInt();
	INT_Int();
	EXT_INTADD(INT_0,Set_State);
    INT_GIE();

	while(1)
	{
		LCD_PrintDino(&State);
	}
}

void Set_State(void)
{
	State=1;
}


