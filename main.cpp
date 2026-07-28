// #include "main.h"
#include "AvrArray.h"
#include <unistd.h>

void USART_Init() {
    UBRR0H = (103 >> 8);
    UBRR0L = 103;

    //Включаем передачу и получение данных
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    //Пока хз что это
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}


unsigned char USART_Receive() {
    while (!(UCSR0A & (1 << RXC0)));

    while (UCSR0A & (1 << RXC0)) {
        unsigned char data = UDR0;

    }
    return UDR0;
}


void USART_Transmit(int8_t data) {
    while (!(UCSR0A & (1 << UDRE0))); // Ждем когда буфер будет пуст
    UDR0 = data;
}



int main() {

}