#include <iostream>

using namespace std;

#include"mem.h"
#include "log_api.h"

//使用工厂模式,突然觉的我好棒棒

class Log{
public:
    virtual void LogPrint(const string tag,const string msg) = 0;
    virtual ~Log(){}
    static Log* Factory(const string& level);
};

class LogD : public Log{
public:
    void LogPrint(const string tag,const string msg){
    cout << "debug"<<endl;
    //...
    }
    ~LogD(){}
};

class LogW :public Log{
public:
    void LogPrint(const string tag,const string msg){
    cout << "warning"<<endl;
    //...
    }
    ~LogW(){}
};

class LogE : public Log{
public:
    void LogPrint(const string tag,const string msg){
        cout << "error"<<endl;
        //...
    }
    ~LogE(){}
};

class LogI : public Log{
public:
    void LogPrint(const string tag,const string msg){
        cout << "Info" <<endl;
        //...
    }
    ~LogI(){}
};

class LogV:public Log{
public:
    void LogPrint(const string tag,const string msg){
        cout << "verbose"<<endl;
        //...
    }
};

Log* Log::Factory(const string &level)
{
    if(level == "debug")
    {
        return new LogD;
    }
    else if(level == "error")
    {
        return new LogE;
    }
    else if(level == "warning")
    {
        return new LogW;
    }
    else if(level == "Info")
    {
        return new LogI;
    }
    else if(level == "verbose")
    {
        return new LogV;
    }
    else
    {
        return NULL;
    }
}
/*
void LOG(string tag,string msg)
{
    ApiPush(tag,msg);
}
*/

void LogD(string tag,string msg)
{
    Log *lg;
    lg = Log::Factory("debug");
    lg->LogPrint(tag,msg);
    delete lg;
}

void LogV(string tag,string msg)
{
    Log *lg;
    lg = Log::Factory("verbose");
    lg->LogPrint(tag,msg);
    delete lg;
}

void LogW(string tag,string msg)
{
    Log *lg;
    lg = Log::Factory("warning");
    lg->LogPrint(tag,msg);
    delete lg;
}

void LogE(string tag,string msg)
{
    Log* lg;
    lg = Log::Factory("error");
    lg->LogPrint(tag,msg);
    delete lg;
}

void LogI(string tag,string msg)
{
    Log* lg;
    lg = Log::Factory("Info");
    lg->LogPrint(tag,msg);
    delete lg;
}

int main()
{
    string tag = "[KAI.GE]";
    string msg = "this is a meaaage.";
    LogD(tag,msg);
    LogW(tag,msg);
    LogE(tag,msg);
    LogV(tag,msg);
    LogI(tag,msg);

    return 0;
}

