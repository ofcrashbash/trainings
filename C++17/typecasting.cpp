#include "typecasting.h"
#include <iostream>
using namespace std;


/*
	different types of conversion for classes
*/

B::B(const A& a) 
{
	cout << "copy cosntructor" << endl;
};

B& B::operator =(const A& a)
{
	cout << "asignment constructor" << endl;
	return *this;
};

B::operator A() 
{
	cout << "type conversion" << endl;
	return A{}; 
}

void typecasting()
{
	cout << "type casting" << endl;
	A a;
	B b(a);
	b = a;
	b = A(b);
}


/*
	Keyword explicit
*/

/*
	Tupe conversion keywords
*/

void dynamic_cast_test() {
	//it performs conversion only between related classes
	//and best case is from derived to base class.
	//from base to derived it can cast only: 
	//if -and only if- the pointed object is a valid complete 
	//object of the target type
	try {
		Base* pba = new Derived;
		Base* pbb = new Base;
		Derived* pd;

		pd = dynamic_cast<Derived*>(pba);
		if (pd == 0) cout << "Null pointer on first type-cast.\n";

		pd = dynamic_cast<Derived*>(pbb);
		if (pd == 0) cout << "Null pointer on second type-cast.\n";
	}
	catch (exception & e) { cout << "Exception: " << e.what(); }
}


void static_cast_test()
{
	Base2* a = new Base2;
	Derived2* b = static_cast<Derived2*>(a);
}

//const cast
void print(char* str)
{
	cout << str << '\n';
}

void const_cast_test() {
	const char* c = "sample text";
	print(const_cast<char*> (c));
}

#include <typeinfo>
void typeid_test()
{
	if (typeid(Base) == typeid(Derived))
		cout << "base is equal to derived" << endl;
	else
		cout << "base isn't equal to deriverd" << endl;

	cout << typeid(Base).name() << endl;
	cout << typeid(Base).raw_name() << endl;
	try{
		Base* a = new Base;
		Base* b = new Derived;
		cout << "a is: " << typeid(a).name() << '\n';
		cout << "b is: " << typeid(b).name() << '\n';
		cout << "*a is: " << typeid(*a).name() << '\n';
		cout << "*b is: " << typeid(*b).name() << '\n';
	}
	catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
}