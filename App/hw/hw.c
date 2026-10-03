#include "hw.h"
#include "button.h"

void hwInit(){
    bspInit();
   
    cliInit();
    ledInit();
    usbInit();
    uartInit();
    buttonInit();
}