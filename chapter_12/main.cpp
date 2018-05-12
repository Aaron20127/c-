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

		{
			mycout();
			const StringMe p("abcd");
			cout << p[1] << endl; //cout不能保证不改变数据，所以重载要声明const类型
		}

		{
			mycout();
			StringMe p("abcd");
			p[1] = 'f';
		}

		{
			mycout();
			StringMe p("abcd");
			cout << StringMe::HowManyString() << endl; //静态函数由解析运算符调用，静态函数只能使用静态成员
		}

		{
			mycout();
			StringMe p("abcd");
			p = "11111";	// 直接赋值字符串		
		}

		{
			mycout();
			StringMe * p = new StringMe("p__");
			cout << *p << endl;
			delete p; //new产生的变量delete时才调用析构函数
		}

		//定位new运算符
		{
			mycout();
			char * buffer = new char[100000];

			StringMe *p1 = new (buffer) StringMe;
			StringMe *p2 = new (buffer + sizeof(StringMe)) StringMe;

			p2->~StringMe(); //必须显示调用析构函数，按生成的顺序的反方向调用
			p1->~StringMe();
			delete buffer;
		}
	}
}
