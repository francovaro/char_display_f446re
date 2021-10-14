/**
 *  @file  : lcd_16_4.c
 *	
 *  @brief	
 *
 *  @author: Francesco Varani
 *  @date  : 11 nov 2020
 */
#include "lcd_16_4.h"
#include "delay.h"
#include "lcd_pin.h"

/** ---------------------------------- DEFINE ------------------------ */
#define LCD_ROW_0	0x00
#define LCD_ROW_1	0x40
#define LCD_ROW_2	0x10
#define LCD_ROW_3	0x50

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
	lcd_generic_commands(e_lcd_command_funcional_set, FUNCTION_SET_8_BIT);

	/* 3 wait at least 4.1ms */
	Delay_ms(5);

	/* 4 Funcional set 8bit set */
	lcd_generic_commands(e_lcd_command_funcional_set, FUNCTION_SET_8_BIT);

	/* 5 wait at least 100us */
	Delay_us(150);

	/* 6 Funcional set 8bit set */
	lcd_generic_commands(e_lcd_command_funcional_set, FUNCTION_SET_8_BIT);

	Delay_us(150);	/* wait ? */

	/* 7 Funcional set 8bit set and number of line and character */
	lcd_generic_commands(e_lcd_command_funcional_set, FUNCTION_SET_8_BIT | FUNCTION_SET_2_LINE | FUNCTION_SET_5_11_CHAR);

	/* 8 Display OFF */
	lcd_generic_commands(e_lcd_command_dsp_on_off, DISPLAY_ON_OFF_CTRL_OFF | DISPLAY_ON_OFF_CURSOR_OFF | DISPLAY_ON_OFF_CURSOR_BLINK_OFF);

	/* 9 Display clear */
	lcd_generic_commands(e_lcd_command_clear_display, 0);

	/* 10 Entry mode set */
	lcd_generic_commands(e_lcd_command_entry_mode_set, ENTRY_MODE_SET_BLINK_RIGHT_DDRAM_INCREASE | ENTRY_MODE_SET_SHIFT_DISABLED);
}

/**
 *
 * @param x
 * @param y
 */
void lcd_set_position(uint8_t x, uint8_t y)
{
	uint8_t	address = x;
	const uint8_t delta_y_LUT[LCD_MAX_ROW] =
	{
			LCD_ROW_0,
			LCD_ROW_1,
			LCD_ROW_2,
			LCD_ROW_3,
	};

	if ((x < LCD_MAX_COLUMN) && (LCD_MAX_ROW))
	{
		address += delta_y_LUT[y];

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


