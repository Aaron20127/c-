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

void globle_test(void);

int main(int agrs, char *argv[])
{
	globle_test();

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