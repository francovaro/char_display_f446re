/**
  ******************************************************************************
  * @file    main.c
  * @author  Francesco Varani
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "lcd_16_4.h"
#include "delay.h"

int main(void)
{
	Delay_init();
	lcd_init();

	while(1)
	{

	}
}
