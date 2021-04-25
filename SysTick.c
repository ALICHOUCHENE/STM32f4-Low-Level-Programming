#include "stm32f4xx.h"                                    // Device header

void SystTickDelayMs( int n);
void Setup(void);

int main(void)
{
	Setup();
	while(1)
	{
		GPIOA->ODR ^=0x20;                        // Togle the LED
		SystTickDelayMs(500);                     // Delay Function.
	}
}

void Setup()
{
	RCC->AHB1ENR |=1;      				  // Enabling AHB1 Clock
	GPIOA->MODER |=0x20;   				  // Setting PA5 as output 
}

void SystTickDelayMs( int n)
{
	SysTick->LOAD =16000; 		               	// Reload with number of clocks per millisecond
	SysTick->VAL  =0;     				// Clear Value register
  SysTick->CTRL = 0x5; 				        // Enable SysTick
	for(int i=0;i<n;i++)
	{
  while((SysTick->CTRL & 0x10000) ==0){} 	        // Wait until the COUNT flag is set
	}
	SysTick->CTRL=0;
}
