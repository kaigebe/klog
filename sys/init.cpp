#include <iostream>
#include <pthread.h>
#include<ctime>
#include<string>

using namespace std;

#include "init.h"
#include "config.h"

pthread_mutex_t g_Lock2;

int CheckSysInit()
{
    static bool sb_isSysInit = false;

    if(!sb_isSysInit)
    {
        pthread_mutex_lock(&g_Lock2);
        sb_isSysInit = !sb_isSysInit;
        pthread_mutex_unlock(&g_Lock2);
        if(sb_isSysInit)
        {
            LogSysInit();
        }
    }
}

void GetCurTime(int *curtime)
{
    time_t rawTime;
    struct tm *pst_TimeInfo;

    time(&rawTime);
    pst_TimeInfo = localtime(&rawTime);

    curtime[YEAR] = pst_TimeInfo->tm_year + 1900;
    curtime[MON] = pst_TimeInfo->tm_mon + 1;
    curtime[MDAY] = pst_TimeInfo->tm_mday;
    curtime[HOUR] = pst_TimeInfo->tm_hour;
    curtime[MIN] = pst_TimeInfo->tm_min;
    curtime[SEC] = pst_TimeInfo->tm_sec;
}

void* Print2Dev(void*)
{
    //怎么去输出呢？
}

void LogSysInit()
{
    pthread_t pid;

    ReadConfigFile();
    pthread_create(&pid,NULL,Print2Dev,NULL);

}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

