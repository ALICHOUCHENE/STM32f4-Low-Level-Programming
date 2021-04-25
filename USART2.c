
#include "stm32f4xx.h"  // Device header
#include "string.h"

void USART_INIT(void);

void USART2_WRITE( char* ch);

int main(void)
{
USART_INIT();
	while(1)
	{
		 USART_INIT();
		 USART2_WRITE("USART2 WORKS");
}

}

void USART_INIT(void)
{
RCC->APB1ENR  |=0x20000;   // Enabling APB1 Clock
RCC->AHB1ENR  |=0x1;       // Enabling AHB1 Clock
GPIOA->AFR[0] |=0x0700;	  // Setting PA2 as alternate function
GPIOA->MODER  |=0x20;      // Setting PA2 as output
USART2->BRR   =0x0683; 		//Setting the baude rate (9600 @ 16MHz)
USART2->CR1   |=0x8;  			// Enabling the transmitter 
USART2->CR1   |=0x2000;			// Enabling the USART2
}

void USART2_WRITE( char* ch)
{
	for (uint8_t i=0; i < strlen(ch);i++)
	{
	while(!(USART2->SR & 0x0080)){}
	USART2->DR = ch[i] & 0xFF;					//Sending the data
	}
}
