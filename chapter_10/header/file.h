#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <string>

template <typename T>
void show(T x);

class Stock 
{
private:
    std::string _company;
    long _a;
    double _b;

public:
    Stock();
    Stock(const std::string & co, long a1 = 1, double b1 = 0);
    ~Stock();
    void show(void) const; //当定义常量的类时，可以调用该方法
    const Stock & topval(const Stock & s) const;
    Stock operator+(const Stock & s) const; //重载加法
};

#endif