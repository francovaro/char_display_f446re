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
	 * 6) Function set 0x3x
	 * 7) Function set 0x3x - specify the number of lines and character font
	 * 8) Display OFF
	 * 9) Display clear
	 *10) Entry mode set
	 */
	lcd_hw_init();

	/* 1 Initial wait 40 ms */
	Delay_ms(60);

	/* 2 Funcional set 8bit set */
	lcd_function_set(1, 0, 0);

	/* 3 wait at least 4.1ms */
	Delay_ms(5);

	/* 4 Funcional set 8bit set */
	lcd_function_set(1, 0, 0);

	/* 5 wait at least 100us */
	Delay_us(150);

	/* 6 Funcional set 8bit set */
	lcd_function_set(1, 0, 0);

	/* 7 Funcional set 8bit set and number of line and character */
	lcd_function_set(1, 2, 1);

	/* 8 Display OFF */
	lcd_generic_commands(e_lcd_command_dsp_on_off, DISPLAY_ON_OFF_CTRL_OFF | DISPLAY_ON_OFF_CTRL_OFF | DISPLAY_ON_OFF_CURSOR_BLINK_OFF);

	/* 9 Display clear */
	lcd_generic_commands(e_lcd_command_clear_display, 0);

	/* 10 Entry mode set */
	lcd_generic_commands(e_lcd_command_entry_mode_set, ENTRY_MODE_SET_BLINK_RIGHT_DDRAM_INCREASE | ENTRY_MODE_SET_SHIFT_DISABLED);
}

/**
 *
 */
void lcd_send_command(void)
{
	PORT_LCD_ENABLE->BSRRL =  PIN_LCD_ENABLE;	/* set pin E */
	Delay_us(5u);
	PORT_LCD_ENABLE->BSRRH =  PIN_LCD_ENABLE;	/* clear pin E*/
}

/**
 *
 * @param data_bus
 */
void lcd_set_data_pin(t_command_struct data_bus)
{

}

/**
 *
 * @param read_write_bit
 */
void lcd_set_read_write_pin(uint8_t read_write_bit)
{
	if (read_write_bit == 1)
	{
		PORT_LCD_RW->BSRRL =  PIN_LCD_RW;
	}
	else if (read_write_bit == 0)
	{
		PORT_LCD_RW->BSRRH =  PIN_LCD_RW;	/* clear pin E*/
	}
}

/**
 *
 * @param command_register_bit
 */
void lcd_set_command_register_pin(uint8_t command_register_bit)
{
	if (command_register_bit == 1)
	{
		PORT_LCD_RS->BSRRL =  PIN_LCD_RS;
	}
	else if (command_register_bit == 0)
	{
		PORT_LCD_RS->BSRRH =  PIN_LCD_RS;	/* clear pin E*/
	}
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
