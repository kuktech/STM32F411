#include "ap.h"
#include "bsp.h"
#include "cli.h"


void cliTest(cli_args_t *args);

void apInit()
{
    logPrintf("stm32cli V1.0\n");

    cliOpen(_DEF_UART1, 57600);

    cilAdd("test", cliTest);
}

void apMain(int argc, char *argv[])
{
    uint32_t pre_time;

    pre_time = millis();
    while(1)
    {
        if(millis() - pre_time >= 500)
        {
            pre_time = millis();
        }
        cliMain();
    }
}

void apExit(void)
{
  printf("\ncli exit\n");
  exit(0);
}


void cliTest(cli_args_t *args)
{
    bool ret = false;

    if(args->argc==1 &&args->isStr(0,"cnt") ==true)
    {
        while(cliKeepLoop())
        {
            cliPrintf("cnt = %d\n", cnt++);
            delay(500);
        }
    }
    
    if(ret != true)
    {
        cliPrintf("test cnt\n");
    }
}