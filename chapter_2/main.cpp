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

int climits_test(void);
int cPlusPlus_init(void);
int flaotnum(void);
int cin_test(void);
int string_test();
int struct_test(void);
int enum_test(void);
int array_vector_test(void);
int for_test(void);
int switch_test(void);
int file_test(void);

int pointer_test(void);
int two_dimensional_arrays_test(void);
int function_pointer_test(int n);


int main()
{

	//cout.setf(ios_base::fixed, ios_base::floatfield);
    //cin_test();
	//flaotnum();	
	//climits_test();
	//cPlusPlus_init();
	//string_test();
    //struct_test();
	//enum_test();
	//array_vector_test();
	//for_test();
	//switch_test();
	//file_test();
	//pointer_test();
	//two_dimensional_arrays_test();

	function_pointer_test(1);

	cin.get();
	cin.get();
	return 0;
}

int function_pointer_test(int n)
{
	int (*ft)(int) = function_pointer_test;
	int (*ft1[3])(int) = {function_pointer_test,function_pointer_test, 
						  function_pointer_test};
	auto ft2 = ft1;

	if (n > 0) {
		n--;
		(*ft)(n);
		ft(n);
		(*ft1[0])(n);
		ft1[0](n);
		ft2[1](n);
	}
	cout << "function_pointer_test\n";
	return 0;
}

static int array_in(int arr[][3], int (*arr1)[3])
{
	cout << "int arr\n";
	cout << arr[1][1] << endl;
	cout << *(*(arr+1) + 1) << endl;

	cout << "\nint arr1\n";
	cout << arr1[1][1] << endl;
	cout << *(*(arr1+1) + 1) << endl;	

	return 0;
}

int  two_dimensional_arrays_test(void)
{
	int a[2][3] = {{1,2,3},{1,2,3}};
	array_in(a,a);

	return 0;
}

int pointer_test(void)
{
	int a = 3;
	int c = 1;
	const int b = 2;

	const int * p1 = &a;
	p1 = &b;
	// *p1 = 5; //指针指向的值不可修改

	int * const p2 = &a;
	// p2 = &c; //指针不可修改
	*p2 = 4;
	cout << "a: " << a << endl;

	const int * const p3 = &c; //指针和指针指向的值都不可修改
	// p3 = &a;
	// *p3 = 6;

	return 0;
}

int file_test(void)
{
	char filename[20] = "carinfo.txt";
	char filecount[20] = {};
	ofstream outFile;
	outFile.open(filename);
	outFile << "Make and model!" << endl;
	outFile.close();

	ifstream inFile;
	inFile.open(filename);

	while (inFile.good()) {
		inFile >> filecount + strlen(filecount);		
	}
	if (inFile.eof()) {
		inFile.close();
	}
	cout << filecount << endl; //空格不见了

	return 0;
}

int switch_test(void)
{
	switch(4) {
		case 1: cout << 1 << endl;
				break;
		case 2: cout << 2 << endl;
				break;
		case 3: cout << 3 << endl;
				break;
		case 4: cout << 4 << endl;
				break;
		default: cout << "default" << endl;
	}
}

int for_test(void)
{
	double prices[3] = {1,2,3};

	for (double &x : prices) {
		x += 1;
	}
	cout << endl;

	for (double x : prices) {
		cout << x << ", ";
	}

	cout << endl;
	for (double x : {4, 5, 6}) {
		cout << x << ", ";
	}

	return 0;
}

int array_vector_test(void)
{
	vector<int> ve(4); //can not = {1,2,3,4};
	array<int, 3> arr = {1, 2, 3};
	cout << arr.at(2) << endl;

	cout.setf(ios_base::boolalpha); //设置成输出bool值
	cout << (1 > 0) << endl;

	for (;1;) {}; //等价于for (;;;) {}
	return 0;
}

int enum_test(void)
{
	enum spectrum {
		red,
		blue = 3,
		yellow
	};

	spectrum band = blue;
	cout << band << endl;
	band = spectrum (2);
	cout << band << endl;

	return 0;
}

int struct_test(void)
{
	struct inlatable {
		int a;
		union id {
			int b;
			char c[20];
		} id_val;
		union {
			int b;
			int c;
		};
	};

	inlatable l {};

	l.a = 1;
	l.id_val.b = 2;
	l.id_val.c[0] = 3;
	l.b = 4;

	cout << l.a << endl;
	cout << l.id_val.b << endl;
	cout << (int) l.id_val.c[0] << endl;
	cout << l.b << endl;
	cout << l.c << endl;

	return 0;
}

int string_test()
{
	cout << R"+*(jim "is" who is '\n')")+*" << endl; //raw string

	char f1[20];
	string f2;
	cin.getline(f1, 20);
	cout << f1 << endl;

	getline(cin, f2);
	cout << f2 << endl;

	string c = "c";
	string d = c;

	d += "ff";

	d = "d";

	cout << c << endl;
	cout << d << endl;

	char charr1[20];
	string str1;

	cin >> charr1;
	cin >> str1;

	cout << charr1 << endl;
	cout << str1 << endl;

	char a[] {"Le Chapon"};
	string b {"Be chapon"};

	cout << a << endl;
	cout << b << endl;

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

int cin_test(void)
{
	const int arrsize = 20;
	char a[arrsize];
	char b[arrsize];

	cin.getline(a, arrsize); //	getline() automatically remove '\n'
	cin.getline(b, arrsize);
	cout << "cin.getline\n";
	cout << "a = " << a << endl;
	cout << "b = " << b << endl << endl;

	char c[arrsize];
	char d[arrsize];

	cin.get(c, arrsize).get(); // get() will get next char '\n'
	cin.get(d, arrsize).get();
	cout << "cin.get\n";
	return 0;
}

