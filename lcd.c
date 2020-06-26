/*
 * lcd.c
 *
 * Created: 5/29/2020 3:20:47 AM
 *  Author: Khalid
 */ 
#include "lcd.h"

static void LCD_SendCmd(INT8U u8Cmd);
static void LCD_SendData(INT8U u8Data);
static void LCD_GotoXY(INT8U x, INT8U y);

static void LCD_SendCmd(INT8U u8Cmd){
	clearbit(LCD_CTRL_PORT, LCD_RS);	/* RS -> 0 */
	LCD_DATA_PORT = u8Cmd;				/* upload  u8Cmd*/
	setbit(LCD_CTRL_PORT, LCD_EN);		/* high and low for EN */
	clearbit(LCD_CTRL_PORT, LCD_EN);
	_delay_us(40);						/* wait 40 us */	
}
static void LCD_SendData(INT8U u8Data){
	setbit(LCD_CTRL_PORT, LCD_RS);		/* RS -> 1 */
	LCD_DATA_PORT = u8Data;				/* upload  u8Data*/
	setbit(LCD_CTRL_PORT, LCD_EN);		/* high and low for EN */
	clearbit(LCD_CTRL_PORT, LCD_EN);
	_delay_us(40);						/* wait 40 us */
}
/* 
	Line 1: 0x00
	Line 2: 0x40
*/
static void LCD_GotoXY(INT8U x, INT8U y){
	/* get address of DDRAM using x,y */
	if(x == 1){
		LCD_SendCmd((0x80|0x00) + y-1); /* Eqn */
	}
	else{
		LCD_SendCmd((0x80|0x40) + y-1); /* Eqn */
	}
}
void LCD_Init(void){
	/* Directions -> OUT */
	setallbits(LCD_DATA_DDR);
	setbit(LCD_CTRL_DDR, LCD_RS);
	setbit(LCD_CTRL_DDR, LCD_EN);
	/* delay -> 20 ms (power on lcd) */
	_delay_ms(20);
	LCD_SendCmd(CMD_CFG);		/* 0x38 => 2 lines and 5x8 dots*/
	LCD_SendCmd(CMD_DISP_ON);	/* 0x0C => Display on, no cursur, no bliking*/
	LCD_SendCmd(CMD_ENTRY_MODE);	/* 0x06 => cursur moves right, no display shift*/
	LCD_Clear();
}
void LCD_Clear(void){
	LCD_SendCmd(CMD_CLEAR);		/* 0x01 => Clear display*/
	_delay_ms(5);		/* delay 5 ms */
}
void LCD_DispChar(INT8U u8Char){
	LCD_SendData(u8Char);
}
void LCD_DispStr(INT8U* pu8Str){
	while (*pu8Str)
	{
		LCD_SendData(*pu8Str);
		pu8Str++;
	}
}
void LCD_DispCharXY(INT8U x, INT8U y, INT8U u8Char){
	LCD_GotoXY(x,y);
	LCD_DispChar(u8Char);
}
void LCD_DispStrXY(INT8U x, INT8U y, INT8U* pu8Str){
	LCD_GotoXY(x,y);
	LCD_DispStr(pu8Str);
}
void LCD_DispInt(int intNum){	char a_bufferString[17]={0};	sprintf(a_bufferString, "%d", intNum);	LCD_DispStr(a_bufferString);}void LCD_DispIntXY(INT8U x, INT8U y, int intNum){	LCD_GotoXY(x,y);	LCD_DispInt(intNum);}
