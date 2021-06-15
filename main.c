int main(){
SCB->CPACR|=((3UL<<10*2)|(3UL<<11*2-2));	
Rled_Init();	
Sw2_Init();
PortB_Init();
PortE_Init();
UART_Init();
	

//track the distance
 delay_in_seconds(30);//delay for GPS fix
double total_distance = 0;
char* first = readStr();    //read first point from GPS
st=GPS_time(first);         
parseLat (first);          //get latitude from GPS format for the first point
parseLng (first);          //get longitude from GPS format for the first point
double lat1=GPS_decimal( lat , latDir(first));  //get real value of latitude from GPS format for the first point
double lon1=GPS_decimal( lng  , lngDir(first)); //get real value of longitude from GPS format for the first point
while ( (GPIO_PORTF_DATA_R & 0x01) != 0)        // looping until pushing SW2
        {
	char* second = readStr();               //read second point from GPS
	en=GPS_time(second);                    
	parseLat (second);                       //get latitude from GPS format for the second point
	 parseLng (second);                      //get longitude from GPS format for the second point
	 double lat2=GPS_decimal( lat , latDir(second)); //get real value of latitude from GPS format for the second point
	 double lon2=GPS_decimal( lng  , lngDir(second)); //get real value of longitude from GPS format for the fsecond point
        total_distance += distance(lat1, lon1,lat2,lon2); // increment the total distance
	 print((int)total_distance);//to display the distance in 7 segment during the movement
	led(total_distance);// if total_distance>=100, the red led turns on

            // Let the second point to be the first point in the next cycle of the loop
         lat1 = lat2;
         lon1 = lon2;
        delay_in_seconds(5);
        }
	speed=travelspeed();
				
}
