#include "basicclasses.h"


FirstOne::FirstOne() 
{
	cout << "FirstOne Default Constructor" << endl;
}

FirstOne::FirstOne(int, int) 
{
	cout << "FirstOne Default Constructor with two arguments" << endl;
}


void test_FirstOneClass()
{
	
	FirstOne a;   // ok, default constructor called
	FirstOne b(); // oops, default constructor NOT called
	cout << R"(
		FirstOne a;   // ok, default constructor called
		FirstOne b(); // oops, default constructor NOT called)" << endl;

	//This is because the empty set of parentheses would make of rectc a function declaration instead 
	//of an object declaration : It would be a function that takes no argumentsand returns a value 
	//of type Rectangle.
}


Val::Val() :val(0)
{
	cout << "default constructor" << endl;
}

Val::Val(int i)
{
	cout << "one arg constructor: i = " << i << endl;
	val = i;
}

Val::Val(int i, int j)
{
	cout << "two args constructor: i = " << i <<" , j= "<< j << endl;
	val = i * j;
}
int Val::Get()
{
	return val;
}

void initializer_list_test()
{
	//An advantage of uniform initialization over functional form is that, 
	//unlike parentheses, braces cannot be confused with function declarations, 
	//and thus can be used to explicitly call default constructors:


	cout << "intializer list" << endl;
	cout << R"(Val a, b(1), c{ 2, 3 }, d = { 4, 5 }, e = 6, f = {7}, g{};)" << endl;
	Val a, b(1), c{ 2, 3 }, d = { 4, 5 }, e = 6, f = { 7 }, g{};
}








OperatorOverload::OperatorOverload(int a) :val(a) {}
OperatorOverload OperatorOverload::operator+(const OperatorOverload& a) const 
{ 
	return OperatorOverload{ val + a.val }; 
}

OperatorOverload OperatorOverload::operator+(const int a) const 
{ 
	return OperatorOverload{ val + a }; 
}
OperatorOverload operator+(const int a, const OperatorOverload& b) 
{ 
	return OperatorOverload{ b.val + a }; 
}

OperatorOverload OperatorOverload::operator-() 
{ 
	return OperatorOverload{ -val }; 
}

OperatorOverload OperatorOverload::operator+() 
{ 
	return OperatorOverload{ +val }; 
}

OperatorOverload OperatorOverload::operator++()
{
	++val;
	return *this;
}

OperatorOverload OperatorOverload::operator--()
{
	--val;
	return *this;
}

OperatorOverload OperatorOverload::operator++(int)
{
	val++;
	return *this;
}

OperatorOverload OperatorOverload::operator--(int)
{
	val--;
	return *this;
}

ostream& operator<< (ostream& out, const OperatorOverload& a)
{
	out << a.val;
	return out;
}


void overloaded_operators()
{
	cout << R"(	   
    OperatorOverload a{ 1 }, b{ 2 };
	a + b;
	a + 1;
	1 + a;
	a + a + a + a + b + b;
	auto c = a.operator+(b);
	-a;
	+a;
	++a;
	a++;
	a--;)" << endl;


	OperatorOverload a{ 1 }, b{ 2 };
	cout << "a + b = " << a + b << endl;

	cout << "a + 1 = " << a + 1 << endl;
	cout << "1 + a = " << 1 + a << endl;
	cout << "a + a ... +b = " << a + a + a + a + b + b << endl;
	auto c = a.operator+(b);
	cout << "-a = " << -a << endl;
	cout << "+a = " << +a << endl;
	cout << "++a = " << ++a << endl;
	cout << "a++ = " << a++ << endl;
	cout << "a-- = " << a-- << endl;
	cout << "--a = " << --a << endl;
}





int Static::n = 0;

Static::Static() { ++n; cout << n << endl; }


void class_static_members()
{ 
	cout << "Static a[6];" << endl;
	Static a[6];
}