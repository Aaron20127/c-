#include <iostream>
#include <cmath>
#include <climits>
#include <cfloat>

using namespace std;

int climits_test(void);
int cPlusPlus_init(void);
int flaotnum(void);

//第五次修改

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);

    //long a = 11111111111111;
	const int b = 1;
	int a = 2000;
	char c = {a};
	cout << "a + b = " << c << endl;


	//flaotnum();	
	//climits_test();
	//cPlusPlus_init();

	cin.get();
	return 0;
}

int climits_test(void)
{
	char n_char = CHAR_BIT;
	int n_int_max = INT_MAX;
	int n_int_min = INT_MIN;

	cout << "sizeof (n_char): " << sizeof (n_char) << endl;
	cout << "CHAR_BIT: " << CHAR_BIT << endl;

	cout << "sizeof (short): " << sizeof (short) << endl;
	//cout << "SHORT_MAX: " << SHORT_MAX << endl;

	cout << "sizeof (n_int_max): " << sizeof n_int_max << endl;
	cout << "INT_MAX: " << INT_MAX << endl;

	cout << "sizeof (n_int_min): " << sizeof (n_int_min) << endl;
	cout << "INT_MIN: " << INT_MIN << endl;

	cout << "sizeof (long): " << sizeof (long) << endl;
	cout << "LONG_MAX: " << LONG_MAX << endl;

	return 0;
}

int cPlusPlus_init(void)
{
	int a = {};
	int b = {5};
	int c{};

	cout << "a: " << a << endl
		 << "b: " << b << endl
		 << "c: " << c << endl;
	return 0;
}

int flaotnum(void)
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;

	cout << "tub = " << tub;
	cout << ", amillion tub = " << million * tub;
	cout << ", \nand ten million tube = " << 10 * million * tub;
    cout << "\nmint = " << mint << " and a million minte = ";
	cout << million * mint << endl;
	return 0;

}