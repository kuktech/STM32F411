#include "hw.h"
#include "button.h"
#include "def.h"


void hwInit(){
    bspInit();
   
    cliInit();
    ledInit();
    usbInit();
    uartInit();
    buttonInit();
    gpioInit();
    ymodemInit();


 
    usbBegin(USB_CDC_MODE);


}