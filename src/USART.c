#include <avr/io.h>
#include "USART.h"
#include <util/setbaud.h>

void usart_init(void){
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	UCSR0C = (1<<UCSZ00) | (1 << UCSZ01);
}

void usart_transmit_byte(unsigned char data) {
	loop_until_bit_is_set(UCSR0A,UDRE0);
	UDR0 = (unsigned char) data;
}


void usart_transmit_str(char *str)
{
	while(*str != '\0')
	{
		usart_transmit_byte(*str);
		++str;
	}
}

uint8_t usart_read_byte(void)
{
	loop_until_bit_is_set(UCSR0A,RXC0);
	return (uint8_t) UDR0;
}

void usart_read_str(char* buffer, uint8_t maxLen)
{
	uint8_t nextChar;
	uint8_t stringLen = 0;

	nextChar = (char)usart_read_byte();
	while(nextChar != '\n' && stringLen < maxLen -1){
		*buffer++ = nextChar;
		stringLen++;
		nextChar = (char)usart_read_byte();
	}
	*buffer = '\0';
}
