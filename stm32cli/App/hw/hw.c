#include "hw.h"
#include "button.h"
#include "def.h"


void hwInit(){
    bspInit();
   
    cliInit();
    uartInit();

}