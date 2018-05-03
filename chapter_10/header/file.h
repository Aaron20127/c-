#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <string>

template <typename T>
void show(T x)
{
	std::cout << x;
}

class Stock 
{
private:
    std::string _company;
    double _a;
    double _b;

public:
    Stock();
    Stock(double n);
    explicit Stock(int n); //显示初始化
    
    Stock(const std::string & co, double a1 = 1, double b1 = 0);
    ~Stock();

    void show(void) const; //当定义常量的类时，可以调用该方法
    const Stock & topval(const Stock & s) const;

    Stock operator+(const Stock & s) const; //重载加法
    Stock operator*(double m) const; //重载乘法

    friend Stock operator*(double m,  const Stock & n); //重载超过一个参数，则只能写成友元函数
    friend std::ostream & operator<<(std::ostream & os, const Stock & s); 
 
    operator int () const; //转换函数
    operator double () const;
    explicit operator char () const;
};

#endif