#include <iostream>

using namespace std;

#include"mem.h"
#include "log_api.h"

void LOG(string tag,string msg)
{
    ApiPush(tag,msg);
}

int main()
{
    string tag = "kai.ge";
    string msg = "hello world\n";
    LOG(tag,msg);
    std::cout << "Hello world" << std::endl;
    return 0;
}

