#pragma once
#ifndef CONFIG_H_
#define CONFIG_H_

void ReadConfigFile(void);
string GetConfig(string key);
void SetConfig(string key);
void GetCfgMap(map<string,string> &mapCfgInfo);

#endif
