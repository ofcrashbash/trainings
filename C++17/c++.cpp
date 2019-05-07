#include "c++.h"
#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

int basic_types()
{
	cout << "Basic Types size" << endl;
	cout << "\tCharakter types:" << endl;
	cout << "\t\tchar: " << sizeof(char) << endl;
	cout << "\t\tchar16_t: " << sizeof(char16_t) << endl;
	cout << "\t\tchar32_t: " << sizeof(char32_t) << endl;
	cout << "\t\twchar_t: " << sizeof(wchar_t) << endl;

	cout << "\tInteger types:" << endl;
	cout << "\t\tsigned char: " << sizeof(signed char) << endl;
	cout << "\t\t\tmin value: " << SCHAR_MIN << ", max value: " << SCHAR_MAX << endl;
	cout << "\t\tshort int: " << sizeof(short int) << endl;
	cout << "\t\t\tmin value: " << SHRT_MIN << ", max value: " << SHRT_MAX << endl;
	cout << "\t\tint: " << sizeof(int) << endl;
	cout << "\t\t\tmin value: " << INT_MIN << ", max value: " << INT_MAX << endl;
	cout << "\t\tlong int: " << sizeof(long int) << endl;
	cout << "\t\t\tmin value: " << LONG_MIN << ", max value: " << LONG_MAX << endl;
	cout << "\t\tlong long int: " << sizeof(long long int) << endl;
	cout << "\t\t\tmin value: " << LLONG_MIN << ", max value: " << LLONG_MAX << endl;
	
	cout << "\tUnsigned integer types:" << endl;
	cout << "\t\tThey are similar to signed." << endl;

	cout << "\tFloating point types:" << endl;
	cout << "\t\tfloat: " << sizeof(float) << endl;
	cout << "\t\t\tsmallest such that 1.0+FLT_EPSILON != 1.0: " << FLT_EPSILON << endl;
	cout << "\t\t\tmin value: " << FLT_MIN << ", max value: " << FLT_MAX << endl;
	cout << "\t\t\tmin exp: " << FLT_MIN_10_EXP << ", max exp: " << FLT_MAX_10_EXP << endl;
	cout << "\t\tdouble: " << sizeof(double) << endl;
	cout << "\t\t\tsmallest such that 1.0+DBL_EPSILON != 1.0: " << DBL_EPSILON << endl;
	cout << "\t\t\tmin value: " << DBL_MIN << ", max value: " << DBL_MAX << endl;
	cout << "\t\t\tmin exp: " << DBL_MIN_10_EXP << ", max exp: " << DBL_MAX_10_EXP << endl;
	cout << "\t\tlong double: " << sizeof(long double) << endl;
	cout << "\t\t\tsame as double.." << endl;

	cout << "\tOther: " << endl;
	cout << "\t\tbool: " << sizeof(bool) << endl;
	cout << "\t\tvoid: no storage" << endl;
	cout << "\t\tnull pointer: " << sizeof(decltype(nullptr)) << endl;

	return 0;
}


void constants()
{
	75;         // decimal
	0113;       // octal
	0x4b;       // hexadecimal 
	
	75;         // int
	75u;        // unsigned int
	75l;        // long
	75ul;       // unsigned long 
	75lu;       // unsigned long

	3.14159L;   // long double
	6.02e23f;   // float
	6.1e10;     // double

	"lalalala"; //char
	u"lalalla"; //char16_t
	L"lalalla"; //wchar_t

	auto rawc = R"(la\\t\bdfbd\fsrd\gd\bxn\t""""'''' \l\""ala)"; //raw string
	
																 //For supporting of unicode probably compiler should be reconfigured
	auto u8c = u8"Як умру то поховайте"; //unicode string 
	cout << "raw string :" << rawc << endl
		<< "u8 string: " << u8c << endl;
}


void some_operators()
{	
	cout << "comma operator." << endl;
	auto b = 1;
	auto a = (++b, ++b, ++b, b);
	cout << R"(
	auto b = 1;
	auto a = (b++, b++, b++, 1);
	a = )" << a << endl;
	
	cout << "conditional ternary operator." << endl;
	auto c = true ? 3 : 1;
	auto d = false ? 3 : 1;
	cout << "true ? 3 : 1 = " << c << endl;
	cout << "false ? 3 : 1 = " << d << endl;

	cout << "Bitwise operators: &, |, ^, ~, <<, >> " << endl;
	unsigned char i = 5, j = 9;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "i&j = " << (i&j) << endl;
	cout << "i|j = " << (i|j) << endl;
	cout << "i^j = " << (i^j) << endl;
	cout << "i<<1 = " << (i<<1) << endl;
	cout << "i>>1 = " << (i>>1) << endl;
	cout << "~j = " << (~j) << endl;

}


template<typename T>
T sum(T a, T b)
{
	return a + b;
}

//Non-type template arguments
template<typename T, int N = 1>
T gain(T a)
{
	return a * N;
}

void template_usage()
{
	auto a = sum(1, 2);
	auto b = sum(1., 2.);
	auto c = sum(1., (double)2);
	auto d = sum<double>(1, 2);

	a = gain(4);
	a = gain(4.);
	a = gain<int, 10>(4.);
	a = gain(4.);
}


//local vs global storage
int global_val;
void foo()
{
	int local_val = 0;//can't be used withou initialziation.
	cout << "global: " << global_val << endl;
	cout << "local: " << local_val;
}


//function pointers
typedef int (*fptr)(int, int);
using fptr2 = int (*)(int, int);

int faa(int i, int j)
{
	return i * j;
}


fptr pointer_to_faa()
{
	return faa;
}

fptr2 pointer_to_faa_2()
{
	return faa;
}

void func_pointer_test()
{
	cout << "typedef func pointer: fptr()(2, 3) = " << pointer_to_faa()(2, 3) << endl;
	cout << "using func pointer: fptr2()(2, 3) = " << pointer_to_faa_2()(2, 3) << endl;
}

//Memory allocation
void memory_allocation()
{
	auto a = new int;
	*a = 1;
	delete a;

	//But if there will be not enough of memory it will throw excpetion
	auto b = new int[10];
	*b = 1;
	delete[] b;

	//
	auto c = new (nothrow) int[LONG_MAX];
	delete[] c;

	auto d = new int[LONG_MAX];
	delete[] d;

}


//More rare data types
void anonimous_union_and_structure()
{
	struct book1_t {
		char title[50];
		char author[50];
		union {
			float dollars;
			int yen;
		} price;
	} book1;

	book1.price.dollars;

	struct book2_t {
		char title[50];
		char author[50];
		union {
			float dollars;
			int yen;
		};
	} book2;

	book2.yen;

	//enumerated types
	enum months_t {
		january = 1, february, march, april,
		may, june, july, august,
		september, october, november, december
	};

	months_t::april;
	months_t::december;


	//class enumerated
	enum class Colors { black, blue, green, cyan, red, purple, yellow, white };
	Colors::black;
}
