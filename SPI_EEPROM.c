/*
 * SPI_EEPROM.c
 *
 * Created: 07/06/2020 02:10:11 م
 *  Author: Khalid Ibrahim
 */ 

#include "SPI_EEPROM.h"


void SPI_EEPROM_Init(void){
	
	SPI_Init(MODE_MASTER);
	
}


static void SPI_EEPROM_WriteEnable(void){
	
	clearbit(SPI_PORT,SPI_SS);
	SPI_Tranceive(INSTRUCTION_WREN);
	setbit(SPI_PORT,SPI_SS);
	_delay_ms(10);
}

INT8U SPI_EEPROM_ReadByte(INT16U  U16RomAdsress){
	INT8U Result=0;
	clearbit(SPI_PORT,SPI_SS);
	SPI_Tranceive(INSTRUCTION_READ | ((U16RomAdsress>>5)&0X08));//read instruction
	SPI_Tranceive((INT8U)U16RomAdsress);//send address
	Result=SPI_Tranceive(0x00);//send and recive data from eeprom
	setbit(SPI_PORT,SPI_SS);
	_delay_ms(10);
	return Result;
}
void SPI_EEPROM_WriteByte(INT16U  U16RomAdsress,INT8U U8Data){
	SPI_EEPROM_WriteEnable();
	clearbit(SPI_PORT,SPI_SS);
	SPI_Tranceive(INSTRUCTION_WRITE | ((U16RomAdsress>>5)&0X08)    );
	SPI_Tranceive((INT8U)U16RomAdsress);
	SPI_Tranceive(U8Data);
	setbit(SPI_PORT,SPI_SS);
	_delay_ms(10);
	
	
}
