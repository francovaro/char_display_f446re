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

/* Entry mode options */
#define ENTRY_MODE_SET_BLINK_RIGHT_DDRAM_INCREASE	(1<<1)
#define ENTRY_MODE_SET_BLINK_LEFT_DDRAM_DECREASE	(0u)

#define ENTRY_MODE_SET_SHIFT_ENABLED				(1u)
#define ENTRY_MODE_SET_SHIFT_DISABLED				(0u)

/* Display mode options */
#define DISPLAY_ON_OFF_CTRL_ON						(1<<2)
#define DISPLAY_ON_OFF_CTRL_OFF						(0)

#define DISPLAY_ON_OFF_CTRL_ON						(1<<2)
#define DISPLAY_ON_OFF_CTRL_OFF						(0)

#define DISPLAY_ON_OFF_CURSOR_ON					(1<<1)
#define DISPLAY_ON_OFF_CURSOR_OFF					(0)

#define DISPLAY_ON_OFF_CURSOR_BLINK_ON				(1)
#define DISPLAY_ON_OFF_CURSOR_BLINK_OFF				(0)

/** ---------------------------------- TYPE DEFINITION ------------------------ */
typedef enum
{
	e_lcd_command_clear_display,
	e_lcd_command_return_home,
	e_lcd_command_entry_mode_set,
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

typedef struct
{
	t_lcd_command		command_id;
	t_command_struct	data;
	uint8_t				read_write;
	uint8_t				command_register;
	uint8_t				is_constant;
}lcd_command_struct;

extern void lcd_generic_commands(t_lcd_command command_id, uint8_t *data);
extern void lcd_function_set(uint8_t dl_bit, uint8_t line_number, uint8_t font_type);

#endif /* INC_LCD_COMMANDS_H_ */
