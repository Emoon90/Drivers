/*
 * spi_cfg.c
 *
 * Created: 21/11/2017
 *  Author: Eman_Samy
 */
 
#include "spi.h"
#include "spi_cfg.h"

const SpiConfigParamType SpiConfigP[1] =
{
	{prescaler_64,MSB,Master,Rising,Sample}
};
