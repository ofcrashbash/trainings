#pragma once

/*
	different types of conversion for classes
*/

class A {};

class B
{
public:
	B(const A& a);
	B& operator = (const A& a);
	operator A();
};


void typecasting();


/*
	Keyword explicit
*/

class B_Explicit
{
public:
	explicit B_Explicit(const A& a);
	B_Explicit& operator = (const A& a);
	explicit operator A();
};

/*
	Tupe conversion keywords
*/

//dynamic cast
class Base { virtual void dummy() {} };
class Derived : public Base { int a; };

void dynamic_cast_test();

//static_cats
class Base2 {};
class Derived2 : public Base2 { };

void static_cast_test();
//reinterpret_cast - bit by bit copy, thats why it is platform dependend.

void const_cast_test();
void typeid_test();