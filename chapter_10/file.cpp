#include <iostream>
#include "header/file.h"

using namespace std;

template <typename T>
void show(T x)
{
	cout << x;
}

Stock::Stock()
{
    cout << "Stock::Stock()\n";
    _company = "no name";
    _a = 0;
    _b = 0;
}

Stock::Stock(const string & co, long a1, double b1)
{
    cout << "Stock::Stock(const string & co, long a1, double b1)\n";
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
         << "_a: " << _a << '\n'
         << "_b: " << _b << endl;
}