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

lcd_command_struct lcd_command_list[] =
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

/** ---------------------------------- PUBLIC FUNCTIONS IMPLEMENTATION ------------------------ */
/**
 *
 * @param command_id
 * @param data
 */
void lcd_generic_commands(t_lcd_command command_id, uint8_t data)
{
	if (lcd_command_list[command_id].is_constant == 0)	/* no need to manipulate data */
	{
		lcd_set_data_pin(lcd_command_list[command_id].data);
	}
	else
	{
		lcd_command_list[command_id].data.command_byte |= (data);	/* include the parameter */
	}

	lcd_set_read_write_pin(lcd_command_list[command_id].read_write);
	lcd_set_command_register_pin(lcd_command_list[command_id].command_register);

	lcd_send_command();
}
