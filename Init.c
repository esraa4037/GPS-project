#include "tm4c123gh6pm.h"
#include "Init.h"


void PortB_Init(){
SYSCTL_RCGCGPIO_R |=0x2;
while((SYSCTL_PRGPIO_R & 0x2)==0);
GPIO_PORTB_LOCK_R =	Lock_key;
GPIO_PORTB_CR_R =PB_mask ;
GPIO_PORTB_DIR_R =PB_mask;
GPIO_PORTB_DEN_R =PB_mask;
GPIO_PORTB_AMSEL_R &=~ PB_mask;
GPIO_PORTB_AFSEL_R &=~ PB_mask;
GPIO_PORTB_PCTL_R &=~ 0xffffffff;
GPIO_PORTB_DATA_R &=~ PB_mask; 	
	
}

void PortE_Init(){
SYSCTL_RCGCGPIO_R |=0x10;
while((SYSCTL_PRGPIO_R & 0x10)== 0);
GPIO_PORTE_CR_R |= PE0123_mask;
GPIO_PORTE_DIR_R |= PE0123_mask;
GPIO_PORTE_DEN_R |= PE0123_mask;
GPIO_PORTE_AMSEL_R &=~ PE0123_mask;
GPIO_PORTE_AFSEL_R &=~ PE0123_mask;
GPIO_PORTE_PCTL_R &=~ 0xffff;	
GPIO_PORTE_DATA_R &=~ PE0123_mask;	
}

void Sw2_Init(){
SYSCTL_RCGCGPIO_R |=0x20;
while ((SYSCTL_PRGPIO_R &0x20) == 0);
GPIO_PORTF_LOCK_R =	Lock_key;
GPIO_PORTF_CR_R |= PF0_mask;
GPIO_PORTF_DIR_R &=~ PF0_mask;
GPIO_PORTF_DEN_R |= PF0_mask;
GPIO_PORTF_AMSEL_R &=~ PF0_mask;
GPIO_PORTF_AFSEL_R &=~ PF0_mask;
GPIO_PORTF_PCTL_R &=~ 0xF;	
GPIO_PORTF_PUR_R |=PF0_mask;	
}

void Rled_Init(){
SYSCTL_RCGCGPIO_R |=0x20;
while ((SYSCTL_PRGPIO_R &0x20) == 0);
GPIO_PORTF_LOCK_R =	Lock_key;
GPIO_PORTF_CR_R |= PF1_mask;
GPIO_PORTF_DIR_R |= PF1_mask;
GPIO_PORTF_DEN_R |= PF1_mask;
GPIO_PORTF_AMSEL_R &=~ PF1_mask;
GPIO_PORTF_AFSEL_R &=~ PF1_mask;
GPIO_PORTF_PCTL_R &=~ 0xf0;	
GPIO_PORTF_DATA_R &=~ PF1_mask;	
	
}

void SystemInit(){}


int main(){
Rled_Init();	
Sw2_Init();
PortB_Init();
PortE_Init();	

	
}
