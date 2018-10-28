#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <pthread.h>

using namespace std;

static pthread_mutex_t g_Lock;//PTHREAD_MUTEX_INITIALIZER;

class AutoLock{

    pthread_mutex_t *m_lock;
public:
    AutoLock(pthread_mutex_t &Lock)
    {
    //    cout << "lock"<<endl;
        m_lock = &Lock;
        pthread_mutex_lock(m_lock);
    }
    ~AutoLock()
    {
    //    cout <<"unlock"<<endl;
        pthread_mutex_unlock(m_lock);
    }
};

queue<string> g_queueLogMessage;
queue<string> g_queueLogTag;

void MessagePush(string tag,string msg)
{
    AutoLock Lock(g_Lock);
    g_queueLogMessage.push(msg);
    g_queueLogTag.push(tag);
}

void MessagePop()
{
    AutoLock Lock(g_Lock);
    g_queueLogMessage.pop();
    g_queueLogTag.pop();
}

void ApiPush(string tag,string msg)
{
    MessagePush(tag,msg);
}

void ApiPop()
{
    MessagePop();
}

