#include <stdio.h>
#include <math.h>
#include "stdint.h"
#include <tm4c123gh6pm.h>
#define MAX 200
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
	while(readChar()!='$');
	if(readChar()=='G'){
		if(readChar()=='p'){
			if(readChar()=='G'){
				if(readChar()=='G'){
					if(if(readChar()=='A')){
						    str[0:5]="$GPGGA";//NOT SURE
							for(int i=0;i<MAX;i++){
		                        cstr=readChar();
		                        if(cstr=="\n" || cstr=="\r")
		                            break;
		                        else
			                    str[i]=cstr;
					             }
				}
			}
		}
	}

}
}