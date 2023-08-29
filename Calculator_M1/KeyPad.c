
#include <avr/io.h>
#include <avr/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "KeyPad.h"


u8 KPD_u8Keys[4][6]=KPD_KEYS;

u8 KPD_u8RowPins[4]={KPD_R0_PIN,KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN};

u8 KPD_u8ColPins[6]={KPD_C0_PIN,KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN,KPD_C4_PIN,KPD_C5_PIN};



void KPD_VidInt()
{
	DIO_VidSetPortDirection(KPD_PORT_0,0x0f);
	DIO_VidSetPortValue(KPD_PORT_0,0xff);
	DIO_VidSetPinDirection(KPD_PORT_1,PIN_0,DIO_IN);
	DIO_VidSetPinDirection(KPD_PORT_1,PIN_1,DIO_IN);
	DIO_VidSetPortValue(KPD_PORT_1,0xff);
}

u8 KPD_u8PressedKey()
{
	u8 count_R, count_C,Pressed,Returned=KPD_CHEK,Flag=0;
	for(count_R=0;count_R<4;count_R++)
	{
		DIO_VidSetPinValue(KPD_PORT_0,KPD_u8RowPins[count_R],DIO_LOW);
		for(count_C=0;count_C<6;count_C++)
		{
			if(count_C<4)
			{
				Pressed=DIO_u8GetPinValue(KPD_PORT_0,KPD_u8ColPins[count_C]);
				if(Pressed==DIO_LOW)
				{
					_delay_ms(20);
					while(Pressed==DIO_LOW)
						Pressed=DIO_u8GetPinValue(KPD_PORT_0,KPD_u8ColPins[count_C]);

					Returned = KPD_u8Keys[count_R][count_C];
					Flag=1;
					break;
				}
			}
			else
			{
				Pressed=DIO_u8GetPinValue(KPD_PORT_1,KPD_u8ColPins[count_C]);
				if(Pressed==DIO_LOW)
				{
					_delay_ms(20);
					while(Pressed==DIO_LOW)
						Pressed=DIO_u8GetPinValue(KPD_PORT_1,KPD_u8ColPins[count_C]);

					Returned = KPD_u8Keys[count_R][count_C];
					Flag=1;
					break;
				}
			}

		}
		DIO_VidSetPinValue(KPD_PORT_0,KPD_u8RowPins[count_R],DIO_HIGH);
		if(Flag==1)
			break;
	}
	return Returned;
}

