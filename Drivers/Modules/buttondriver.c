/*
 * buttondriver.c
 *
 *  Created on: Aug 21, 2023
 *      Author: brknu
 */

#include "stm32l0xx_hal.h"

void buttondriverInt_init(void){

	////////// 1-CLOCK SETTINGS //////////

	// GPIOC CLOCK
	__HAL_RCC_GPIOC_CLK_ENABLE();

	// SYSCFG CLOCK FOR EXTI
	__HAL_RCC_SYSCFG_CLK_ENABLE();

	///////// 2-EXTI SETTINGS //////////

	// SELECT MODE INPUT
	GPIOC->MODER &= ~((3UL << 26)); // 00 INPUT

	// PULL-UP PULL-DOWN
	GPIOC->PUPDR &= ~((3UL << 26));  // NO PULL-UP NO PULL-DOWN

	////////// 3-EXTI SETTINGS //////////

	// SELECT EXTI_13 -> GPIOC
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;  // SYSCFG->EXTICR[3] |= 0x20

	// EXTI13 INTERRUPT UNMASK
	EXTI->IMR |= EXTI_IMR_IM13;  //EXTI->IMR |= (1<<13);

	// EXTI13 INTERRUPT FALLING EDGE
	EXTI->FTSR = EXTI_FTSR_TR13;

	////////// 4-NVIC SETTINGS //////////

	// SET EXTI14_4 PRIORITY ON NVIC
	NVIC_SetPriority(EXTI4_15_IRQn,1);

	// ENABLE EXTI4_15 INTERRUPT ON NVIC
	NVIC_EnableIRQ(EXTI4_15_IRQn);

}

void EXTI4_15_IRQHandler(void){
	if((EXTI->PR & EXTI_PR_PR13) == EXTI_PR_PR13){
		EXTI->PR |= EXTI_PR_PR13;
		GPIOA->ODR ^= GPIO_PIN_5;
	}
}
