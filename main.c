int main(){
SCB->CPACR|=((3UL<<10*2)|(3UL<<11*2-2));	
Rled_Init();	
Sw2_Init();
PortB_Init();
PortE_Init();
UART_Init();
	

//total_distance();
	 delay_in_seconds(30);//delay for GPS fix
    double total_distance = 0;
    char* first = readStr();    //To read the start point of the jurney {latitude1 , longitude1}
	st=GPS_time(first);
	parseLat (first);
	parseLng (first);
	double lat1=GPS_decimal( lat , latDir(first));
	double lon1=GPS_decimal( lng  , lngDir(first));
    // int startPoin[1] = parse(start);  //int startPoin[1] = {lat1, lon1};
    while ( (GPIO_PORTF_DATA_R & 0x01) != 0)
        {
			char* second = readStr();
	       en=GPS_time(second);
			parseLat (second);
	        parseLng (second);
	        double lat2=GPS_decimal( lat , latDir(second));
	        double lon2=GPS_decimal( lng  , lngDir(second));
            // string end = read();
            // int second_point[1] = parse(end);  //int second_point[1] = {lat2, lon2};
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
