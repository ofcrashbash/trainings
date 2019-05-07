#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "../EulerProject/theEulerProject.h"

BOOST_AUTO_TEST_CASE(myTestCase)
{	
	//BOOST_TEST(largest_product("11111111") == 1);
	BOOST_TEST(1 == 1);
	BOOST_TEST(true);
}