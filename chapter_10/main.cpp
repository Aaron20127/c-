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
void class_this_test(void);
void class_operator_test(void);
void friend_test(void);
void convert_function_test(void);


int main(int agrs, char *argv[])
{
	// class_test();
	// class_this_test();
 	//class_operator_test();
	//friend_test();
	convert_function_test();
	

	cin.get();
	cin.get();
	return 0;
}

void mycout(void)
{
	show("\n------------------------------------------------------\n");
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

	mycout();
	{
		Stock stock{"lee", 1, 2};
		stock.show();
		cout << endl;
	}

	mycout();
	{
		Stock stock1 = {"Bluce", 3, 4};
		stock1.show();
		cout << endl;
	}

	//可以隐式转换
	mycout();
	{
		Stock mycat;
		mycat = 1.0; //只有接受一个变量的构造函数才能这样使用，隐式转换
	}

	//只能显示转换
	mycout();
	{
		Stock p1(5); //显示初始化

		Stock p2; 
		p2 = 10; //这里调用的是 Stock(double n); 而不是Stock(int n)；原因是Stock(int n)被声明成显示初始化，
				 //这里使用隐式转换，所以调用了Stock(double n)来代替
		p2 = (int)10; //4.8版本这里仍使用Stock(double n)
	}	
}

//this指针指向调用类自身的地址
void class_this_test(void)
{
	Stock stock1("B1", 2,1);
	Stock stock2("B2", 1,2);
	stock1.topval(stock2).show();
}

//重载运算符测试
void class_operator_test(void)
{
	{
		Stock stock1("Lee",1,1);
		Stock stock2("hh", 2, 2); 
		stock1 = stock1 + stock2;
		stock1.show();
	}

	mycout();
	{
		Stock stock1("Lee",1,1);
		cout << "stock1:\n" << stock1;
	}
}

//friend友元函数测试，重载超过一个参数必须写成友元函数，而非成员函数
void friend_test(void)
{
	{
		Stock stock1("Lee", 1, 1);
		stock1 = stock1 * 0.2;
		stock1.show();	
	}

	mycout();
	{
		Stock stock1("Lee", 1, 1);
		stock1 = 0.3 * stock1;
		stock1.show();
	}
}

//转换函数，将类对象赋值给其他类型
void convert_function_test(void)
{
	Stock stock1("Lee", 1, 1);
	int a = stock1;
	double b = stock1;

	// long c = stock1; //有二意性，编译报错
	long d = (int) stock1; //指定转换函数

	// char e = stock1; //explicit声明，必须加显示使用显示转换
	char e = (char)stock1;
}