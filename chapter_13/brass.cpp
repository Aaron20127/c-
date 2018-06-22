
#include <iostream>
#include <cstring>
#include "header/brass.h"
#include "header/common.h"


Brass::Brass(const std::string & s, long an, double bal) 
{
    show("Brass::Brass(const std::string & s, long an, double bal) \n");
}

void Brass::Deposit(double amt) 
{
    show("Brass::Deposit(double amt) \n");
}

void Brass::Withdraw(double amt) // 虚函数，使派生类和基类能使用同名函数，具有各自的方法
{
    show("Brass::Withdraw(double amt)\n");
}

double Brass::Balance() const
{
    show("Brass::Balance() const\n");
    return 0.0;
}

void Brass::Viewacct() const
{
    show("Brass::Viewacct() const\n");
}

Brass::~Brass()
{
    show("void Brass::~Brass()\n");
}

void Brass::virtualSameNameHidden(int n)
{
    show("void Brass::virtualSameNameHidden(int n)\n");
}

void Brass::sameNameHidden(int n)
{
    show("void Brass::sameNameHidden(int n)\n");
}


// BrassPlus-----------------------------------

BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double a)
{
    show("BrassPluss::BrassPlus(const std::string & s, long an, double bal, double ml, double a)\n");
}

BrassPlus::BrassPlus(const Brass & ba,double ml, double r)
{
    show("BrassPlus::BrassPlus(const Brass & ba,double ml, double r)\n");
}

void BrassPlus::Viewacct() const
{
    Balance(); //非重重名函数直接调用
    Brass::Viewacct(); //同名函数使用作用域解析符
    // Viewacct(); //递归调用自己，将出现段错误
    show("BrassPlus::Viewacct() const\n");
}

void BrassPlus::Withdraw(double amt)
{
    show("BrassPluss::Withdraw(double amt)\n");
}

BrassPlus::~BrassPlus()
{
    show("void BrassPlus::~BrassPlus()\n");
}

void BrassPlus::virtualSameNameHidden()
{
    show("void BrassPlus::virtualSameNameHidden()\n");
}

void BrassPlus::sameNameHidden()
{
    show("void BrassPlus::sameNameHidden()\n");
}
