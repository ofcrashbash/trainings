#include "c++.h"
#include "basicclasses.h"
#include "friendshipandinheritance.h"
#include "typecasting.h"
#include "Exceptions.h"

int main(int argc, char* argv[])
{
	//Basic Language Syntaxys
	basic_types();
	constants();
	some_operators();
	template_usage();
	foo();
	func_pointer_test();
	memory_allocation();
	anonimous_union_and_structure();

	//Basic Classes Syntaxes 
	test_FirstOneClass();
	initializer_list_test();
	overloaded_operators();
	class_static_members();

	const_class_test();
	template_test();
	special_members_test();

	//friendship and inheritance
	cout << "firnedhsip and relateions" << endl;
	auto a = SomeClass{};
	friendfunction(a);
	friendclass();
	inheritance_test();
	constructor_calls();
	polymorfism_test();

	//Types
	typecasting();
	dynamic_cast_test();
	static_cast_test();
	const_cast_test();
	typeid_test();

	//exceptions
	simple_except();

	return 0;
}