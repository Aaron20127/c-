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

using namespace std;

inline int inline_test(); //內联函数可以用在递归
int cite_test(int & n); //修改了n值会修改传入n的变量的值

int main(int agrs, char *argv[])
{
	//inline_test();

	int a = 4;
	cite_test(a);
	cout << a << endl;

	cin.get();
	cin.get();
	return 0;
}

int cite_test(int & n)
{
	n = n + 1; 
	return 0;
}

inline int inline_test()
{
	cout << "o\n";
	inline_test();
	return 0;
}