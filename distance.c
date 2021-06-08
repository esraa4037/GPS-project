#include <stdio.h>
#include "stdint.h"
#include <math.h>
#define PI 3.14159265
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
    delay();//delay for GPS fix
    double total_distance = 0;
    char start[] = read();     //To read the start point of the jurney {latitude1 , longitude1}
    int startPoin[1] = parse(start);  //int startPoin[1] = {lat1, lon1};
    while ( (GPIO_PORTF_DATA_R & 0x01) != 0)
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


int main () {
	 total_distance();  // this will invoke the print() function and led()
   return(0);
}



////////////These functions will be implemented in the second milestone /////////
/////////////////////////////////////////////////////////////////////////////////
/*
 *
 // A function reads from gps
char* read(){
  string d="";
  //////
  //////
  }
  return d;
  }


 //this function takes the string from function read()
 //and then return langitude and longitude in int array (size: 2)
  int * parse(string s){
  ///////
  ///////
  return arr;
    }




*/
