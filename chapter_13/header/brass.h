
#ifndef BRASS_H_
#define BRASS_H_

#include <string>
#include "common.h"

class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;

public:
    Brass(const std::string & s = "NullBody", long an = -1,double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt); 
    double Balance() const;
    virtual void Viewacct() const; // 虚函数，使派生类和基类能使用同名函数，具有各自的方法
    // void Viewacct() const;
    virtual ~Brass() {}; // 虚析构函数，保护派生类释放时，基类正常释放
};

class BrassPlus : public Brass {
private:
    double maxloan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string & = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500, double a = 0.11125);
    BrassPlus(const Brass & ba,
              double ml = 500, double r = 0.11125);
    virtual void Viewacct() const; // 虚函数，使派生类和基类能使用同名函数，具有各自的方法
    // void Viewacct() const;
    virtual void Withdraw(double amt); 
    void ResetMax(double m) { maxloan = m; };
    void ResetRate(double r) { rate = r; };
    void ReseOwes() { owesBank = 0; }
};



#endif
