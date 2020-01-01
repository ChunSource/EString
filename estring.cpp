#include "estring.h"

EString::EString()
{

}

EString::EString(EString const &estring)
{
    this->mString = estring.mString;
}

EString::EString(string str)
{
    this->mString = str;
}

EString::EString(char *data)
{
    this->mString = data;
}

EString::EString(char *data, int dataSize)
{
    this->mString = string(data,dataSize);
}

EString::EString(int number, int radix)
{
    if(radix == 10)
    {
        this->mString = to_string(number);
        return;
    }
    int width = getIntWidth(number);  //根据数字的位数自动设置
    char *tmp = new char[width];
    this->mString = itoa(number,tmp,radix);
    delete[] tmp;
    tmp = nullptr;
}

EString EString::operator+(const EString &str)
{
    EString newString(this->mString + str.mString);
    return newString;
}

EString EString::operator+(const string &str)
{
    EString newString(this->mString + str);
    return newString;
}

EString EString::operator+(const char *str)
{
    string tmpSrMemory = str;
    EString newString(this->mString + tmpSrMemory);
    return newString;
}

EString EString::operator+(const int &number)
{
    EString newString(this->mString + to_string(number));
    return newString;
}

EString EString::operator=(const char *str)
{
    EString a(str);
    this->mString = str;
    return a;
}

EString EString::operator=(const string &str)
{
    this->mString = str;
    EString newString(str);
    return newString;
}

bool EString::operator==(const EString &str)
{
    if(str.mString == this->mString)
    {
        return true;
    }
    return false;
}

bool EString::operator==(const char *str)
{
    if(cmpStr(this->mString,str))
    {
        return true;
    }
    return false;
}

bool EString::operator==(const string &str)
{
    if(this->mString == str)
    {
        return true;
    }
    return false;
}

bool EString::operator!=(const EString &str)
{
    if(this->mString == str.mString)
    {
        return false;
    }
    return true;
}

bool EString::operator!=(const char *str)
{
    if(cmpStr(this->mString,str))
    {
        return false;
    }
    return true;
}

int EString::getLength()
{
    return this->mString.length();
}

string EString::toStdstring()
{
    return this->mString;
}

int EString::toInt()
{
    return atoi(this->mString.data());
}

const char *EString::toCharPoint()
{
    return this->mString.data();
}

int EString::getIntWidth(int &number)
{

    return 1+log10(number);
}

bool EString::cmpStr(const string &str1, const char *str2)
{
    int size = sizeof (str2);
    if(memcmp(&str1,str2,size) == 0)
    {
        return true;
    }
    return false;
}
