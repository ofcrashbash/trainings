#include "friendshipandinheritance.h"

#include <iostream>

using namespace std;



void friendfunction(SomeClass& a)
{
	//Typical use cases of friend functions are operations that 
	//are conducted between two different classes accessing private 
	//or protected members of both
	cout << " private member : " << a.private_value << endl;
}


void FriendClass::PrintPrivate(const SomeClass& a)
{
	cout << a.private_value << endl;
}

void friendclass()
{
	auto a = SomeClass{};
	FriendClass{}.PrintPrivate(a);
}


/*
	Inheritacne Test
*/



void Polygon::set_values(int a, int b)
{
	width = a; height = b;
}

int Rectangle::area()
{
	return width * height;
}

int Triangle::area()
{
	return width * height / 2;
}


void inheritance_test()
{
	cout << "inheritance test" << endl;
	Rectangle r;
	r.set_values(1, 2);
	r.area();

	Triangle t;
	t.set_values(1, 23);
	t.area();

	//What is inherited from the base class ?
	//	In principle, a publicly derived class inherits access to every 
	//  member of a base class except :
	//
	//	its constructorsand its destructor
	//	its assignment operator members (operator=)
	//	its friends
	//	its private members

}


/*
	Constructor calls
*/

//constructor calls
Mother::Mother()
{
	cout << "Mother: no parameters\n";
}
Mother::Mother(int a)
{
	cout << "Mother: int parameter\n";
}

Father::Father()
{
	cout << "Father: no parameters\n";
}
Father::Father(int a)
{
	cout << "Father: int parameter\n";
}

Daughter::Daughter(int a)
{
	cout << "Daughter: int parameter\n\n";
}

Son::Son(int a) : Mother(a), Father(a)
{
	cout << "Son: int parameter\n\n";
}

void constructor_calls()
{
	cout << "constructor calls" << endl;
	Daughter{ 1 };
	Son{ 2 };
}

/*
	Polymorfism
*/
void polymorfism_test()
{
	cout << "polymorfism" << endl;

	Triangle b;

	Polygon *pb;
	pb = &b;

	pb->set_values(1, 2);

	cout << " area Polygon: " << pb->area() << endl;

	//Non - virtual members can also be redefined in derived classes, 
	//but non - virtual members of derived classes cannot be accessed 
	//through a reference of the base class : i.e., if virtual is 
	//removed from the declaration of area in the example above, 
	//all three calls to area would return zero, because in all cases, 
	//the version of the base class would have been called instead.

	//A class that declares or inherits a virtual function is called 
	//a polymorphic class.

	cout << " area : " << b.area() << endl;

}