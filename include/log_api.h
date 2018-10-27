#pragma once
#ifndef LOG_API_H
#define LOG_API_H

void (*Log)(string tag,string msg);
void LOG(string tag,string msg);
void LogD(string tag,string msg);
void LogE(string tag,string msg);
void LogI(string tag,string msg);
void LogW(string tag,string msg);

#endif //LOG_API_H

