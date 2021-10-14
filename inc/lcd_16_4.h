/**
 *  @file  : lcd_16_4.h
 *	
 *  @brief	
 *
 *  @author: Francesco Varani
 *  @date  : 11 nov 2020
 */

#ifndef INC_LCD_16_4_H_
#define INC_LCD_16_4_H_

/** ---------------------------------- INCLUDE ------------------------ */
#include "lcd_commands.h"
#include "stm32f4xx.h"

/** ---------------------------------- DEFINE ------------------------ */
/* LCD definition */
#define LCD_MODEL		"MC41605A6W-SPR"
#define LCD_MAX_ROW		(4u)
#define LCD_MAX_COLUMN	(16u)

/** ---------------------------------- PUBLIC FUNCTIONS  ------------------------ */
extern void lcd_init(void);
extern void lcd_set_position(uint8_t x, uint8_t y);


extern void lcd_write_char(void);
extern void lcd_write_char_x_y(void);
extern void lcd_write_string(void);
extern void lcd_write_string_x_y(void);
extern void lcd_set_cursor(void);

#endif /* INC_LCD_16_4_H_ */
