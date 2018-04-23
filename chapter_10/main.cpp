#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <climits>
#include <string>
#include <vector>
#include <array>
#include <typeinfo>
#include "header/debug.h"
#include "header/file.h"

using namespace std;

void class_test(void);

int main(int agrs, char *argv[])
{
	class_test();

	cin.get();
	cin.get();
	return 0;
}

//构造函数与析构函数，只要变量释放，就调用析构函数
void class_test(void)
{
	{
		const Stock stock("lee", 1, 2);
		stock.show();
		cout << endl;

		Stock stock1 = Stock("Bluce", 3, 4);
		stock1.show();
		cout << endl;

		stock1 = stock;
		stock1.show();
		cout << endl;

		Stock stock2;
		stock2.show();
		cout << endl;
	}

	{
		Stock stock{"lee", 1, 2};
		stock.show();
		cout << endl;
	}

	{
		Stock stock1 = {"Bluce", 3, 4};
		stock1.show();
		cout << endl;
	}

}

