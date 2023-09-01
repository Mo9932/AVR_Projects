/*
 * Special.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Mohamed
 */

#include<avr/io.h>
#include <avr/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "LCD.h"
#include "Special.h"

u8 Dino_0[7][8]= Dino;

u8 Dino_1[7][8]= Dino_Move;

void LCD_PrintDino(u8 *Copy_State)
{
	u8 count;
	if(*Copy_State==0)
	{
		for(count=0;count<7;count++)
		{
			LCD_VidSpecialChar(count,Dino_0[count]);
		}
		for(count=0;count<7;count++)
		{
			if(count<4)
			{
				LCD_VidSendLocation(LINE_3,count+1);
				LCD_VidSendChar(count);
			}
			if(count>3)
			{
				LCD_VidSendLocation(LINE_4,count-3);
				LCD_VidSendChar(count);
			}
		}
		_delay_ms(200);
		for(count=0;count<7;count++)
		{
			LCD_VidSpecialChar(count,Dino_1[count]);
		}
		for(count=0;count<7;count++)
		{
			if(count<4)
			{
				LCD_VidSendLocation(LINE_3,count+1);
				LCD_VidSendChar(count);
			}
			if(count>3)
			{
				LCD_VidSendLocation(LINE_4,count-3);
				LCD_VidSendChar(count);
			}
		}
		_delay_ms(200);
	}
	if(*Copy_State==1)
	{
		LCD_VidClear();
		for(count=0;count<7;count++)
		{
			LCD_VidSpecialChar(count,Dino_0[count]);
		}
		for(count=0;count<7;count++)
		{
			if(count<4)
			{
				LCD_VidSendLocation(LINE_1,count+1);
				LCD_VidSendChar(count);
			}
			if(count>3)
			{
				LCD_VidSendLocation(LINE_2,count-3);
				LCD_VidSendChar(count);
			}
		}
		_delay_ms(200);
		LCD_VidClear();
		*Copy_State=0;
	}

}
