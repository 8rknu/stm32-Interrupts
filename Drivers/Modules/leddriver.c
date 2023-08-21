/*
 * leddriver.c
 *
 *  Created on: Aug 13, 2023
 *      Author: brknu
 */
#include "stm32l0xx_hal.h"

void leddriver_init(void){

	RCC -> IOPENR |= (1<<0);
	GPIOA -> MODER |= (1<<10);
	GPIOA -> MODER &= ~(1<<11);

	GPIOA -> OTYPER &= ~(1<<5);

	GPIOA -> OSPEEDR &= ~(1<<10);
	GPIOA -> OSPEEDR &= ~(1<<11);
}


void leddriver_on(void){
	GPIOA -> ODR |= (1<<5);
}


void leddriver_off(void){
	GPIOA -> ODR &= ~(1<<5);
}
