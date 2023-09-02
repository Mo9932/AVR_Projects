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
u8 Location=0;

void Set_State(void);
int main(void)
{
	u8 Key=KPD_CHEK;
	DIO_VidSetPinDirection(PORT_D,PIN_3,DIO_IN);
	DIO_VidSetPinValue(PORT_D,PIN_2,DIO_HIGH);
	LCD_VidInt();
	KPD_VidInt();
	INT_Int();										//Enable the interrupt
	EXT_INTADD(INT_0,Set_State);					//If the interrupt flag is high call the state function
    INT_GIE();										//Enable the global interrupt flag

	while(1)
	{
		/*To check if the Dino is above the tree and not jumping*/
		if((Location==18 || Location==17 || Location==16 || Location==15)&& State==0)
		{
			State=2;
			/*Disable the interrupt
			 * If the user tried to make the dino jump the state will not be updated*/
			CLEAR_BIT(SREG,7);
		}
		else
		{
			LCD_PrintDino(&State,&Location,80);//Take and update game state ,Update tree location and take the animation delay
		}

		if(State==2)
		{
			Key=KPD_u8PressedKey();
			while(Key!=KPD_CHEK)
			{
				if(Key=='c')
				{
					State=0;
					Location=0;
					LCD_VidClear();
					INT_GIE();
					Key=KPD_CHEK;
				}
			}
		}
	}
}

/*Update the state to make the dino jump*/
void Set_State(void)
{
	State=1;
}


