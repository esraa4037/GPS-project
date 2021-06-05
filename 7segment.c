
#include "tm4c123gh6pm.h"
unsigned int mask(unsigned int no){
unsigned int x;
	if(no == 0){
		x = 0xc0;
	}
	else if(no == 1){
		x = 249;
	}
	else if(no == 2){
		x = 164;
	}
	else if(no == 3){
		x = 176;
	}
	else if(no == 4){
		x = 153;
	}
	else if(no == 5){
		x = 146;
	}
	else if(no == 6){
		x = 130;
	}
	else if(no == 7){
		x = 248;
	}
	else if(no == 8){
		x = 128;
	}
	else if(no == 9){
		x = 246;
	}					
	return x;
}


unsigned int i;
// check the 7 segment transition
void delay(void){
  for( i = 0; i < 1250/10; i++){
  } 
}

unsigned int digit1;
unsigned int digit2;
unsigned int digit3;
unsigned int mask1;
unsigned int mask2;
unsigned int mask3;

void print(int distance){
	 digit1 = distance/100;
	distance %= 100;
	
	 digit2 = distance/10;
	distance %= 10;

	digit3 = distance;
	
	 mask1 = mask(digit1);
	 mask2 = mask(digit2);
	 mask3 = mask(digit3);
	
	while(1){
		GPIO_PORTB_DATA_R = mask1;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x01;
		delay();
		
		GPIO_PORTB_DATA_R = mask2;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x02;
		delay();
		
		GPIO_PORTB_DATA_R = mask3;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x04;
		delay();
	}
	
}

void SystemInit(){}


int main(){

	
}
