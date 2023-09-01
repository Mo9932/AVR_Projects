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

u8 Dino_C[7][8]= Dino;

void LCD_PrintDino(void)
{
	u8 count;
	for(count=0;count<7;count++)
	{
		LCD_VidSpecialChar(count,Dino_C[count]);
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
}
