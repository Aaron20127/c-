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

using namespace std;

int globle = 1;
extern const int finger;

template <typename T>
void show(T x);

void globle_test(void);
void mutable_test(void);
void const_extern_test(void);
void namespace_test(void);
void debug_test(void);

int main(int agrs, char *argv[])
{
	//globle_test();
	//const_extern_test();
	//namespace_test();

	debug_test();
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

//new定义变量时，初始化的方法
void new_test(void)
{
	int * p1 = new int (3);
	int * p2 = new int [2] {1, 2};
}

namespace jill {
	int a = 1;
}

void namespace_test(void)
{
	using namespace jill;
	show(a);
	int a = 2;
	show(a);
	show(jill::a);
}

//打印测试
void debug_test(void)
{
	int i ;
    i = DEBUG("hahaha\n");
    printf("==> buf_len [%d]\n", i);
    INFO("hahaha\n");
    WARN("hahaha\n");
    ERROR("hahaha\n");
}