#include "lpc17xx.h"
#include "led.h"


/*----------------------------------------------------------------------------
  Used defined functions
 *----------------------------------------------------------------------------*/
//Leds mapping:
//	LED		PIN		NUM
//	LD11 	p2.0	7
//	LD10 	p2.1	6
//	LD9  	p2.2	5
//	LD8  	p2.3	4
//	LD7  	p2.4	3
//	LD6  	p2.5	2
//	LD5  	p2.6	1
//	LD4  	p2.7	0

void Led_ON(unsigned int num){
	if(num > 7) //NON-REQUIRED error checking
		num = 7; //There are only 8 leds on board.
	LPC_GPIO2->FIOSET = 1 << (7 - num);
}

void Led_OFF(unsigned int num){
	if(num > 7) //NON-REQUIRED error checking
		num = 7; //There are only 8 leds on board.
	LPC_GPIO2->FIOCLR = 1 << (7 - num);
}

void Led_AllOFF(){
	//Turn OFF all the leds.
	//	=> Clear all bits from 0 to 7
	//	=> Set FIOCLR bits 0-7 to 1 => 0xFF
	LPC_GPIO2->FIOCLR = 0xFF;
}

void Led_AllON(){
	//Turn ON all the leds.
	//	=> Clear all bits from 0 to 7
	//	=> Set FIOCLR bits 0-7 to 1 => 0xFF
	LPC_GPIO2->FIOSET = 0xFF;
}

int Led_IsON(unsigned int num){
	//Steps for checking:
	//	- Mask FIOPIN value according to the bit we're interested in
	//	- Shift the result right so that it becomes the LSB
	//	- Check if result is 1 :)
	return ((LPC_GPIO2->FIOPIN & (1 << (7 - num))) >> (7 - num) ) == 1;
}

void Led_BinaryNumber(uint8_t val){
	//Led 11 (7) correspond to LSB of value to be represented.
	Led_AllOFF();
	LPC_GPIO2->FIOPIN |= val;//Assign val to lower 8 bits
}

void Led_InvertedBinaryNumber(uint8_t val){
	Led_BinaryNumber(val ^ 0xff);
}


void Led_BlinkTwo(unsigned int num1, unsigned int num2){
	if(Led_IsON(num1)){
		Led_OFF(num1);
		Led_ON(num2);
	}
	else if(Led_IsON(num2)){
		Led_OFF(num2);
		Led_ON(num1);
	}
	else {
		Led_ON(num1);
	}
}
