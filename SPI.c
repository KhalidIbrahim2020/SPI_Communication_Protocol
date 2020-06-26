/*
 * SPI.c
 *
 * Created: 07/06/2020 10:29:25 ص
 *  Author: Khalid Ibrahim
 */ 
#include "SPI.h"

void SPI_Init(SPI_Mode SpiMode){
	
	switch(SpiMode)
	{
		case MODE_MASTER:
		setbit(SPI_DDR,SPI_MOZI);
		setbit(SPI_DDR,SPI_SCK);
		setbit(SPI_DDR,SPI_SS);
		//UN SELECT FOR SLAVE
		setbit(SPI_PORT,SPI_SS);
		clearbit(SPI_DDR,SPI_MISO);//input
		//Master Mode selection
		setbit(SPCR,MSTR);
		break;
		case MODE_SLAVE:
		clearbit(SPI_DDR,SPI_MOZI);
		clearbit(SPI_DDR,SPI_SCK);
		clearbit(SPI_DDR,SPI_SS);
		// SELECT FOR SLAVE
		clearbit(SPI_PORT,SPI_SS);
		setbit(SPI_DDR,SPI_MISO);//input
		//Slave Mode selection
		clearbit(SPCR,MSTR);
		break;
	}
	//ENABLE SPI
	setbit(SPCR,SPE);
}
  
INT8U SPI_Tranceive(INT8U U8Data){
	
	//update DR
	SPDR=U8Data;   //SHIFT STARTED
	//wait for shift complete flag
	while(!(SPSR&(1<<SPIF)));
	//return DR	
	return SPDR;
}
