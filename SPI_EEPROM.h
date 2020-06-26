/*
 * SPI_EEPROM.h
 *
 * Created: 07/06/2020 02:00:59 م
 *  Author: BODY
 */ 


#ifndef SPI_EEPROM_H_
#define SPI_EEPROM_H_
#include "SPI.h"
#define INSTRUCTION_WREN   0X06
#define INSTRUCTION_READ   0X03
#define INSTRUCTION_WRITE  0X02


void SPI_EEPROM_Init(void);
INT8U SPI_EEPROM_ReadByte(INT16U  U16RomAdsress);
void SPI_EEPROM_WriteByte(INT16U  U16RomAdsress,INT8U U8Data);




#endif /* SPI_EEPROM_H_ */