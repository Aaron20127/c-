#include <iostream>
#include "header/file.h"

using namespace std;



Stock::Stock()
{
    cout << "Stock::Stock()\n";
    _company = "no name";
    _a = 0;
    _b = 0;
}

Stock::Stock(double n)
{
    cout << "Stock::Stock(double n)\n";
    _company = "no name";
    _a = 0;
    _b = 0;
}

//只能显示转换
Stock::Stock(int n)
{
    cout << "Stock::Stock(int n)\n";
    _company = "no name";
    _a = 0;
    _b = 0;
}

Stock::Stock(const string & co, double a1, double b1)
{
    cout << "Stock::Stock(const string & co, double a1, double b1)\n";
    _company = co;
    _a = a1;
    _b = b1;
}

Stock::~Stock()
{
    cout << "~Stock(), " << _company << endl;
}

void Stock::show(void) const
{
    cout << "void Stock::Tshow(void)\n";
    cout << "_company: " << _company << '\n'
         << "_a: " << _a << endl
         << "_b: " << _b << endl << endl;
   
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s._a > _a)
        return s;
    else 
        return *this;
}

Stock Stock::operator+(const Stock & s) const
{
    Stock stock(_company,0,0);
    stock._a += s._a;
    stock._b += s._b;
    return stock;
}

Stock Stock::operator*(double m) const
{
    cout << "Stock::operator*(double m) const\n";
    return Stock(_company, this->_a * m, this->_b * m);
}

Stock operator*(double m, const Stock & n)
{
    cout << "operator*(double m, const Stock & n)\n";
    return n*m;
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
    cout << "Stock & operator<<(std::ostream & os, const Stock & s)\n";
    cout << "_company: " << s._company << '\n'
         << "_a: " << s._a << endl
         << "_b: " << s._b << endl << endl;
    return os;
}
