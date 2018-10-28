#ifndef LOG_MEM_H_
#define LOG_MEM_H_

class AutoLock;

void MessagePop(void);

void MessagePush(string tag,string msg);

void ApiPush(string tag,string msg);

void ApiPop(void);

#endif //LOG_MEM_H_
