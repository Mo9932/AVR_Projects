/*
 * LCD.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mohamed
 */

#include<avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "LCD.h"


void LCD_VidSendCMD(u8 Copy_U8CMD)
{

	DIO_VidSetPinValue(LCD_CMD_PORT,RS,DIO_LOW);
	DIO_VidSetPinValue(LCD_CMD_PORT,RW,DIO_LOW);
	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_U8CMD);

	DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_HIGH);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_LOW);

}

void LCD_VidSendNumber(u32 Copy_U8Number)
{
	u32 local_remainder=0;
	u32 local_reversed=0;
	u32 tmp=Copy_U8Number;
	u8 count=0;

	while(Copy_U8Number!=0)
	{
		local_remainder=Copy_U8Number%10;
		local_reversed=(local_reversed*10)+local_remainder;
		Copy_U8Number/=10;
		count++;
	}

	while(count!=0)
	{
		LCD_VidSendChar((local_reversed%10)+'0');
		local_reversed/=10;
		count--;
	}
	if(tmp==0)
		LCD_VidSendChar('0');

}

void LCD_VidSendNumberFloat(f32 Copy_Value)
{
	u32 local_remainder=0;
	u32 local_reversed=0;

	u32 tmp_1=Copy_Value;
	f32 tmp=Copy_Value-tmp_1;

	u8 count=0,count1=3;

	u32 Copy_U8Number=tmp*1000;



	if(Copy_Value<1)
		LCD_VidSendChar('0');

	while(tmp_1!=0)
	{
		local_remainder=tmp_1%10;
		local_reversed=(local_reversed*10)+local_remainder;
		tmp_1/=10;
		count++;
	}
	while(count!=0)
	{
		LCD_VidSendChar((local_reversed%10)+'0');
		local_reversed/=10;
		count--;
	}

	LCD_VidSendChar('.');
	if(Copy_U8Number/100 ==0)
		LCD_VidSendChar('0');
	else if (Copy_U8Number/10 ==0)
			LCD_VidSendChar('0');

	while(Copy_U8Number!=0)
	{
		local_remainder=Copy_U8Number%10;
		local_reversed=(local_reversed*10)+local_remainder;
		Copy_U8Number/=10;
		count++;
	}
	while(count!=0)
	{
		LCD_VidSendChar((local_reversed%10)+'0');
		local_reversed/=10;
		count--;
	}

	if(tmp==0)
		LCD_VidSendChar('0');

}

void LCD_VidSendChar(u8 Copy_U8Char)
{

	DIO_VidSetPinValue(LCD_CMD_PORT,RS,DIO_HIGH);
	DIO_VidSetPinValue(LCD_CMD_PORT,RW,DIO_LOW);
	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_U8Char);

	DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_HIGH);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CMD_PORT,EN,DIO_LOW);

}

void LCD_VidInt(void)
{
	DIO_VidSetPortDirection(LCD_DATA_PORT,0xff);


	DIO_VidSetPinDirection(LCD_CMD_PORT,RS,DIO_OUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT,RW,DIO_OUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT,EN,DIO_OUT);
	_delay_ms(35);
	LCD_VidSendCMD(FUN_SET);
	_delay_ms(1);
	LCD_VidSendCMD(LCD_ON_OFF);
	_delay_ms(1);
	LCD_VidSendCMD(LCD_CLEAR);
	_delay_ms(2);
}

void LCD_VidSendString(u8 *Copy_u8Ptr)
{
	u8 local=0;
	while(Copy_u8Ptr[local] !='\0')
	{
		LCD_VidSendChar(Copy_u8Ptr[local]);
		local++;
	}

}

void LCD_VidSendLocation(u8 Copy_Line,u8 Copy_Char)
{
	switch(Copy_Line)
	{
		case LINE_1:LCD_VidSendCMD(0x80+Copy_Char);break;
		case LINE_2:LCD_VidSendCMD(0xc0+Copy_Char); break;
		case LINE_3:LCD_VidSendCMD(0x94+Copy_Char);break;
		case LINE_4:LCD_VidSendCMD(0xd4+Copy_Char); break;
	}
}

void LCD_VidSpecialChar(u8 Copy_GCRAMLoc,u8 *Copy_Char)
{
	LCD_VidSendCMD(0x40+8*(Copy_GCRAMLoc));
	for(u8 count=0;count<8;count++)
	{
		LCD_VidSendChar(Copy_Char[count]);
	}
}

void LCD_VidClear()
{
	LCD_VidSendCMD(LCD_CLEAR);
	_delay_ms(2);
}










