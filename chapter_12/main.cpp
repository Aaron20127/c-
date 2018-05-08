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

void mycout(void)
{
	show("\n------------------------------------------------------\n");
}

void class_test(void)
{
	{
		{
		StringMe p1("p1");
		StringMe p2 = p1; //初始化并不一定使用赋值运算符
		}

		{
		mycout();
		StringMe p3("p3"), p4;
		p4 = p3;
		}
	}
}
