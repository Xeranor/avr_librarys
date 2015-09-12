#include "SPI.h"

void spi_init_master(uint8_t mode,uint8_t clock_divider, bool lsbfirst)
{
	spi_set_data_mode(mode);
	spi_set_clock_divider(clock_divider);
	spi_set_bit_order(lsbfirst);
	SPI_CTRL_REG |= (1<<MSTR) | (1<<SPE);
	SPI_DDR |= (1<<SPI_SCK) | (1<<SPI_MOSI);
}

void spi_init_slave(uint8_t mode,bool lsbfirst)
{
	spi_set_data_mode(mode);
	spi_set_bit_order(lsbfirst);
	SPI_CTRL_REG |= (1<<SPE);
	SPI_DDR |= (1<<SPI_MISO);
}

void spi_end(void)
{
	SPI_CTRL_REG &= ~(1<<SPE);
}

uint8_t spi_transfer(uint8_t data)
{
	SPDR = data;
	loop_until_bit_is_set(SPI_STAT_REG,SPIF);
	return SPDR;
}

void spi_set_bit_order(bool lsbfirst)
{
	if (lsbfirst){
		SPI_CTRL_REG |= (1<<DORD);
	} else {
		SPI_CTRL_REG &= ~(1<<DORD);
	}
}

void spi_set_data_mode(uint8_t data_mode)
{
	SPI_CTRL_REG = (SPI_CTRL_REG & ~SPI_MASK_MODE) | data_mode;
}

void spi_set_clock_divider(uint8_t clock_divider)
{
	SPI_CTRL_REG = 
					(SPI_CTRL_REG & ~SPI_MASK_CLOCK) | (clock_divider & SPI_MASK_CLOCK);
	SPI_STAT_REG = 
					(SPI_STAT_REG & ~SPI_MASK_2XCLOCK) | ((clock_divider>>2) 
													& SPI_MASK_2XCLOCK);
}
