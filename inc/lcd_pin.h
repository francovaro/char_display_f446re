#include "stm32f4xx.h"

/* PIN definition */

/* LCD enable*/
#define PIN_LCD_ENABLE	GPIO_Pin_8
#define PORT_LCD_ENABLE	GPIOA
/* LCD Read Write */
#define PIN_LCD_RW		GPIO_Pin_9
#define PORT_LCD_RW		GPIOA
/* LCD Register Command*/
#define PIN_LCD_RS		GPIO_Pin_10
#define PORT_LCD_RS		GPIOA
/* LCD Datab Bus pin*/
#define PORT_LCD_DBx	GPIOA

#define PIN_LCD_DB0		GPIO_Pin_0
#define PORT_LCD_DB0	GPIOA
#define PIN_LCD_DB1		GPIO_Pin_1
#define PORT_LCD_DB1	GPIOA
#define PIN_LCD_DB2		GPIO_Pin_2
#define PORT_LCD_DB2	GPIOA
#define PIN_LCD_DB3		GPIO_Pin_3
#define PORT_LCD_DB3	GPIOA
#define PIN_LCD_DB4		GPIO_Pin_4
#define PORT_LCD_DB4	GPIOA
#define PIN_LCD_DB5		GPIO_Pin_5
#define PORT_LCD_DB5	GPIOA
#define PIN_LCD_DB6		GPIO_Pin_6
#define PORT_LCD_DB6	GPIOA
#define PIN_LCD_DB7		GPIO_Pin_7
#define PORT_LCD_DB7	GPIOA
