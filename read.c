#include <stdio.h>
#include <math.h>
#include "stdint.h"
#include <tm4c123gh6pm.h>
#define MAX 200

int availble(){
	return ((UART2_FR_R  & (1<<4)) ==0)?1:0;
}
char readChar(){
	while(availble()!=1);
	return UART2_DR_R & 0xFF;
}
char str[MAX];//global variable 
char* readStr(){
	UART2_CTL_R|=0x301;	
	char cstr;
	int valid=1;
        while(valid==1){
	    while(readChar()!='$'){};
            str[0]='$';
	   if(readChar()=='G'){
                 str[1]='G';
		if(readChar()=='p'){
                       str[2]='p';
		       if(readChar()=='G'){
                             str[3]='G';
			     if(readChar()=='G'){
                                     str[4]='G';
				     if(readChar()=='A'){
                                           str[5]='A';
                                           valid=0;
					   GPIO_PORTF_DATA_R |=0X04;
                                           for(int i=6;i<MAX;i++){
		                                cstr=readChar();
		                                 if(cstr=='\n' || cstr=='\r')
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
UART2_CTL_R|=0x001;
return str;
}




  
