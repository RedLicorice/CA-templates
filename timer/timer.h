/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           timer.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_timer, funct_timer, IRQ_timer .c files
** Correlated files:    lib_timer.c, funct_timer.c, IRQ_timer.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#ifndef __TIMER_H
#define __TIMER_H
#define TIMER_FREQ_KHZ 25000
/* init_timer.c */
extern uint32_t init_timer( uint8_t timer_num, uint32_t timerInterval );
extern uint32_t init_timer_millis( uint8_t timer_num, uint32_t milliseconds );
extern void enable_timer( uint8_t timer_num );
extern void disable_timer( uint8_t timer_num );
extern void reset_timer( uint8_t timer_num );
extern uint32_t is_timer_enabled ( uint8_t timer_num );
extern uint32_t read_timer_value ( uint8_t timer_num);

/* IRQ_timer.c */
extern void TIMER0_IRQHandler (void);
extern void TIMER1_IRQHandler (void);
extern void TIMER2_IRQHandler (void);
extern void TIMER3_IRQHandler (void);

/* func_timer.c */
extern void init_timer_handlers(void);
extern void set_timer_handler(int index, void (*handler)(int));
extern void clear_timer_handler(int index);
extern void handle_timer(int index);

#endif 
/* end __TIMER_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
