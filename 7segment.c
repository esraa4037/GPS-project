
#include "tm4c123gh6pm.h"
unsigned int mask(unsigned int no){
	unsigned int x;
	if(no == 0){
		x = 0x3f;
	}
	else if(no == 1){
		x = 0x06;
	}
	else if(no == 2){
		x = 0x5b;
	}
	else if(no == 3){
		x = 0x4f;
	}
	else if(no == 4){
		x = 0x66;
	}
	else if(no == 5){
		x = 0x6d;
	}
	else if(no == 6){
		x = 0x7d;
	}
	else if(no == 7){
		x = 0x07;
	}
	else if(no == 8){
		x = 0x7f;
	}
	else if(no == 9){
		x = 0x6f;
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
		GPIO_PORTD_DATA_R = mask1;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x01;
		delay();
		
		GPIO_PORTD_DATA_R = mask2;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x02;
		delay();
		
		GPIO_PORTD_DATA_R = mask3;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x04;
		delay();
	}
	
}

void SystemInit(){}


int main(){

	
}
