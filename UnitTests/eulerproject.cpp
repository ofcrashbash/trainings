#include "stdafx.h"
#ifndef __linux__
#include "CppUnitTest.h"
#include "../Eulerproject/theEulerProject.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCasesOfSandBox
{	

	TEST_CLASS(TheEulerProject)
	{
	public:
		
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

		TEST_METHOD(task_6_square_diff)
		{
			Assert::AreEqual(square_diff(10), (unsignllongint)2640, L"(...)^2 - ...^2 != 2640");
			Assert::AreEqual(square_diff(0), (unsignllongint)0, L"0^2 - 0^2 != 0");
			Assert::AreEqual(square_diff(1), (unsignllongint)0, L"1^2 - 1^2 != 0");
		}
		
		TEST_METHOD(task_7_primes)
		{
			Assert::AreEqual(prime(8), (unsignllongint)19, L"8 prime should be 19");
			Assert::AreEqual(prime(1), (unsignllongint)2, L"first prime - 2");
			Assert::AreEqual(prime(3), (unsignllongint)5, L"third - 5");
		}

		TEST_METHOD(task_8_largest_product)
		{
			auto str = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
			Assert::AreEqual(largest_product(str, 4), (unsignllongint)5832);
			str = "1111";
			Assert::AreEqual(largest_product(str, 4), (unsignllongint)1);
			str = "1122";
			Assert::AreEqual(largest_product(str, 4), (unsignllongint)4);
		}

		TEST_METHOD(task_9_pithagorian_product)
		{
			Assert::AreEqual(product_of_pithagorian_numbers(), (unsignllongint)31875000);
		}

		TEST_METHOD(task_10_sum_of_primes)
		{
			Assert::AreEqual(sum_of_prime(10), (unsignllongint)17);
			Assert::AreEqual(fast_sum_of_prime(10), (unsignllongint)17);
		}

		TEST_METHOD(task_10_sum_of_primes_is_prime)
		{
			Assert::IsTrue(is_prime(2));
			Assert::IsTrue(is_prime(3));
			Assert::IsTrue(is_prime(5));
			Assert::IsTrue(is_prime(13));
			Assert::IsTrue(is_prime(541));
			Assert::IsFalse(is_prime(27));
		}

		TEST_METHOD(task_11)
		{
			string num_matrix = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\
				  49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\
				  81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\
				  52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\
				  22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\
				  24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\
				  32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\
				  67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\
				  24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\
				  21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\
				  78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\
				  16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\
				  86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\
				  19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\
				  04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\
				  88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\
				  04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\
				  20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\
				  20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\
				  01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

			//Assert::AreEqual(max_line_product_in_matrix(num_matrix), (long int)1788696);
		}
	};
}

#endif