#include "tm4c123gh6pm.h"
#include "Init.h"
#define PF2_mask  0x04


void Bled_Init(){
SYSCTL_RCGCGPIO_R |=0x20;
while ((SYSCTL_PRGPIO_R &0x20) == 0);
GPIO_PORTF_LOCK_R =	Lock_key;
GPIO_PORTF_CR_R |= PF2_mask;
GPIO_PORTF_DIR_R |= PF2_mask;
GPIO_PORTF_DEN_R |= PF2_mask;
GPIO_PORTF_AMSEL_R &=~ PF2_mask;
GPIO_PORTF_AFSEL_R &=~ PF2_mask;
GPIO_PORTF_PCTL_R &=~ 0xf00;	
GPIO_PORTF_DATA_R &=~ PF2_mask;	
}