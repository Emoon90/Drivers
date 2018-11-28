/*
 * spi_cfg.h
 *
 * Created: 221/11/2017
 *  Author: Eman_Samy
 */ 


#ifndef SPI_CFG_H_
#define SPI_CFG_H_

#include <avr/io.h>

//______________________SD_PART_____________________________

#define SPI_SD             SPCR = 0x52
#define SPI_HIGH_SPEED     SPCR = 0x50; SPSR |= (1<<SPI2X)

//__________________________________________________________

#define SS_SPI		PB0
#define MOSI_SPI	PB2
#define MISO_SPI	PB3
#define SCK_SPI	    PB1

#define DDR_SPI		DDRB
#define PORT_SPI	PORTB


#endif /* SPI_CFG_H_ */