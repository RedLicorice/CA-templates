#include "lpc17xx.h"
#include <string.h>
#include "button.h"
#include "..\timer\timer.h"

 //Buttons mapping:
 //	BUTTON	PIN		INTERRUPT		INDEX
 //	INT0		p2.10		EINT0				0
 //	KEY1		p2.11		EINT1				1
 //	KEY2		p2.12		EINT2				2
 
 //#define USE_DEBOUNCE_TIMER
 #define DEBOUNCE_TIMER_INDEX 1
 #define DEBOUNCE_TIMER_INTERVAL 20000
 #define DEBOUNCE_TIMER_DELAY 5
 
void (*button_handlers[3])(int);
#ifdef USE_DEBOUNCE_TIMER
uint32_t button_debounces[3];
#endif

void init_button_handlers(){
	memset(button_handlers, 0x00, sizeof(button_handlers));
#ifdef USE_DEBOUNCE_TIMER
	memset(button_debounces, 0x00, sizeof(button_debounces));
	init_timer_millis( DEBOUNCE_TIMER_INDEX, DEBOUNCE_TIMER_INTERVAL );
	enable_timer( DEBOUNCE_TIMER_INDEX );
#endif
}

/******************************************************************************
** Function name:		set_button_handler
**
** Descriptions:		Set handler for specified button
**
** parameters:			button index: 0 or 1 or 2, handler (functor)
**									handler must be a pointer to function void handler(int button_index)
** Returned value:		None
**
******************************************************************************/
void set_button_handler(int index, void (*handler)(int)){
	if(index >= 3)
		return;
	button_handlers[index] = handler;
}

/******************************************************************************
** Function name:		clear_button_handler
**
** Descriptions:		Clear handler for specified button
**
** parameters:			button index: 0 or 1 or 2
** Returned value:		None
**
******************************************************************************/
void clear_button_handler(int index){
	if(index >= 3)
		return;
	button_handlers[index] = 0x00;
}

/******************************************************************************
** Function name:		handle_button
**
** Descriptions:		Handle interrupt for specified button by calling set
**									handler function, passing current timer index as argument.
**									Debouncing is included.
**
** parameters:			button index: 0 or 1 or 2
** Returned value:		None
**
******************************************************************************/
void handle_button(int index){
	if(index >= 3)
		return;
#ifdef USE_DEBOUNCE_TIMER
	if(button_debounces[index] != 0){
		if(read_timer_value(DEBOUNCE_TIMER_INDEX) < button_debounces[index]){
			return; //Wait a little more
		}
	}
	button_debounces[index] = read_timer_value(DEBOUNCE_TIMER_INDEX) + DEBOUNCE_TIMER_DELAY;
#endif
	if(button_handlers[index] != 0x00){
		(*button_handlers[index])(index);
	}
}
