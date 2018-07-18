#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Trainings/stl_experience.h"
#include "../Trainings/theEulerProject.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::AreEqual(vetor_test(), 0, L"mesage");
		}

		TEST_METHOD(multipliers_brute_test)
		{
			Assert::AreEqual(multipliers_of_5_and_3(10), 23, L"sum of mulitpliers below 10 isn't equal to 23");
			Assert::AreEqual(multipliers_of_5_and_3(2), 0, L"sum of mulitpliers below 2 isn't equal to 0");
			Assert::AreEqual(multipliers_of_5_and_3(1), 0, L"sum of mulitpliers below 1 isn't equal to 0");
			Assert::AreEqual(multipliers_of_5_and_3(0), 0, L"sum of mulitpliers below 0 isn't equal to 0");
			Assert::AreEqual(multipliers_of_5_and_3(-1), 0, L"sum of mulitpliers below -1 isn't equal to 0");
		}

		TEST_METHOD(multipliers_fast_test)
		{
			Assert::AreEqual(multipliers_of_5_and_3_fast(10), 23, L"sum of mulitpliers below 10 isn't equal to 23");
			Assert::AreEqual(multipliers_of_5_and_3_fast(2), 0, L"sum of mulitpliers below 2 isn't equal to 0");
			Assert::AreEqual(multipliers_of_5_and_3_fast(1), 0, L"sum of mulitpliers below 1 isn't equal to 0");
			Assert::AreEqual(multipliers_of_5_and_3_fast(0), 0, L"sum of mulitpliers below 0 isn't equal to 0");
			Assert::AreEqual(multipliers_of_5_and_3_fast(-1), 0, L"sum of mulitpliers below -1 isn't equal to 0");
		}

		TEST_METHOD(fibonachi_even_numbers_sum)
		{
			Assert::AreEqual(sum_of_fibonachi_even_numbers(10), 10, L"sum of fibonachi even num below 10 isn't equal to 10");
			Assert::AreEqual(sum_of_fibonachi_even_numbers(3), 2, L"sum of fibonachi even num below 3 isn't equal to 2");
			Assert::AreEqual(sum_of_fibonachi_even_numbers(2), 0, L"sum of fibonachi even num below 2 isn't equal to 0");
			Assert::AreEqual(sum_of_fibonachi_even_numbers(1), 0, L"sum of fibonachi even num below 1 isn't equal to 0");
			Assert::AreEqual(sum_of_fibonachi_even_numbers(0), 0, L"sum of fibonachi even num below 0 isn't equal to 0");
			Assert::AreEqual(sum_of_fibonachi_even_numbers(-1), 0, L"sum of fibonachi even num below -1 isn't equal to 0");
		}

		TEST_METHOD(fibonachi_even_numbers_sum_fast)
		{
			Assert::AreEqual(sum_of_fibonachi_even_numbers_fast(4000000), 4613732, L"sum of fibonachi even num below 10 isn't equal to 10");
			Assert::AreEqual(sum_of_fibonachi_even_numbers_fast(10), 10, L"sum of fibonachi even num below 10 isn't equal to 10");
			Assert::AreEqual(sum_of_fibonachi_even_numbers_fast(3), 2, L"sum of fibonachi even num below 3 isn't equal to 2");
			Assert::AreEqual(sum_of_fibonachi_even_numbers_fast(2), 0, L"sum of fibonachi even num below 2 isn't equal to 0");
			Assert::AreEqual(sum_of_fibonachi_even_numbers_fast(1), 0, L"sum of fibonachi even num below 1 isn't equal to 0");
			Assert::AreEqual(sum_of_fibonachi_even_numbers_fast(0), 0, L"sum of fibonachi even num below 0 isn't equal to 0");
			Assert::AreEqual(sum_of_fibonachi_even_numbers_fast(-1), 0, L"sum of fibonachi even num below -1 isn't equal to 0");
		}

	};
}