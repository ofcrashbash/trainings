#pragma once

#include <iostream>

using namespace std;

//Class I
class FirstOne
{
public:
	FirstOne();
	FirstOne(int, int);
private:
};
void test_FirstOneClass();


class Val
{
public:
	Val();
	Val(int);
	Val(int, int);
	int Get();
private:
	int val;
};
void initializer_list_test();


//Class II
class OperatorOverload
{
	private: 
		int val;
	
	public:
		OperatorOverload(int a);
		OperatorOverload operator+(const OperatorOverload& a) const;
		OperatorOverload operator+(const int a) const;
		friend OperatorOverload operator+(const int a, const OperatorOverload& b);
		OperatorOverload operator-();
		OperatorOverload operator+();
		OperatorOverload operator++();
		OperatorOverload operator--();
		OperatorOverload operator++(int);
		OperatorOverload operator--(int);
		friend ostream& operator<< (ostream& out, const OperatorOverload& a);

};
void overloaded_operators();


class Static 
{
	public: 
		static int n;
		Static();
};



void class_static_members();

void const_class_test();

void template_test();

void special_members_test();
