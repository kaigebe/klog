#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

#include "config.h"

//configeration file path
const char* path = "klog.conf"

void ReadConfigFile(void)
{
    fstream CfgFile;

    CfgFile.open(path,ios::out|ios::app);


}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

