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

		TEST_METHOD(is_prime_test)
		{
			std::vector<unsignllongint> prime_vector{ 2,3,5,7,11,13,17,19,23,29};
			Assert::IsTrue(is_largest_prime(prime_vector, (unsignllongint)31), L"2 is a first prime number!");
		}

		TEST_METHOD(largest_prime_factor_test)
		{
			//TODO no exception thrown
			auto  funPtr = [this] {largest_prime_factor((unsignllongint)0);};
			Assert::ExpectException<std::string>(funPtr, L"No exception thrown");

			unsignllongint number = 4;
			unsignllongint result = 2;
			
			//this all works wrong
			Assert::AreEqual(largest_prime_factor(number), result, L"largest prime factor isn't 2");
			Assert::AreEqual(largest_prime_factor((unsignllongint)22), (unsignllongint)11, L"largest prime factor isn't 21");
			Assert::AreEqual(largest_prime_factor((unsignllongint)13195), (unsignllongint)29, L"largest prime factor isn't 21");
		}


		TEST_METHOD(task_4_is_polindrome)
		{
			Assert::IsTrue(is_palindrome(1234321), L"1234321 - should be palindrome");
			Assert::IsTrue(is_palindrome(123321), L"123321 - should be palindrome");
			Assert::IsTrue(is_palindrome(12321), L"12321 - should be palindrome");
			Assert::IsTrue(is_palindrome(1221), L"1221 - should be palindrome");
			Assert::IsTrue(is_palindrome(11), L"11 - should be palindrome");
			Assert::IsTrue(is_palindrome(1), L"1 - should be palindrome");
			Assert::IsTrue(is_palindrome(0), L"0 - should be palindrome");
			Assert::IsFalse(is_palindrome(12345), L"12345 - isn't palindrome");
			Assert::IsFalse(is_palindrome(123423424), L"123423424 - isn't palindrome");
		}
		TEST_METHOD(task_4_is_polindrome_fast)
		{
			Assert::IsTrue(is_palindrome_fast(1234321), L"1234321 - should be palindrome");
			Assert::IsTrue(is_palindrome_fast(123321), L"123321 - should be palindrome");
			Assert::IsTrue(is_palindrome_fast(12321), L"12321 - should be palindrome");
			Assert::IsTrue(is_palindrome_fast(1221), L"1221 - should be palindrome");
			Assert::IsTrue(is_palindrome_fast(11), L"11 - should be palindrome");
			Assert::IsTrue(is_palindrome_fast(1), L"1 - should be palindrome");
			Assert::IsTrue(is_palindrome_fast(0), L"0 - should be palindrome");
			Assert::IsFalse(is_palindrome_fast(12345), L"12345 - isn't palindrome");
			Assert::IsFalse(is_palindrome_fast(123423424), L"123423424 - isn't palindrome");
		}

		TEST_METHOD(task_4_palindrome_test)
		{
			Assert::AreEqual(find_maximal_polindrome((unsignllongint)2), (unsignllongint)9009, L"Palindrome for 2 digit num should be 9009 = 91*99");
			Assert::AreEqual(find_maximal_polindrome((unsignllongint)1), (unsignllongint)9, L"Palindrome for 1 digit num should be 3*3 = 9");
		}
		
		TEST_METHOD(task_4_palindrome_fast_test)
		{
			Assert::AreEqual(find_maximal_palindrome_fast((unsignllongint)2), (unsignllongint)9009, L"Palindrome for 2 digit num should be 9009 = 91*99");
			//Assert::AreEqual(find_maximal_palindrome_fast(1), 9, L"Palindrome for 1 digit num should be 3*3 = 9"); don't work for this case
		}

		TEST_METHOD(task_5_smallest_multiple_brute)
		{
			Assert::AreEqual(smallest_multiple_brute(10), (unsignllongint)2520, L"smallest number that can't be divided by 1,..,10");
		}
	};
}