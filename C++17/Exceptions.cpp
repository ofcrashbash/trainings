#include "Exceptions.h"
#include <iostream>

using namespace std;

void simple_except()
{
	try
	{
		throw 20; 
		throw 'c';
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}
	catch (char e)
	{
		cout << "Char Exception:" << e << endl;
		throw;//will rethrow same error
	}
}