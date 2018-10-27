#include <iostream>

using namespace std;

#include"mem.h"

int main()
{
    string msg = "hello world";
    string tag = "tag";
    ApiPush(tag,msg);
    ApiPop();
    std::cout << "Hello world" << std::endl;
    return 0;
}

