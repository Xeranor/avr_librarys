#include "main.h"

int main(void)
{
	usart_init();
	while(1){
		usart_transmit_byte('a');
		usart_transmit_byte('\n');
		_delay_ms(500);
		usart_transmit_str("Das ist ein test\n");
	}
	return 1;
}