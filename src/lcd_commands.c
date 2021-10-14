/**
 *  @file  : lcd_commands.c
 *
 *  @brief
 *
 *  @author: Francesco Varani
 *  @date  : 11 nov 2020
 */
#include "lcd_commands.h"
#include "lcd_16_4.h"
#include "delay.h"
#include "lcd_pin.h"

static lcd_command_struct lcd_command_list[] =
{
	{.command_id = e_lcd_command_clear_display,		.data.command_byte = 0x01, .read_write = 0, .command_register = 0, .is_constant = 1},
	{.command_id = e_lcd_command_return_home,		.data.command_byte = 0x02, .read_write = 0, .command_register = 0, .is_constant = 1},
	{.command_id = e_lcd_command_entry_mode_set,	.data.command_byte = 0x04, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_dsp_on_off,		.data.command_byte = 0x08, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_cursor_dsp_shft,	.data.command_byte = 0x10, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_funcional_set, 	.data.command_byte = 0x20, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_set_CGRAM,			.data.command_byte = 0x40, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_set_DDRAM,			.data.command_byte = 0x80, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_read_bsy_addr,		.data.command_byte = 0x00, .read_write = 1, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_write_data,		.data.command_byte = 0x00, .read_write = 0, .command_register = 1, .is_constant = 0},
	{.command_id = e_lcd_command_read_data,			.data.command_byte = 0x00, .read_write = 1, .command_register = 1, .is_constant = 0},

};

static void lcd_send_command(void);
static void lcd_set_data_pin(t_command_struct data_bus);
static void lcd_set_pin(uint8_t value, uint16_t pin);
static void lcd_set_read_write_pin(uint8_t read_write_bit);
static void lcd_set_command_register_pin(uint8_t command_register_bit);

/** ---------------------------------- PUBLIC FUNCTIONS IMPLEMENTATION ------------------------ */
/**
 * @brief sends a command
 * @param command_id
 * @param data
 */
void lcd_generic_commands(t_lcd_command command_id, uint8_t data)
{
	/**
	 * To send a command:
	 * 1 set data pin
	 * 2 set READWRITE pin
	 * 3 set REGISTER SELECT pin
	 * 4 toggle ENABLE pin
	 */
	t_command_struct data_bus = {.command_byte = 0x00};

	if (lcd_command_list[command_id].is_constant == 1)	/* no need to manipulate data */
	{
		data_bus = lcd_command_list[command_id].data;
	}
	else
	{
		data_bus.command_byte = lcd_command_list[command_id].data.command_byte |= (data);	/* include the parameter */
	}

	lcd_set_data_pin(data_bus);
	lcd_set_read_write_pin(lcd_command_list[command_id].read_write);
	lcd_set_command_register_pin(lcd_command_list[command_id].command_register);

	lcd_send_command();
}

/* */
/**
 * @brief Toggle ENABLE pin to "send" command
 */
static void lcd_send_command(void)
{
	PORT_LCD_ENABLE->BSRRL =  PIN_LCD_ENABLE;	/* set pin E */
	Delay_us(5u);
	PORT_LCD_ENABLE->BSRRH =  PIN_LCD_ENABLE;	/* clear pin E*/
}

/**
 * @brief Set DBx pin to write data
 * @param data_bus
 */
static void lcd_set_data_pin(t_command_struct data_bus)
{
	lcd_set_pin(data_bus.db0, PIN_LCD_DB0);
	lcd_set_pin(data_bus.db1, PIN_LCD_DB1);
	lcd_set_pin(data_bus.db2, PIN_LCD_DB2);
	lcd_set_pin(data_bus.db3, PIN_LCD_DB3);
	lcd_set_pin(data_bus.db4, PIN_LCD_DB4);
	lcd_set_pin(data_bus.db5, PIN_LCD_DB5);
	lcd_set_pin(data_bus.db6, PIN_LCD_DB6);
	lcd_set_pin(data_bus.db7, PIN_LCD_DB7);
}

/**
 *
 * @param value
 * @param pin
 */
static void lcd_set_pin(uint8_t value, uint16_t pin)
{
	if (value == 1)
	{
		PORT_LCD_DBx->BSRRL =  pin;
	}
	else if (value == 0)
	{
		PORT_LCD_DBx->BSRRH =  pin;	/* clear pin E*/
	}
}

/**
 * @brief Set the RW pin
 * @param read_write_bit
 */
static void lcd_set_read_write_pin(uint8_t read_write_bit)
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
static void lcd_set_command_register_pin(uint8_t command_register_bit)
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
