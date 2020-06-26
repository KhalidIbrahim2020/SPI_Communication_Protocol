/*
 * SPI.h
 *
 * Created: 07/06/2020 10:29:09 ص
 *  Author: BODY
 */ 


#ifndef SPI_H_
#define SPI_H_

#ifndef F_CPU
#define F_CPU	8000000UL
#endif

#include	"avr/io.h"
#include	"data_types.h"
#include	"bit_handle.h"
#include	"util/delay.h"

typedef enum{
	
	MODE_MASTER,MODE_SLAVE
	}SPI_Mode;
	
#define SPI_PORT  PORTB
#define SPI_DDR   DDRB
#define SPI_SS    PB0 
#define SPI_SCK   PB1
#define SPI_MOZI  PB2
#define SPI_MISO  PB3
void SPI_Init(SPI_Mode SpiMode);
INT8U SPI_Tranceive(INT8U U8Data);



#endif /* SPI_H_ */