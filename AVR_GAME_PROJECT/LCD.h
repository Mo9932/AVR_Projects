/*
 * LCD.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mohamed
 */

#ifndef LCD_H_
#define LCD_H_

#define LCD_DATA_PORT PORT_A

#define LCD_CMD_PORT PORT_B

#define RS PIN_5
#define RW PIN_6
#define EN PIN_7


#define LINE_1 0
#define LINE_2 1
#define LINE_3 3
#define LINE_4 4

#define FUN_SET 0b00111100
#define LCD_ON_OFF 0b00001100
#define LCD_CLEAR 0b00000001

void LCD_VidSendCMD(u8 Copy_U8CMD);
void LCD_VidSendNumber(u32 Copy_U8Number);
void LCD_VidSendNumberFloat(f32 Copy_Value);
void LCD_VidSendChar(u8 Copy_U8Char);
void LCD_VidSendLocation(u8 Copy_Line,u8 Copy_Char);
void LCD_VidSendString(u8 *Copy_u8Ptr);
void LCD_VidSpecialChar(u8 Copy_GCRAMLoc,u8 *Copy_Char);
void LCD_VidClear();

void LCD_VidInt(void);

#endif /* LCD_H_ */
