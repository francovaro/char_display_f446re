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

/** ---------------------------------- DEFINE ------------------------ */
/* LCD definition */
#define LCD_MODEL		"MC41605A6W-SPR"
#define LCD_MAX_ROW		(4u)
#define LCD_MAX_COLUMN	(16u)

/* PIN definition */

/* LCD enable*/
#define PIN_LCD_ENABLE	GPIO_Pin_5
#define PORT_LCD_ENABLE	GPIOA
/* LCD Read Write */
#define PIN_LCD_RW		GPIO_Pin_5
#define PORT_LCD_RW		GPIOA
/* LCD Register Command*/
#define PIN_LCD_RS		GPIO_Pin_5
#define PORT_LCD_RS		GPIOA
/* LCD Datab Bus pin*/
#define PIN_LCD_DB0		GPIO_Pin_5
#define PORT_LCD_DB0	GPIOA
#define PIN_LCD_DB1		GPIO_Pin_5
#define PORT_LCD_DB1	GPIOA
#define PIN_LCD_DB2		GPIO_Pin_5
#define PORT_LCD_DB2	GPIOA
#define PIN_LCD_DB3		GPIO_Pin_5
#define PORT_LCD_DB3	GPIOA
#define PIN_LCD_DB4		GPIO_Pin_5
#define PORT_LCD_DB4	GPIOA
#define PIN_LCD_DB5		GPIO_Pin_5
#define PORT_LCD_DB5	GPIOA
#define PIN_LCD_DB6		GPIO_Pin_5
#define PORT_LCD_DB6	GPIOA
#define PIN_LCD_DB7		GPIO_Pin_5
#define PORT_LCD_DB7	GPIOA

/** ---------------------------------- PUBLIC FUNCTIONS  ------------------------ */
extern void lcd_init(void);
extern void lcd_send_command(void);

extern void lcd_write_char(void);
extern void lcd_write_char_x_y(void);
extern void lcd_write_string(void);
extern void lcd_write_string_x_y(void);
extern void lcd_set_cursor(void);

#endif /* INC_LCD_16_4_H_ */
