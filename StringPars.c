#include <string.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"

char lat[9] ;
char lng[10] ;

void parseLat (char string[500]){
	
	for(int i = 0; i < strlen(string); i++){
		if(string[i] == 'N' || string[i] == 'S'){
			for(int j = i-2; j >= 0; j--){
				if(string[j] == ',' ){
					int x = 0;
					for(int k = j+1; k < j+9; k++){
						lat[x] = string[k];
						x++;
					}
					break;
				}
				
			}
			
		}
		else {
			continue;
		}
		break;
	}
	
}

char latDir(char string[500]){
	char x;
	for(int i = 0; i < strlen(string); i++){
		if(string[i] == 'N' || string[i] == 'S'){
			x = string[i];
			break;
		}
	}
	return x;

}

char lngDir(char string[500]){
	char x;
	for(int i = 0; i < strlen(string); i++){
		if(string[i] == 'W' || string[i] == 'E'){
			x = string[i];
			break;
		}
	}
	return x;

}

void parseLng (char string[500]){
	
	for(int i = 0; i < strlen(string); i++){
		if(string[i] == 'E' || string[i] == 'W'){
			for(int j = i-2; j >= 0; j--){
				if(string[j] == ',' ){
					int x = 0;
					for(int k = j+1; k < j+10; k++){
						lng[x] = string[k];
						x++;
						
					}
					break;
				}
				
			}
			
		}
		else {
			continue;
		}
		break;
	}
	
}
void SystemInit(){
}

int main(){

	
}
