#include <avr/io.h>

#define SPI_PORT PORTB
#define SPI_DDR DDRB
#define SPI_SCK PB5
#define SPI_MISO PB4
#define SPI_MOSI PB3
#define SPI_CTRL_REG SPCR
#define SPI_DATA_REG SPDR
#define SPI_STAT_REG SPSR