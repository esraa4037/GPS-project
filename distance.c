#include <stdio.h>
#include "stdint.h"
#include <math.h>
#define PI 3.14159265
double degToRad(double deg) {
  return deg * PI / 180;
}
int power(int base, int exponent)
{
int product=1;
for (int i=exponent; i>0; i--)
{
product = product * base;
}
return product;
}
unsigned factorial(unsigned n)
{
   unsigned c;
   unsigned result = 1;
 
   for( c = 1 ; c <= n ; c++ )
         result = result*c;
 
   return ( result );
}
double sin(double x){
	double res=x-(power(x,3))/factorial(3)+(power(x,5))/factorial(5)-power(x,7)/factorial(7);
	return res;
}

double distance(double latitude1, double latitude2, double longitude1,double longitude2) {

  double a =  pow(sin(degToRad(latitude2-latitude1)/2),2)+ pow(sin(degToRad(longitude2-longitude1)/2),2) * cos(degToRad(latitude2) )* cos(degToRad(latitude1)); 
  double c = 2 * atan2(sqrt(a),sqrt(1-a)); 
  return 6371 * c;
}
double sine (double x){
    int i = 1;
    double cur = x;
    double acc = 1;
    double fact= 1;
    double pow = x;
    while (fabs(acc) > .00000001 &&   i < 100){
        fact *= ((2*i)*(2*i+1));
        pow *= -1 * x*x; 
        acc =  pow / fact;
        cur += acc;
        i++;
    }
    return cur;

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