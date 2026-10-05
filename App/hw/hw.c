#include "hw.h"
#include "button.h"

void hwInit(){
    bspInit();
   
    cliInit();
    ledInit();
    usbInit();
    uartInit();
    buttonInit();
    gpioInit();

    if(sdInit()==true){
        fatfsInit();
    }

    usbBegin(USB_MSC_MODE);
}