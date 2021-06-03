#include "tm4c123gh6pm.h"
#include "Init.h"


void PortD_Init(){
SYSCTL_RCGCGPIO_R |=0x8;
while((SYSCTL_PRGPIO_R & 0x8)==0);
GPIO_PORTD_LOCK_R =	Lock_key;
GPIO_PORTD_CR_R =PD_mask ;
GPIO_PORTD_DIR_R =PD_mask;
GPIO_PORTD_DEN_R =PD_mask;
GPIO_PORTD_AMSEL_R &=~ PD_mask;
GPIO_PORTD_AFSEL_R &=~ PD_mask;
GPIO_PORTD_PCTL_R &=~ 0xffffffff;
GPIO_PORTD_DATA_R &=~ PD_mask; 	
	
}

void PortE_Init(){
SYSCTL_RCGCGPIO_R |=0x10;
while((SYSCTL_PRGPIO_R & 0x10)== 0);
GPIO_PORTE_CR_R |= PE0123_mask;
GPIO_PORTE_DIR_R &=~ PE0123_mask;
GPIO_PORTE_DEN_R |= PE0123_mask;
GPIO_PORTE_AMSEL_R &=~ PE0123_mask;
GPIO_PORTE_AFSEL_R &=~ PE0123_mask;
GPIO_PORTE_PCTL_R &=~ 0xffff;	
GPIO_PORTE_DATA_R &=~ PE0123_mask;	
}

