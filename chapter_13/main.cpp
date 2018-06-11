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

void derived_classe_test(void);

int main(int agrs, char *argv[])
{
	derived_classe_test();

	cin.get();
	cin.get();
	return 0;
}

void mycout(void)
{
	show("\n------------------------------------------------------\n");
}

void derived_classe_test(void)
{
	{
		StringMe p1("p1");
		reStringMe p2("p2"); //初始化并不一定使用赋值运算符

		StringMe * p3 = &p2; //基类指向派生类
		StringMe & p4 = p2; //基类引用派生类	
	}

	{
		mycout();
		reStringMe r1("p1");
		StringMe s1(r1); //复制构造函数，派生类可以作为基类参数

		s1 = r1; //调用赋值重载函数，将继承类赋值给基类
	}
}
