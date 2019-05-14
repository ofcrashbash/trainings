#pragma once


class SomeClass
{
	int private_value = 9;
	friend void friendfunction(SomeClass& a);

	//so it can be used for testing! private members
	friend void wihoutdeclaration(SomeClass& a);
	friend class FriendClass;
};

class FriendClass
{
public:
	void PrintPrivate(const SomeClass& a);

};


void friendfunction(SomeClass& a);
void friendclass();



class Polygon {
protected://pay atention that it is protected, not private
	int width, height;
private:
	int priv_value;
public:
	virtual int area() = 0;//important moment
	void set_values(int a, int b);
};

class Rectangle : public/*this serves to limit parent class access*/ Polygon {
public:
	int area();
};

class Triangle : public Polygon {
public:
	int area();
};

void inheritance_test();


//Constructor Calls
class Mother {
public:
	Mother();
	Mother(int a);
};

class Father {
public:
	Father();
	Father(int a);
};

class Daughter : public Mother, public Father {
public:
	Daughter(int a);
};

class Son : public Mother, public Father {
public:
	Son(int a);
};

void constructor_calls();

void polymorfism_test();