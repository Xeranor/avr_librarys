#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "SPI_config.h"

#define SPI_CLOCK_DIVIDER4 0x00
#define SPI_CLOCK_DIVIDER16 0x01
#define SPI_CLOCK_DIVIDER64 0x02
#define SPI_CLOCK_DIVIDER128 0x03
#define SPI_CLOCK_DIVIDER2 0x04
#define SPI_CLOCK_DIVIDER8 0x05
#define SPI_CLOCK_DIVIDER32 0x06

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MASK_MODE 0x0C
#define SPI_MASK_CLOCK 0x03
#define SPI_MASK_2XCLOCK 0x01

void spi_init_master(uint8_t mode,uint8_t clock_divider, bool lsbfirst);
void spi_init_slave(uint8_t mode,bool lsbfirst);
void spi_end(void);

uint8_t spi_transfer(uint8_t data);

void spi_set_bit_order(bool lsbfirst);
void spi_set_data_mode(uint8_t data_mode);
void spi_set_clock_divider(uint8_t clock_divider);


void spi_attach_interrupt(void);
void spi_detach_interrupt(void);
