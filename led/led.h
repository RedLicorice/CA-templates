/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** Descriptions:        Prototypes of functions included in the lib_led, funct_led .c files
** Correlated files:    lib_led.c, funct_led.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

/* lib_led */
void LED_init(void);
void LED_deinit(void);

/* funct_led */
void Led_ON(unsigned int num);
void Led_OFF(unsigned int num);
void Led_AllOFF(void);
void Led_AllON(void);
int Led_IsON(unsigned int num);
void Led_BinaryNumber(uint8_t val);
void Led_InvertedBinaryNumber(uint8_t val);
void Led_BlinkTwo(unsigned int num1, unsigned int num2);
