#include <util/setbaud.h>
#include <avr/io.h>

void usart_init(void);
void usart_transmit_byte(unsigned char data);
void usart_transmit_str(char *str);
uint8_t usart_read_byte(void);
void usart_read_str(char* buffer, uint8_t maxLen);
