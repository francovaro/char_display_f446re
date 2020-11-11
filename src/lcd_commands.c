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

typedef struct
{
	union
	{
		uint8_t command_byte;
		uint8_t db0:1;
		uint8_t db1:1;
		uint8_t db2:1;
		uint8_t db3:1;
		uint8_t db4:1;
		uint8_t db5:1;
		uint8_t db6:1;
		uint8_t db7:1;
	};
}t_command_struct;

void lcd_generic_commands(t_lcd_command command_id)
{

}

void lcd_function_set(uint8_t dl_bit, uint8_t line_number, uint8_t font_type)
{
	uint8_t data_to_send = 0x00;
	t_command_struct	function_set_data = {.command_byte = 0x00};

	//data_to_send |= ((dl_bit<<4) | (line_number<<3) | (font_type<<2));

	function_set_data.db2 = font_type;
	function_set_data.db3 = line_number;
	function_set_data.db4 = line_number;
	function_set_data.db5 = 1u;


	lcd_send_command();
}
