#ifndef __BUTTON_H
#define __BUTTON_H

void BUTTON_init(void);

void EINT1_IRQHandler(void);
void EINT2_IRQHandler(void);
void EINT3_IRQHandler(void);

/* funct_button.c */
void init_button_handlers(void);
void set_button_handler(int index, void (*handler)(int));
void clear_button_handler(int index);
void handle_button(int index);

#endif
