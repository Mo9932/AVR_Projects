/*
 * TIMER.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mohamed
 */

#ifndef TIMER_H_
#define TIMER_H_

#define OVF 0
#define CTC 1
#define Mode CTC

void TIM0_VidInt();
void TIM0_SetCallBack(void(*Copy_Tim0)(void),u8 Copy_Mode);

#endif /* TIMER_H_ */
