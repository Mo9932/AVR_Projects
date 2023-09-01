/*
 * KeyPad.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mohamed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


# define KPD_PORT PORT_C

#define KPD_R0_PIN PIN_0
#define KPD_R1_PIN PIN_1
#define KPD_R2_PIN PIN_2
#define KPD_R3_PIN PIN_3

#define KPD_C0_PIN PIN_4
#define KPD_C1_PIN PIN_5
#define KPD_C2_PIN PIN_6


#define KPD_CHEK 0xff

#define KPD_KEYS {  {7,8,9},\
					{4,5,6},\
					{1,2,3},\
					{'c',0,'='}}

void KPD_VidInt();
u8 KPD_u8PressedKey();

#endif /* KEYPAD_H_ */
