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
    flashInit();
    spiInit();

    if(sdInit()==true){
        fatfsInit();
    }

    if(buttonGetPressed(_DEF_BUTTON1) == true && sdIsDetected() == true)
    {
        usbBegin(USB_MSC_MODE);
    }
    else
    {
        usbBegin(USB_CDC_MODE);
    }

    lcdInit();

}