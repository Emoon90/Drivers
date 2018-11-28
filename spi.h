/*
 * spi.h
 *
 * Created: 21/11/2017
 *  Author: Eman_Samy
 */ 

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include "spi_cfg.h"

typedef enum { MSB = 0, LSB} DORD_Type;
typedef enum {Slave = 0,Master} MSTR_Type;
	
//_________________________________________	
// CPOL  |  Leading Edge   | Trailing Edge
//----------------------------------------
//  0    |   Rising		   |   Failing
//  1	 |   Failing       |   Rising
//_________________________________________
//CPHA   |  Leading Edge   | Trailing Edge
//-----------------------------------------
//  0    |   Sample        |  Setup
//  1    |   Setup         |  Sample
//_________________________________________

typedef enum {Rising = 0,Falling}CPOL_Type;
typedef enum {Sample = 0,Setup}CPHA_Type;
	
typedef enum {prescaler_4 = 0,prescaler_16,prescaler_64,prescaler_128,prescaler_2,prescaler_8,prescaler_32}prescaler_Type;
	
typedef struct
{
	prescaler_Type prescaler1;
	DORD_Type      DORD1;
	MSTR_Type      MSTR1;
	CPOL_Type      CPOL1;
	CPHA_Type      CPHA1;
	
}SpiConfigParamType;

void SPI_INIT(void);
uint8_t SPI_Transmit(uint8_t Data);
uint8_t SPI_receive(void);

#endif /* SPI_H_ */