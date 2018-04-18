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

template <typename T>
static void show(T & a);

template <typename T>
static void show2(T & a, T & b);

inline int inline_test(); 
int cite_test(void); 
int default_parameters_test(int a, int b, int c = 3, int d = 4); 
void overload_test_1(void);
void template_test(void);
int decltype_test(void);
int unknown_return_type(void);


int main(int agrs, char *argv[])
{
	//inline_test();
	//default_parameters_test(1, 2);
	//overload_test_1();
	//template_test();	
	//decltype_test();
	unknown_return_type();

	cin.get();
	cin.get();
	return 0;
}

static int & cite_test_init(int & n, int & m, const int & z)
{
	n = n + 1; 
	return m;
}

//引用测试
int cite_test(void)
{
	int a = 0, b = 0;

	//返回左值引用可以被赋值，const声明的引用参数可以传入值，函数将自动创建引用变量
	cite_test_init(a, b, 1) = 2; 
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;	

	return 0;
}

//內联函数可以用在递归
inline int inline_test()
{
	cout << "o\n";
	inline_test();
	return 0;
}

//给函数设置默认参数，默认参数只能从右到左设置，声明时设置
int default_parameters_test(int a, int b, int c, int d)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	return 0;
}

//函数重载测试1
static void stove(int & r)
{
	cout << "stove(int & r)\n";
}

static void stove(const int & r)
{
	cout << "stove(const int & r)\n";
}

static void stove(int && r)
{
	cout << "stove(int && r)\n";
}

void overload_test_1(void)
{
	int a = 1;
	const int b = 2;

	stove(a);
	stove(b);
	stove(a+b);
}

template <typename T>
static void show(T & a)
{
	cout << a << endl << endl;
}

template <typename T>
static void show2(T & a, T & b)
{
	cout << a << ", " << b << endl << endl;
}

template <typename T>
static void Swap(T & a, T & b)
{
	cout << "Swap(T & a, T & b)\n";
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
static void Swap(T & a, T & b, int n)
{
	cout << "Swap(T & a, T & b, int n)\n";
	T temp = a;
	a = b;
	b = temp;
}

//显示具体化，将实现与原模板不同的函数
template <> 
void Swap(float & a, float & b)
// void Swap<float>(float & a, float & b)
{
	cout << "template <> Swap<float>(float & a, float & b)\n";	
	float temp = a;
	a = b;
	b = temp;
}

static void Swap(float & a, float & b)
{
	cout << "void Swap(float & a, float & b)\n";	
	float temp = a;
	a = b;
	b = temp;
}

//函数模板测试
void template_test(void)
{
	// template void Swap<char>(char & a, char & b); //显示实力化

	int a = 1, b = 2;
	double c = 3, d = 4;
	float e = 5, f = 6;
	char g = 'g', h = 'h';

	Swap(a, b); //隐式实例化
	show2(a, b);

	Swap(c, d, 1);
	show2(c, d);

	Swap(e, f); //显示具体化
	show2(e, f);

	Swap<>(e, f); //强制使用模板匹配
	show2(e, f);

	Swap<char>(g, h);
	show2(g, h);
}

//decltype 提取类型
int decltype_test(void)
{
	int x = 1;

	decltype(x) y = 2;
	decltype((x)) z = x; //得到x的引用

	z = 3;
	show(x);

	return 0;
}

//后置返回类型，对未知类型进行返回，用到了类型截取decltype
template <typename T1, typename T2>
auto gt(T1 x, T2 y) -> decltype(x + y)
{
	return x + y;
}

int unknown_return_type(void)
{
	int a = 2, b = 2;
	cout << gt(a, b) << endl;
}
