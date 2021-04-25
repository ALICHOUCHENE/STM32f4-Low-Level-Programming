#include "stm32f4xx.h"                  // Device header.

// Toggle onboard LED connected to PA5 using TIM2 with output compare mode.
void Toggle_Output_Compare_Mode(void);
void Setup(void);
int main(void)
{
	Setup();
	Toggle_Output_Compare_Mode();
}
void Setup(void)
{
	RCC->AHB1ENR |=1; // Enabling AHB1 Clock.
	GPIOA->MODER |= 0x800; // Set PA5 to Alternate Function.
	GPIOA->AFR[0] |=0x100000; // Set pin Af1 for TIM2 CHANNEL_1.
	RCC->APB1ENR |=1;
}
void Toggle_Output_Compare_Mode(void)
{
	TIM2->PSC =1600-1;
	TIM2->ARR =100000-1;
	TIM2->CCMR1 =0x30; // Set output to toggle on match.
	TIM2->CCR1 =0;     // St match mode.
	TIM2->CCER |=1; // Enable CH1 compare mode.
	TIM2->CNT =0; // Clear counter.
	TIM2->CR1 |=1; // Enable TIM2.
}
