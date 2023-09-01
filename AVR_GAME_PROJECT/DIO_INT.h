/*
 * INTERRUPT.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mohamed
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

/***************************************************************************/
//Interrupt Mode
#define LOW_LEVEL			0
#define LOGICAL_CHANGE	    1
#define FALLING_EDGE		2
#define RISING_EDGE			3
/***************************************************************************/

/***************************************************************************/
//Global Interrupt Enable GIE
#define ENABLE	0
#define DISABLE	1
/***************************************************************************/


/***************************************************************************/
//Interrupt Vector
#define INT_0 		0
#define INT_1		1
#define INT_2		2
/***************************************************************************/


/***************************************************************************/
//Global Interrupt Enable PIN
#define I_BIT	    7
/***************************************************************************/

/***************************************************************************/
//Chose Mode
#define MODE	 FALLING_EDGE

#define GIE		ENABLE

#define INT INT_0
/***************************************************************************/


void INT_GIE();
void INT_Int();
void EXT_INTADD(u8 index,void(*Copy_add)(void));


#endif /* INTERRUPT_H_ */
