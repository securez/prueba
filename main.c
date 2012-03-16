//#include <stdio.h>
//#include <math.h>
#include <avr/io.h>
//#include <avr/pgmspace.h>
#include <util/delay.h>

//#define USART_BAUDRATE 115200
//
//void USART0Init(void) {
//	#define BAUD 115200
//	#include <util/setbaud.h>
//
//	// Set baud rate
//	UBRR0H = UBRRH_VALUE;
//	UBRR0L = UBRRL_VALUE;
//
//	#if USE_2X
//		UCSR0A |= (1 << U2X0);
//	#else
//		UCSR0A &= ~(1 << U2X0);
//	#endif
//
//	// Set frame format to 8 data bits, no parity, 1 stop bit
//	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
//
//	//enable transmission and reception
//	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
//}
//
//int USART0SendByte(char u8Data, FILE *stream) {
//	if (u8Data == '\n') {
//		USART0SendByte('\r', 0);
//	}
//
//	//wait while previous byte is completed
//	while (!(UCSR0A & (1 << UDRE0))) {
//	};
//
//	// Transmit data
//	UDR0 = u8Data;
//	return 0;
//}
//
//int USART0ReceiveByte(FILE *stream) {
//	uint8_t u8Data;
//
//	// Wait for byte to be received
//	while (!(UCSR0A & (1 << RXC0))) {
//	};
//	u8Data = UDR0;
//
//	//echo input data
//	USART0SendByte(u8Data, stream);
//
//	// Return received data
//	return u8Data;
//}

//set stream pointer
//FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, USART0ReceiveByte, _FDEV_SETUP_RW);

//int main(void) {
//	//sample data
//	uint16_t u16Data = 10;
//	double fltData = 3.141593;
//	int8_t s8Data = -5;
//	uint8_t u8str[] = "Hello";
//	uint8_t u8Data;
//
//	//Initialize USART0
//	USART0Init();
//
//	//assign our stream to standart I/O streams
//	stdin = stdout = &usart0_str;
//
//	//print unsignet integer
//	printf("\nunsigned int = %u", u16Data);
//	//print hexadecimal number
//	printf("\nhexadecimal unsigned int = %#04x", u16Data);
//	//print double with fprint function
//	fprintf(stdout, "\ndouble = %08.3f", fltData);
//	//print signed data
//	printf("\nsigned int = %d", s8Data);
//	//print string
//	printf("\nstring = %-20s", u8str);
//	//print string stored in flash
//	printf_P(PSTR("\nString stored in flash"));
//	//printing back slash and percent symbol
//	printf("\nprintf(\"\\nstring = %%-20s\",u8str);");
//	while (1) {
//		printf_P(PSTR("\nPress any key:"));
//		//scan standard stream (USART)
//		scanf("%c", &u8Data);
//		printf_P(PSTR("\nYou pressed: "));
//		//print scaned character and its code
//		printf("%c; Key code: %u", u8Data, u8Data);
//	}
//}

void delay() {
	int i, j, h;

	for (h = 0; h < 16; h++)
		for (i = 0; i < 10000; i++)
			for (j = 0; j < 10000; j++)
				;
}

int main(void) {
	/* INITIALIZE */
	/* enable PE2 as output */
	DDRE |= (1 << DDE2);

	while (1) {
		/* led on, pin=0 */
		PORTE &= ~(1 << PE2);
//		delay();
    _delay_ms(500);
		/* set output to 5V, LED off */
		PORTE |= (1 << PE2);
    _delay_ms(500);
//		delay();
	}

	return (0);
}

