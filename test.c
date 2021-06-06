#include "Init.h"
#include "tm4c123gh6pm.h"
#define PI 3.14159265
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

void led (double distance){ 
    if (distance >=100){  
          (GPIO_PORTF_DATA_R |=0X02);
						
			}
}

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
	if(distance >= 100 && distance <1000){
	 digit1 = distance/100;
	distance %= 100;
	mask1 = mask(digit1);

	}
	if(distance >= 10){
	 digit2 = distance/10;
	distance %= 10;
			 mask2 = mask(digit2);

	}

	digit3 = distance;
	
	 mask3 = mask(digit3);
	
	while(1){
		GPIO_PORTB_DATA_R = mask1;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x02;
		delay();
		
		GPIO_PORTB_DATA_R = mask2;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x04;
		delay();
		
		GPIO_PORTB_DATA_R = mask3;
		GPIO_PORTE_DATA_R &= ~0x0f;
		GPIO_PORTE_DATA_R |= 0x08;
		delay();
	}
	
}
double degToRad(double deg) {
  return deg * PI / 180;
}

////////// this function calulate the distance between two GPS points /////////////
double distance(double latitude1, double longitude1, double latitude2 ,double longitude2) {

  double a =  pow(sin(degToRad(latitude2-latitude1)/2),2)+
	  pow(sin(degToRad(longitude2-longitude1)/2),2) * cos(degToRad(latitude2) )* cos(degToRad(latitude1)); 
  double c = 2 * atan2(sqrt(a),sqrt(1-a));
  return 6371 * c;
}
////////////////// calculate the total distance ////////////
void total_distance(){
    double total_distance = 0;
    char start[] = read();     //To read the start point of the jurney {latitude1 , longitude1}, read() will be implemented in second milestone
    int startPoin[1] = parse(start);  //int startPoin[1] = {lat1, lon1}, parse() will be implemented in second milestone
    while (GPIO_PORTF_DATA_R & 0x00000001 != 0)
        {
            string end = read();
            int second_point[1] = parse(end);  //int second_point[1] = {lat2, lon2};
            total_distance += distance(startPoin[0], startPoin[1],
                                       second_point[0], second_point[1] ); // increment the total distance
	    print((int)total_distance);//to display the distance in 7 segment during the movement
	    led(total_distance);// if total_distance>=100, the red led turns on

            // Let the second point to be the first point in the next cycle of the loop
            startPoin[0] = second_point[0];
            startPoin[1] = second_point[1];
            delay();
        }

}


void SystemInit(){}


int main(){
	PortB_Init();
	PortE_Init();
	Sw2_Init();
        Rled_Init();
	led(100);
	print(120);
	//total_distance() will be called in second milestone
}
