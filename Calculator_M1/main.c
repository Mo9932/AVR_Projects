/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Mohamed
 */


#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CALC.h"
#include "DIO.h"
#include "LCD.h"
#include "KeyPad.h"



void main()
{
	u8 flag=0;
	f32 NUM_1=0;
	f32 NUM_2=0;
	u8 OPP=0;
	u8 TMP=KPD_CHEK;
	u8 ANS=0;




	KPD_VidInt();
	LCD_VidInt();

	while(1)
	{

		TMP=KPD_u8PressedKey();
		if(TMP!=KPD_CHEK)
		{
			if(TMP=='c')
			{
				LCD_VidClear();
				NUM_1=0;
				NUM_2=0;

				flag=0;
			}
			else if(TMP!='L' && TMP!='S' && TMP!='C' && TMP!='e' && TMP!='T' && TMP!='=')
			{
				 if(flag!=1 && TMP!='-' && TMP!='c' && TMP!='+' && TMP!='*' && TMP!='/')
				{
					NUM_1=(NUM_1)*10+TMP;
					LCD_VidSendNumber(TMP);
					TMP=KPD_CHEK;
				}
				else if(TMP!='c' &&( TMP=='-' || TMP=='c' || TMP=='+' || TMP=='*' || TMP=='/'))
				{
					OPP=TMP;
					LCD_VidSendChar(OPP);
					TMP=KPD_CHEK;
					flag=1;
				}
				else if(TMP!='=')
				{
					NUM_2=(NUM_2)*10+TMP;
					LCD_VidSendNumber(TMP);
					TMP=KPD_CHEK;
				}
			}

			else if(TMP=='L' || TMP=='S' || TMP=='C' || TMP=='e' || TMP=='T')
			{
				switch(TMP)
				{
				case 'L':
					LCD_VidSendString("ln(");
					break;
				case 'S':
					LCD_VidSendString("sin(");
					break;
				case 'C':
					LCD_VidSendString("cos(");
					break;
				case 'e':
					LCD_VidSendString("e(");
					break;
				case 'T':
					LCD_VidSendString("tan(");
					break;
				}

				OPP=TMP;
				while(1)
				{
					TMP=KPD_u8PressedKey();
					if(TMP!=KPD_CHEK)
					{
						if(TMP!='-' && TMP!='c' && TMP!='+' && TMP!='*' && TMP!='/' && TMP!='=')
						{
							NUM_1=(NUM_1)*10+TMP;
							LCD_VidSendNumber(TMP);
							TMP=KPD_CHEK;
						}
					}
					if(TMP=='=')
					{
						ANS=TMP;
						LCD_VidSendChar(')');
						LCD_VidSendChar(ANS);
						TMP=KPD_CHEK;
						break;
					}
				}
			}

			else if(TMP=='=')
			{
				ANS=TMP;
				LCD_VidSendChar(ANS);
				TMP=KPD_CHEK;
				flag=0;
			}
		}

		if(ANS=='=')
			switch(OPP)
			{
				case '+':
					LCD_VidSendNumber(NUM_1+NUM_2);
					NUM_1=0;
					NUM_2=0;
					break;
				case '-':
					LCD_VidSendNumber(NUM_1-NUM_2);
					NUM_1=0;
					NUM_2=0;
					break;
				case '/':
					LCD_VidSendNumberFloat(NUM_1/NUM_2);
					NUM_1=0;
					NUM_2=0;
					break;
				case '*':
					LCD_VidSendNumber(NUM_1*NUM_2);
					NUM_1=0;
					NUM_2=0;
					break;
				case 'L':
					LCD_VidSendNumberFloat(Ln(NUM_1));
					NUM_1=0;
					break;
				case 'S':
					LCD_VidSendNumberFloat(Sin(NUM_1));
					NUM_1=0;
					break;
				case 'C':
					LCD_VidSendNumberFloat(Cos(NUM_1));
					NUM_1=0;
					break;
				case 'e':
					LCD_VidSendNumberFloat(Exp(NUM_1));
					NUM_1=0;
					break;
				case 'T':
					LCD_VidSendNumberFloat(Tan(NUM_1));
					NUM_1=0;
					break;
			}
		ANS=KPD_CHEK;
	}
}
