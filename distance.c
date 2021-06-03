#include <stdio.h>
#include "stdint.h"
#include <math.h>
#define PI 3.14159265
double degToRad(double deg) {
  return deg * PI / 180;
}

double distance(double latitude1, double latitude2, double longitude1,double longitude2) {

  double a =  pow(sin(degToRad(latitude2-latitude1)/2),2)+ pow(sin(degToRad(longitude2-longitude1)/2),2) * cos(degToRad(latitude2) )* cos(degToRad(latitude1)); 
  double c = 2 * atan2(sqrt(a),sqrt(1-a)); 
  return 6371 * c;
}
int main () {
//    double x, ret, val;

//    x = 45.0;
//    val = PI / 180;
//    ret = sin(x*val);
   distance(0,0,0,0);
  // printf(" %lf ", sine(90));
   
   return(0);
	
}
