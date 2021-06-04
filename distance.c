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


int main () {

    ////////////////// calculate the total distance ////////////
    int total_distance = 0;
    char start[] = read();     //To read the start point of the jurney {latitude1 , longitude1}
    int startPoin[1] = parse(start);  //int startPoin[1] = {lat1, lon1};
    while (GPIO_PORTF_DATA_R & 0x00000001 != 0)
        {
            string end = read();
            int second_point[1] = parse(end);  //int second_point[1] = {lat2, lon2};
            total_distance += distance(startPoin[0], startPoin[1],
                                       second_point[0], second_point[1] ); // increment the total distance
	    print(total_distance);//to display distance in 7 segment

            // Let the second point to be the first point in the next cycle of the loop
            startPoin[0] = second_point[0];
            startPoin[1] = second_point[1];
            delay();
        }
	

   
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
