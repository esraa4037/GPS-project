void SystemInit() {}

void portF_init(void) {
    uint32_t delay;
    SYSCTL_RCGCGPIO_R |= 0x20;
    delay = 1;
    GPIO_PORTF_LOCK_R = 0X4C4F434B;
    GPIO_PORTF_AFSEL_R = 0;
    GPIO_PORTF_PCTL_R = 0;
    GPIO_PORTF_AMSEL_R = 0;
    GPIO_PORTF_DEN_R = 0X1F;
    GPIO_PORTF_DIR_R = 0X0E;
    GPIO_PORTF_PUR_R = 0X11;

}


void one_second_delay()
{
    NVIC_ST_CTRL_R = 0;  //DISABLE TIMER
    NVIC_ST_RELOAD_R = 16000000;
    NVIC_ST_CURRENT_R = 0;  // clears the current register and the count flag
    NVIC_ST_CTRL_R = 5;  // set the enable and clock source to 1
    
    While ( (NVIC_ST_CTRL_R & 0x10000) == 0) { }
}



// this function makes more than one second delay.
void delay_in_seconds(int seconds)
{
    int i;
    for (i=0; i<seconds; i++){
        one_second_delay();
    }
}


int main()
{
    portF_init();
    
    while(1){
        GPIO_PORTF_DATA_R ^= 0x02;
        delay_in_seconds(5);
    }
}

