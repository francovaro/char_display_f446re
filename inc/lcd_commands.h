/*
 *  @file  : lcd_commands.h
 *	
 *  @brief : List of commands
 *
 *  @author: Francesco Varani
 *  @date  : 11 nov 2020
 */

#ifndef INC_LCD_COMMANDS_H_
#define INC_LCD_COMMANDS_H_

#include <stdint.h>

/** ---------------------------------- DEFINE ------------------------ */
#define	LCD_READ		(1u)
#define	LCD_WRITE		(0u)
#define LCD_COMMAND		(0u)
#define LCD_REGISTER	(1u)

/** ---------------------------------- TYPE DEFINITION ------------------------ */
typedef enum
{
	e_lcd_command_clear_display,
	e_lcd_command_return_home,
	e_lcd_command_entr_mode_set,
	e_lcd_command_dsp_on_off,
	e_lcd_command_cursor_dsp_shft,
	e_lcd_command_funcional_set,
	e_lcd_command_set_CGRAM,
	e_lcd_command_set_DDRAM,
	e_lcd_command_read_bsy_addr,
	e_lcd_command_write_data,
	e_lcd_command_read_data,
	e_lcd_command_max
}t_lcd_command;

typedef struct
{
	t_lcd_command	command_id;
	uint8_t			*data;
	uint8_t			read_write;
	uint8_t			command_register;
}lcd_command_struct;

extern void lcd_generic_commands(t_lcd_command command_id);

#endif /* INC_LCD_COMMANDS_H_ */
