/*
 *  @file  : delay.c
 *	
 *  @brief	
 *
 *  @author: franc
 *  @date  : 11 nov 2020
 */
#include "stm32f4xx.h"
#include "delay.h"

volatile uint32_t _req_delay_us;

/**
 *
 */
void Delay_init(void)
{
	_req_delay_us = 0;
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000000);
}

/**
 *
 * @param delay
 */
void Delay_ms(uint16_t delay)
{
	do
	{
		Delay_us(1000);
		delay--;
	}while(delay);
}

/**
 *
 * @param delay
 */
void Delay_us(uint16_t delay)
{
	_req_delay_us = delay;

	while(_req_delay_us);
}

/**
 *
 */
void SysTick_Handler(void)
{
	if(_req_delay_us != 0)
	{
		_req_delay_us--;
	}
}
