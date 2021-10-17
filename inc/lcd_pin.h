#include "stm32f4xx.h"

/* PIN definition */

/* LCD Register Command*/
#define PIN_LCD_RS		GPIO_Pin_4
#define PORT_LCD_RS		GPIOC
/* LCD Read Write */
#define PIN_LCD_RW		GPIO_Pin_13
#define PORT_LCD_RW		GPIOB
/* LCD enable*/
#define PIN_LCD_ENABLE	GPIO_Pin_14
#define PORT_LCD_ENABLE	GPIOB


/* LCD Datab Bus pin*/
#define PORT_LCD_DBx	GPIOA

#define PIN_LCD_DB0		GPIO_Pin_15
#define PORT_LCD_DB0	GPIOB
#define PIN_LCD_DB1		GPIO_Pin_1
#define PORT_LCD_DB1	GPIOB
#define PIN_LCD_DB2		GPIO_Pin_2
#define PORT_LCD_DB2	GPIOB
#define PIN_LCD_DB3		GPIO_Pin_12
#define PORT_LCD_DB3	GPIOB
#define PIN_LCD_DB4		GPIO_Pin_11
#define PORT_LCD_DB4	GPIOA
#define PIN_LCD_DB5		GPIO_Pin_12
#define PORT_LCD_DB5	GPIOA
#define PIN_LCD_DB6		GPIO_Pin_5
#define PORT_LCD_DB6	GPIOC
#define PIN_LCD_DB7		GPIO_Pin_6
#define PORT_LCD_DB7	GPIOC
