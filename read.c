#include <stdio.h>
#include <math.h>
#include "stdint.h"
#include <tm4c123gh6pm.h>
#define MAX 500
int avalible(){
	return ((UART2_FR_R  & (1<<4)) ==0)?0:1;
}
char readChar(){
	while(availble()!=1);
	return UART2_DR_R & 0xFF;
}
char* readStr(){
	UART0_CTL_R|=0x301;
	char str[MAX];
	char cstr;
	while(readChar()!="$");
	for(int i=0;i<MAX;i++){
		cstr=readChar();
		if(cstr=="\n" || cstr=="\r")
		    break;
		else
			str[i]=cstr;
	UART2_CTL_R|=0x201;//disable rx here
     return str;
	}

}
/*
UART0_CTL_R|=0x301;
while((UART2_FR_R  & (1<<4))!=0){
	if(UART2_DR_R !="$")
	    continue;
	else if(UART2_DR_R =="\n" || UART2_DR_R !="\r")
	    break;
	else if{
		str[i]=UART2_DR_R;
	}
	UART2_CTL_R|=0x201;//disable rx here

}
*/
