#pragma once
#ifndef LOG_API_H
#define LOG_API_H

void (*Log)(string tag,string msg);
void LOG(string tag,string msg);
void LogD(string tag,string msg);
void LogE(string tag,string msg);
void LogI(string tag,string msg);
void LogW(string tag,string msg);


#define THRESHOLD_OUT 3
#define THRESHOLD_ERR 1

#define VERBOSE 5
#define DEBUG 4
#define INFO 3
#define WARNING 2
#define ERROR 1
#define Print(f,str,x...) do{sprintf(f,"%s:%s" str,__FUNCTION__,__LINE__,##x)}while(0)

#define LogPrint(level,x...) do{ \
        if(THRESHOLD_OUT >= level){ \
            Print(THRESHOLD_ERR >= level?stderr:stdout,x); \
           }\
        }while(0)

#define LogD(x...) LogPrint(DEBUG,x)
#define LogI(x...) LogPrint(INFO,x)
#define LogE(x...) LogPrint(ERROR,x)
#define LogV(x...) LogPrint(VERBOSE,x)
#define LogW(x...) LogPrint(WARNING,x)

#endif //LOG_API_H

