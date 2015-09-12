#include "main.h"

int main(void)
{
	usart_init();
	while(1){
		usart_transmit_byte('a');
		usart_transmit_byte('\n');
		usart_transmit_str("Das ist ein test\n");
		char test[10];
		while(1){
			usart_read_str(test,10);
			usart_transmit_str(test);
			usart_transmit_byte('\n');
		}
	}
	return 1;
}