#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

#include "config.h"

//configeration file path
const char* path = "klog.conf";

map<string,string> g_mapCfgInfo;

void ReadConfigFile(void)
{
    fstream CfgFile;
    string strLine;

    CfgFile.open(path,ios::out|ios::app);

    if(CfgFile.is_open())
    {
        while(!CfgFile.eof())
        {
            getline(CfgFile,strLine);
            if(strLine.compare(0,1,"#") == 0)
                continue;
            size_t pos = strLine.find('=');
            string strKey = strLine.substr(0,pos);
            string strValue = strLine.substr(pos + 1);
            g_mapCfgInfo.insert(pair<string,string>(strKey,strValue));
        }
    }
    else
    {
        cout <<"Can not open config file.\n";
    }
}
string GetConfig(string key)
{
    map<string,string>::iterator iter_cfgMap;
    iter_cfgMap = g_mapCfgInfo.find(key.c_str());
    if(iter_cfgMap != g_mapCfgInfo.end() )
    {
        return iter_cfgMap->second;
    }
    else
    {
        return "";
    }
}

