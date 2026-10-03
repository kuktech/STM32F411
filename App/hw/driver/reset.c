#include "reset.h"
#include "rtc.h"

static uint32_t reset_count = 0;

bool resetInit(){
    bool ret = true;

    if(RCC->CSR & (1<<26)){  //reset pin이 눌렸다면
        rtcBackupRegWrite(1, rtcBackupRegRead(1) + 1);
        delay(500);
        reset_count = rtcBackupRegRead(1);
    }

    return ret;
}

uint32_t resetGetCount(){


    return reset_count;
}
