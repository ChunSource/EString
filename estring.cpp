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

EString::EString(const char *data)
{
    this->mString = data;
}

EString::EString(const char *data, int dataSize)
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

EString& EString::operator+(const EString &str)
{
    this->mString = this->mString + str.mString;
    return *this;
}

EString& EString::operator+(const string &str)
{
    this->mString += str;
    return *this;
}

EString& EString::operator+(const int &number)
{
    this->mString = this->mString + to_string(number);
    return *this;
}

EString& EString::operator+(const char *str)
{
    this->mString += str;
    return *this;
}

EString& EString::operator=(const string &str)
{
    this->mString = str;
    return *this;
}

EString& EString::operator=(const char *str)
{
    this->mString = str;
    return *this;
}

EString& EString::operator=(const EString &str)
{
    this->mString = str.mString;
    return *this;
}

EString& EString::operator+=(const EString& str)
{
    *this = *this + str;
    return *this;
}

bool EString::operator==(const EString &str)
{
    if(cmpStr(this->mString,str))
    {
        return true;
    }
    return false;
}

bool EString::operator==(const string &str)
{
    if(cmpStr(this->mString,str))
    {
        return true;
    }
    return false;
}

bool EString::operator!=(const string &str)
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

int EString::indexOf(const EString &str, int from)
{
    return this->mString.find(str.mString.c_str(),from);
}

EString EString::mid(int position, int n)
{
    string tmpStr = this->mString.substr(position,n);
    EString newString(tmpStr);
    return tmpStr;
}

EString &EString::repelace(const EString &before,const  EString &after)
{
    const string& old_value = before.mString;
    const string& new_value = after.mString;
    string& str = this->mString;

    for(string::size_type   pos(0);   pos!=string::npos;   pos+=new_value.length())   {
                if(   (pos=str.find(old_value,pos))!=string::npos   )
                    str.replace(pos,old_value.length(),new_value);
                else   break;
            }
    return *this;
}

int EString::getIntWidth(int &number)
{

    return 1+log10(number);
}

bool EString::cmpStr(const string &str1, const EString &str2)
{
    if(str1 == str2.mString)
    {
        return true;
    }
    return false;
}

vector<EString> EString::split(const char* delim)
{
    const char* s = this->mString.data();
 //   const char* delim = sep.mString.data();

    vector<EString> list;
    if (s && strlen(s))
    {
        int len = strlen(s);
        char *src = new char[len + 1];
        strcpy(src, s);
        src[len] = '\0';
        char *tokenptr = strtok(src, delim);
        while (tokenptr != NULL)
        {
            std::string tk = tokenptr;
            list.emplace_back(tk);
            tokenptr = strtok(NULL, delim);
        }
        delete[] src;
    }

    return list;
    
}