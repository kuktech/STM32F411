#include "ap.h"
#include "cli.h"
#include "uart.h"

void apInit(){
    cliOpen(_DEF_UART1, 57600);
}

void apMain(){
    uint32_t pre_time;
    pre_time = millis();
    while(1){
        if(millis() - pre_time >= 500){
            pre_time = millis();
            ledToggle(_DEF_LED1);
        }

        cliMain();
    }
}


