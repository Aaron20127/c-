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
#include "header/brass.h"
#include "header/common.h"

using namespace std;

void derived_classe_test(void);
void virtual_test(void); //虚函数测试


int main(int agrs, char *argv[])
{
	// derived_classe_test();
	virtual_test();

	cin.get();
	cin.get();
	return 0;
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

void virtual_test(void)
{
	{
	// 基类引用基类和派生类时，使用同名函数时将调用各自的函数，前提是基类中声明的同名函数为虚基类
		mycout();
		Brass p1("p1");
		BrassPlus p2("p2");

		Brass & p11 = p1;
		Brass & p22 = p2;

		p11.Viewacct(); 
		p22.Viewacct();
	}

	{
	// 派生类的方法中使用与基类重名的方法则使用作用域解析方法，Brass::Viewacct()
	// 如果不重名，则可以直接调用
		mycout();
		BrassPlus p2("p2");
		p2.Viewacct();
	}

	{
	//如果基类Brass的析构函数不是虚的，则释放时不会调用BrassPlus的析构函数
	//Brass的析构函数应使用 virtual ~Brass();
		mycout();
		Brass * p = new BrassPlus;
		delete p;
	}

	{
	// 参数不同的同函数将被派生类隐藏, 不管函数是不是虚的，
	// 派生类无法直接使用同名的函数，只有向上转换成基类引用时才可使用基类同名函数
		mycout();
		BrassPlus p("p");
		Brass & p1 = p;
		p.virtualSameNameHidden();
		// p.virtualSameNameHidden(1); //虚函数时，使用基类的同名函数时，派生类将报错
		p1.virtualSameNameHidden(1);

		p.sameNameHidden();
		// p.sameNameHidden(1); //使用基类的同名函数时，派生类将报错
		p1.sameNameHidden(1);	
	}
}


