#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <string>

template <typename T>
void show(T x)
{
	std::cout << x;
}

class StringMe 
{
private:
    char * str;
    int len;
    static int num_strings;

public:
    StringMe(const char *s);
    StringMe(const StringMe & st);
    StringMe();
    ~StringMe();

    friend std::ostream & operator<<(std::ostream & os, const
                                     StringMe & st);

    StringMe & operator=(const StringMe & st);
    
    void print(void);
                                        
};

#endif