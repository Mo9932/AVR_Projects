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

u8 Dino_0[7][8]= Dino;//First Frame

u8 Dino_1[7][8]= Dino_Move;//Second Frame

u8 Tree_0[8] = Tree;//Tree Shape


/*This Function Print the frames corresponding to the game state , delay and update the location of the tree
 * Calling by reference is used to access the global variables in main function */
void LCD_PrintDino(u8 *Copy_State,u8 *Location,u8 Animation_Delay)
{
	u8 count;
	static u8 Flag=0;
	static u8 Score=0;
	static u8 Iterator=1;
	LCD_VidSpecialChar(7,Tree_0);//Put the tree shape in CGRAM in this location
	if(*Copy_State==0)
	{
		Flag=0;
		for(count=0;count<7;count++)
		{
			LCD_VidSpecialChar(count,Dino_0[count]);//Put the Dino_0 shape in CGRAM in this location
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
		LCD_VidSendLocation(LINE_4,19-((*Location)-Iterator));//Go to the location before tree
		LCD_VidSendChar(0xfe);						   //Print NULL Character
		LCD_VidSendLocation(LINE_4,19-(*Location));	   //Go to the tree location
		LCD_VidSendChar(7);							   //Print the tree
		(*Location)++;								   //Update the tree location
		_delay_ms(Animation_Delay);
		/*if the tree is at the end of the screen reset the location to 0*/
		if((*Location)==20)
			(*Location)=0;
		for(count=0;count<7;count++)
		{
			LCD_VidSpecialChar(count,Dino_1[count]);//Put the Dino_1 shape in CGRAM in this location
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
		LCD_VidSendLocation(LINE_4,19-((*Location)-Iterator));
		LCD_VidSendChar(0xfe);
		LCD_VidSendLocation(LINE_4,19-(*Location));
		LCD_VidSendChar(7);
		(*Location)++;
		_delay_ms(Animation_Delay);
		if((*Location)==20)
			(*Location)=0;
	}
	/*If game state is 1 make the dino jump
	 * Print the first frame 2-Lines higher
	 * Wait 4 frames and reset the state to 0*/
	if(*Copy_State==1)
	{
		if(Flag==0)
		{
			for(count=0;count<7;count++)
			{
				if(count<4)
				{
					LCD_VidSendLocation(LINE_3,count+1);
					LCD_VidSendChar(0xfe);
				}
				if(count>3)
				{
					LCD_VidSendLocation(LINE_4,count-3);
					LCD_VidSendChar(0xfe);
				}
			}
		}
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
		/*the same as in state 0*/
		LCD_VidSendLocation(LINE_4,19-((*Location)-Iterator));
		LCD_VidSendChar(0xfe);
		LCD_VidSendLocation(LINE_4,19-(*Location));
		LCD_VidSendChar(7);
		(*Location)++;
		_delay_ms(Animation_Delay);


		Flag++;
		/*if the flag is 4 reset the flag and state*/
		if(Flag==4)
		{
			*Copy_State=0;
			Flag=0;
			for(count=0;count<7;count++)
			{
				if(count<4)
				{
					LCD_VidSendLocation(LINE_1,count+1);
					LCD_VidSendChar(0xfe);
				}
				if(count>3)
				{
					LCD_VidSendLocation(LINE_2,count-3);
					LCD_VidSendChar(0xfe);
				}
			}
		}
		if((*Location)==20)
		{
			(*Location)=0;
			Iterator++;
			if(Iterator==3)
				Iterator=1;
		}
		if((*Location)==18)
			Score++;
	}

	/*Game over state*/
	if(*Copy_State==2)
	{
		/*Clear the screen just one time*/
		if(Flag!=3)
		{
			LCD_VidClear();
		}

		LCD_VidSendLocation(LINE_2,4);
		LCD_VidSendString("Game Over");
		LCD_VidSendLocation(LINE_3,4);
		LCD_VidSendString("Your Score:");
		/*Print the score one time before resetting */
		if(Flag!=3)
			LCD_VidSendNumber(Score);

		LCD_VidSendLocation(LINE_4,2);
		LCD_VidSendString("Press * to Play");
		Flag=3; //Update the flag to print the score and clear the screen for one time
		Score=0;//Reset the score
		Iterator=1;
	}

	LCD_VidSendLocation(LINE_4,0);
	LCD_VidSendChar(0xfe);

}
