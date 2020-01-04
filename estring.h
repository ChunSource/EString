#ifndef ESTRING_H
#define ESTRING_H

#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;
class EString
{
    friend ostream&  operator<<(ostream& out ,EString& str)
    {
        cout<<str.mString;
        return out;
    }
    friend istream&  operator>>(istream& in  ,EString& str)
    {
        cin>>str.mString;
        return in;
    }
    friend bool      operator==(const EString& str1,const EString& str2)
    {
        if(str1.mString == str2.mString)
        {
            return true;
        }
        return false;
    }
public:
    //init function()
    EString();
    EString(EString const &estring);
    EString(string str);
    EString(const char* data);
    EString(const char* data, int dataSize);
    EString(int number,int radix = 10);

    //overload operator function:
    EString& operator+(const EString& str);
    EString& operator+(const string& str);
    EString& operator+(const int& number);
    EString& operator+(const char* str);
    EString& operator=(const string& str);
    EString& operator=(const char* str);
    EString& operator=(const EString& str);
    EString& operator+=(const EString& str);
    bool operator==(const EString& str);
    bool operator==(const string& str);
    bool operator!=(const string& str);


    //normal function:
    int             getLength();   //获取字符串长度
    string          toStdstring(); //转string对象
    int             toInt();
    const char*     toCharPoint();

    int             indexOf(const EString& str,int from = 0);
    EString         mid(int position,int n = -1);
    EString&        repelace(const EString& before,const EString& after);
    vector<EString>   split(const char* delim);
private:
    string mString;

    //private function:
    int  getIntWidth(int& number);
    bool cmpStr(const string& str1, const EString& str2);
};
#endif // ESTRING_H
