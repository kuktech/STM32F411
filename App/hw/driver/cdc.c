#include "cdc.h"

#ifdef _USE_HW_CDC

static bool is_init = false;

bool cdcInit(){
    bool ret = true;

    is_init = ret;

    return ret;
}

bool cdcIsInit(){
    return is_init;
}
#endif