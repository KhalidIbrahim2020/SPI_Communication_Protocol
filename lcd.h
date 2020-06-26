/*
 * lcd.h
 *
 * Created: 5/29/2020 3:20:29 AM
 *  Author:Khalid Ibrahim
 */ 


#ifndef LCD_H_
#define LCD_H_


#ifndef F_CPU
#define F_CPU	8000000UL
#endif

#include	"avr/io.h"
#include	"data_types.h"
#include	"bit_handle.h"
#include	"util/delay.h"

#define LCD_DATA_PORT		PORTC
#define LCD_DATA_DDR		DDRC

#define LCD_CTRL_PORT		PORTB
#define LCD_CTRL_DDR		DDRB

#define	LCD_RS				PB5
#define	LCD_EN				PB7

#define CMD_CLEAR			0x01
#define CMD_ENTRY_MODE		0x06
#define CMD_DISP_ON			0x0C
#define CMD_CFG				0x38

/* x (1-2 line), y (1-16) cols */
void LCD_Init(void);
void LCD_Clear(void);
void LCD_DispChar(INT8U u8Char);
void LCD_DispStr(INT8U* pu8Str);
void LCD_DispCharXY(INT8U x, INT8U y, INT8U u8Char);
void LCD_DispStrXY(INT8U x, INT8U y, INT8U* pu8Str);
void LCD_DispIntXY(INT8U x, INT8U y, int intNum);
void LCD_DispInt(int intNum);
#endif /* LCD_H_ */