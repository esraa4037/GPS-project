void SystemInit() {}

void portF_init(void) {
    uint32_t delay;
    SYSCTL_RCGCGPIO_R |= 0x20;
    delay = 1;
    GPIO_PORTF_LOCK_R = 0X4C4F434B;
   // GPIO_PORTF_RC_R = 0X1F;
    GPIO_PORTF_AFSEL_R = 0;
    GPIO_PORTF_PCTL_R = 0;
    GPIO_PORTF_AMSEL_R = 0;
    GPIO_PORTF_DEN_R = 0X1F;
    GPIO_PORTF_DIR_R = 0X0E;
    GPIO_PORTF_PUR_R = 0X11;

}

// initialization for systick timer

void one_second_delay()
{
    NVIC_ST_CTRL_R = 0;  //DISABLE TIMER
    NVIC_ST_RELOAD_R = 16000000 - 1;
    NVIC_ST_CURRENT_R = 0;  // clears the current register and the count flag
    NVIC_ST_CTRL_R = 5;  // set the enable and clock source to 1
    if (NVIC_ST_CTRL_R & 0x10000 == 0) { }
}



// this function makes a delay in seconds
//it takes the number of seconds and number of counts that makes a one second delay(about 16,000,000 counts)
void delay_in_seconds(int seconds)
{
    int i;
    for (i=0; i<seconds; i++){
        one_second_delay();
    }
}
/*
void sysTick_delay(uint32_t counts){
    NVIC_ST_CTRL_R = 0;  //DISABLE TIMER
    NVIC_ST_RELOAD_R = counts;
    NVIC_ST_CURRENT_R = 0;  // clears the current register and the count flag
    NVIC_ST_CTRL_R = 5;  // set the enable and clock source to 1

    if (NVIC_ST_CTRL_R & 0x10000 == 0) { }

}
*/

int main()
{
    portF_init();
    
    while(1){
        GPIO_PORTF_DATA_R ^= 0x02;
        delay_in_seconds(5);
    }
}

