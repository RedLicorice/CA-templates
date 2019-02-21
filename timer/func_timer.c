#include "lpc17xx.h"
#include <string.h>
#include "timer.h"

void (*timer_handlers[4])(int);

void init_timer_handlers(){
	memset(timer_handlers, 0x00, sizeof(timer_handlers));
}

/******************************************************************************
** Function name:		set_timer_handler
**
** Descriptions:		Set handler for specified timer
**
** parameters:			timer index: 0 or 1 or 2 or 3, handler (functor)
**									handler must be a pointer to function void handler(int timer_index)
** Returned value:		None
**
******************************************************************************/
void set_timer_handler(int index, void (*handler)(int)){
	if(index >= 4)
		return;
	timer_handlers[index] = handler;
}

/******************************************************************************
** Function name:		clear_timer_handler
**
** Descriptions:		Clear handler for specified timer
**
** parameters:			timer index: 0 or 1 or 2 or 3
** Returned value:		None
**
******************************************************************************/
void clear_timer_handler(int index){
	if(index >= 4)
		return;
	timer_handlers[index] = 0x00;
}

/******************************************************************************
** Function name:		handle_timer
**
** Descriptions:		Handle interrupt for specified timer by calling set
**									handler function, passing current timer index as argument
**
** parameters:			timer index: 0 or 1 or 2 or 3
** Returned value:		None
**
******************************************************************************/
void handle_timer(int index){
	if(index >= 4)
		return;
	if(timer_handlers[index] != 0x00){
		(*timer_handlers[index])(index);
	}
}
