/*
 * spi.c
 *
 * Created: 21/11/2017
 *  Author: Eman_Samy
 */ 


#define F_CPU 16000000
#include "util/delay.h"
#include "spi.h"
#include "spi_cfg.h"

extern const SpiConfigParamType SpiConfigP[1];

void SPI_INIT(void)
{
	DDR_SPI |= (1<<SCK_SPI)|(1<<MOSI_SPI)|(SS_SPI);
	DDR_SPI &=~ (MISO_SPI);
	PORT_SPI |=(1<<SS_SPI);

	SPCR=(1<<SPE)|(SpiConfigP[0].DORD1<<5)|(SpiConfigP[0].MSTR1<<4)|(SpiConfigP[0].CPOL1<<3)|(SpiConfigP[0].CPHA1<<2)|(SpiConfigP[0].prescaler1<<0);
}

uint8_t SPI_Transmit(uint8_t Data)
{
	uint8_t data=0;
	
	SPDR=Data;
	while(!(SPSR&(1<<SPIF)));
    data=SPDR;
	
	return(data);
}

uint8_t SPI_receive(void)
{
	uint8_t data;

	SPDR = 0xff;
	while(!(SPSR & (1<<SPIF)));
	data = SPDR;

	return data;
}
