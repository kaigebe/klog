#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

queue<string> g_queueLogMessage;
queue<string> g_queueLogTag;

map<string,string> g_mapCfgInfo;

void MessagePush(string tag,string msg)
{
    g_queueLogMessage.push(msg);
    g_queueLogTag.push(tag);
}

void MessagePop()
{
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

