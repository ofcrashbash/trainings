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



// cosnt member function: trick is such that only 
// const memberes can be accesed by const object

class ConstClass
{
	public:
		void foo()
		{
			cout << "non-const member" << endl;
		}

		void foo() const
		{
			cout << "const member" << endl;
		}
};

void const_class_test()
{
	ConstClass la; 
	const ConstClass ka;

	la.foo();
	ka.foo();
}




//class templates
template<class T>
class TemplateTest
{
	T val;
public:
	TemplateTest(T init_val) : val{ init_val } {};
};

//template specialization
template<>
class TemplateTest<char>
{
	char val;
};


void template_test()
{
	TemplateTest<unsigned int> la = { 1 };
	//TemplateTest ra{ 1 }; RESOLVE cmake fails with this line..
}


//special members
template <class T = int>
class Special
{
	T val;

public:
	//Default constructor
	Special() {}

	//constructor
	Special(T init_val) : val{ init_val }
	{
		cout << val << endl;
		cout << "Contructor" << endl;
	}

	//desctructor
	~Special()
	{
		cout << val << endl;
		cout << "Destructor" << endl;
	}

	//Copy constructor
	Special(const Special& sp)
	{
		val = sp.val;
		cout << val << endl;
		cout << "Copy Contructor" << endl;
	}

	//Copy Asignement constructor
	Special& operator=(const Special& a)
	{
		cout << val << endl;
		cout << "Copy Asignment" << endl;
		val = a.val;

		return *this;
	}

	//move constructor
	Special(Special&& a)
	{
		cout << val << endl;
		cout << "Move Contructor" << endl;
		val = a.val;
	}

	//move asignment
	Special& operator=(Special&& a)
	{
		cout << val << endl;
		cout << "Move Asignemt" << endl;
		val = a.val;
		return *this;
	}

};

class SpecialDefault
{
public:
	SpecialDefault() = default;
	~SpecialDefault() = default;
	SpecialDefault(SpecialDefault& sd) = default;
	SpecialDefault(SpecialDefault&& sd) = delete;
	SpecialDefault& operator=(const SpecialDefault& sd) = delete;
	SpecialDefault& operator=(SpecialDefault&& sd) = delete;
};

Special<string> foo()
{
	return Special<string>{ "foo" };
}

//moves corresponds to operations with rvalues
//Return Value Optimization. - rvalue - return value
void special_members_test()
{
	Special<string> la("la"), ka("ka");//constructor
	Special<string> ga(ka)/*copy cosntructor*/; 
	Special<string> ra = foo();//move constructor
	Special<string> pa;

	ka = la;//copy assignemnt
	ra = Special<string>{};//move assignment
	pa = foo();// move assignment


	//also all those special members are generated automaticaly if 
	//they are not specified.

	SpecialDefault a, b, c;
	SpecialDefault d(a);
	//a = b; can't be specified cos asignment constructor is deleted

	//In general, and for future compatibility, classes that explicitly 
	//define one copy / move constructor or one copy / move assignment 
	//but not both, are encouraged to specify either delete or default 
	//on the other special member functions they don't explicitly define.
}