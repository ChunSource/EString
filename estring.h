#ifndef ESTRING_H
#define ESTRING_H

#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
class EString
{
public:
    //init function()
    EString();
    EString(EString const &estring);
    EString(string str);
    EString(char* data);
    EString(char* data, int dataSize);
    EString(int number,int radix = 10);

    //overload operator function:
    EString operator+(const EString& str);
    EString operator+(const string& str);
    EString operator+(const char* str);
    EString operator+(const int& number);

    EString operator=(const char* str);
    EString operator=(const string& str);

    bool operator==(const EString& str);
    bool operator==(const char* str);
    bool operator==(const string& str);

    bool operator!=(const EString& str);
    bool operator!=(const char* str);
    //normal function:
    int    getLength();   //获取字符串长度
    string toStdstring(); //转string对象
    int    toInt();
    const char* toCharPoint();
private:
    string mString;

    //private function:
    int getIntWidth(int& number);
    bool cmpStr(const string& str1,const char* str2);
};
#endif // ESTRING_H
