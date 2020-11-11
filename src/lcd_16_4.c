/**
 *  @file  : lcd_16_4.c
 *	
 *  @brief	
 *
 *  @author: Francesco Varani
 *  @date  : 11 nov 2020
 */
#include "stm32f4xx.h"
#include "lcd_16_4.h"
#include "delay.h"

/** ---------------------------------- PUBLIC FUNCTIONS DECLARATION ------------------------ */
static void lcd_hw_init(void);

/** ---------------------------------- PUBLIC FUNCTIONS IMPLEMENTATION ------------------------ */
/**
 * @brief Performs the intialization of the LCD, hw and then functional.
 */
void lcd_init(void)
{
	/*
	 * Steps:
	 * 1) wait >40ms
	 * 2) Function set 0x3x
	 * 3) wait >4.1ms
	 * 4) Function set 0x3x
	 * 5) wait >100us
	 * 6) Function set 0x3x - specify the number of lines and character font
	 * 7) Display OFF
	 * 8) Display clear
	 * 9) Entry mode set
	 */
	lcd_hw_init();

	/* 1 */
	Delay_ms(60);

	/* 2 */
	lcd_function_set(1, 0, 0);

	/* 3 */
	Delay_ms(5);

	/* 4 */
	lcd_function_set(1, 0, 0);

	/* 5 */
	Delay_us(100);
}

void lcd_send_command(void)
{
	PORT_LCD_ENABLE->BSRRL =  PIN_LCD_ENABLE;
	// wait ....
	Delay_us(5u);
	PORT_LCD_ENABLE->BSRRH =  PIN_LCD_ENABLE;
}

/** ---------------------------------- PRIVATE FUNCTIONS IMPLEMENTATION ------------------------ */
/**
 * @brief Initializes pin to command the LCD
 */
static void lcd_hw_init(void)
{
	GPIO_InitTypeDef 			GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = PIN_LCD_ENABLE;
	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(PORT_LCD_ENABLE, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = PIN_LCD_RW;
	GPIO_Init(PORT_LCD_RW, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = PIN_LCD_RS;
	GPIO_Init(PORT_LCD_RS, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = PIN_LCD_DB0;
	GPIO_Init(PORT_LCD_DB0, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = PIN_LCD_DB1;
	GPIO_Init(PORT_LCD_DB1, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = PIN_LCD_DB2;
	GPIO_Init(PORT_LCD_DB2, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = PIN_LCD_DB3;
	GPIO_Init(PORT_LCD_DB3, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = PIN_LCD_DB4;
	GPIO_Init(PORT_LCD_DB4, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = PIN_LCD_DB5;
	GPIO_Init(PORT_LCD_DB5, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = PIN_LCD_DB6;
	GPIO_Init(PORT_LCD_DB6, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = PIN_LCD_DB7;
	GPIO_Init(PORT_LCD_DB7, &GPIO_InitStructure);
}
