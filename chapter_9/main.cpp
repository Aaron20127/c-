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

using namespace std;

int globle = 1;
extern const int finger;

template <typename T>
void show(T x);

void globle_test(void);
void mutable_test(void);
void const_extern_test(void);


int main(int agrs, char *argv[])
{
	//globle_test();
	const_extern_test();

	cin.get();
	cin.get();
	return 0;
}

template <typename T>
void show(T x)
{
	cout << x << endl;
}

//使用::globle使用全局变量
void globle_test(void)
{
	int globle = 2;
	show(globle);
	show(::globle);
}

//mutable可以修改结构或类的某个成员
void mutable_test(void)
{
	struct go {
		int a;
		mutable int b;
	};

	const go g = {1, 1};
	// g.a = 1; //不允许
	g.b = 2; //允许改变
}

//调用const 生成的外部变量，必须在定义时添加extern
void const_extern_test(void)
{
	show(finger);
}