#include "main.h"

int main(void)
{
	spi_init_master(SPI_MODE0,SPI_CLOCK_DIVIDER128,false);
	while(1){
		spi_transfer(0xff);
		_delay_ms(50);
	}
	return 1;
}