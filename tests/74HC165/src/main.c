#include "main.h"

int main(void){
	usart_init();
	shift_init();
	while(1){
		uint8_t data = shift_in();
		usart_transmit_byte(data);
		_delay_ms(500);
		
	}
	return 1;
}