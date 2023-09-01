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


int main(void)
{
	LCD_VidInt();
	KPD_VidInt();

	while(1)
	{
		LCD_PrintDino();
	}
}



