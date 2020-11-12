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
	{.command_id = e_lcd_command_entr_mode_set,		.data.command_byte = 0x04, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_dsp_on_off,		.data.command_byte = 0x08, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_cursor_dsp_shft,	.data.command_byte = 0x10, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_funcional_set, 	.data.command_byte = 0x20, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_set_CGRAM,			.data.command_byte = 0x40, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_set_DDRAM,			.data.command_byte = 0x80, .read_write = 0, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_read_bsy_addr,		.data.command_byte = 0x00, .read_write = 1, .command_register = 0, .is_constant = 0},
	{.command_id = e_lcd_command_write_data,		.data.command_byte = 0x00, .read_write = 0, .command_register = 1, .is_constant = 0},
	{.command_id = e_lcd_command_read_data,			.data.command_byte = 0x00, .read_write = 1, .command_register = 1, .is_constant = 0},

};

void lcd_generic_commands(t_lcd_command command_id, uint8_t *data)
{
	if (lcd_command_list[command_id].is_constant == 0)	/* no need to manipulate data */
	{
		lcd_set_data_pin(lcd_command_list[command_id].data);
		lcd_set_read_write_pin(lcd_command_list[command_id].read_write);
		lcd_set_command_register_pin(lcd_command_list[command_id].command_register);

		lcd_send_command();
	}
	else
	{

	}
#if 0
	switch(command_id)
	{
		case e_lcd_command_clear_display:
		{

		}
		break;
		case e_lcd_command_return_home:
		{

		}
		break;
		case e_lcd_command_entr_mode_set:
		{

		}
		break;
		case e_lcd_command_dsp_on_off:
		{

		}
		break;
		case e_lcd_command_cursor_dsp_shft:
		{

		}
		break;
		case e_lcd_command_set_CGRAM:
		{

		}
		break;
		case e_lcd_command_set_DDRAM:
		{

		}
		break;
		case e_lcd_command_read_bsy_addr:
		{

		}
		break;
		case e_lcd_command_write_data:
		{

		}
		break;
		case e_lcd_command_read_data:
		{

		}
		break;
		default:
		case e_lcd_command_max:
		{

		}
		break;
	}
#endif
}

void lcd_function_set(uint8_t dl_bit, uint8_t line_number, uint8_t font_type)
{
	t_command_struct	function_set_data = {.command_byte = 0x00};

	//data_to_send |= ((dl_bit<<4) | (line_number<<3) | (font_type<<2));

	function_set_data.db2 = font_type;
	function_set_data.db3 = line_number;
	function_set_data.db4 = line_number;
	function_set_data.db5 = 1u;

	lcd_set_data_pin(function_set_data);

	lcd_send_command();
}
