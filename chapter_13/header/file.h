#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <string>

class StringMe 
{
private:
    char * str;
    int len;
    static int num_strings;

    int myyear = 0; //c++11允许类内初始化
    const int values;

public:
    StringMe(const char *s);
    StringMe(const StringMe & st);
    StringMe();
    ~StringMe();

    char & operator[](int i);
    const char & operator[](int i) const;    

    friend std::ostream & operator<<(std::ostream & os, const
                                     StringMe & st);

    StringMe & operator=(const StringMe & st);
    StringMe & operator=(const char * s);

    void print(void);

    static int HowManyString() { return num_strings; }                             
};

// 
class reStringMe : public StringMe 
{
private:
    int rating;

public:
    reStringMe (const char * str, int r = 0);
    reStringMe (int r, const StringMe & s);
    ~reStringMe();
};

#endif
