#include <iostream>
#include "theEulerProject.h"
#include <limits.h>

int main(int argc, char ** argv)
{

	cout << "##################" << endl;
	cout << "The Eulear Project" << endl;
	cout << "##################" << endl;
	cout << "Task #1" << endl;
	cout << "sum of all multipliers of 3 and 5 below 10 : " << multipliers_of_5_and_3(10) << endl;
	cout << "sum of all multipliers of 3 and 5 below 20 : " << multipliers_of_5_and_3(20) << endl;
	cout << "sum of all multipliers of 3 and 5 below 35 : " << multipliers_of_5_and_3(35) << endl;
	cout << "sum of all multipliers of 3 and 5 below 1000 : " << multipliers_of_5_and_3(1000) << endl;

	cout << "#####FAST######" << endl;
	cout << "sum of all multipliers of 3 and 5 below 10 : " << multipliers_of_5_and_3_fast(10) << endl;
	cout << "sum of all multipliers of 3 and 5 below 20 : " << multipliers_of_5_and_3_fast(20) << endl;
	cout << "sum of all multipliers of 3 and 5 below 35 : " << multipliers_of_5_and_3_fast(35) << endl;
	cout << "sum of all multipliers of 3 and 5 below 1000 : " << multipliers_of_5_and_3_fast(1000) << endl;


	
	cout << "Task #2" << endl;
	cout << "Fibonachi sum below 10 : " << sum_of_fibonachi_even_numbers(10) << endl;
	cout << "Fibonachi sum below 4mln : " << sum_of_fibonachi_even_numbers(4000000) << endl;
	cout << "#####FAST######" << endl;
	cout << "Fibonachi sum below 10 : " << sum_of_fibonachi_even_numbers_fast(10) << endl;
	cout << "Fibonachi sum below 4mln : " << sum_of_fibonachi_even_numbers_fast(4000000) << endl;
	
	
	cout << "Task #3" << endl;
	cout << "solution fron web. Factor of : " << ULLONG_MAX<< "  " << largest_prime_web(ULLONG_MAX) << endl;
	cout << "solution fron web. Factor of : " << 135771890205034978 << "  " << largest_prime_web(135771890205034978) << endl;

	cout << "Task #4 Palnidromes" << endl;
	cout << "max palindrome for 2 digit nums : " << find_maximal_polindrome(2) << endl;
	cout << "max palindrome for 3 digit nums : " << find_maximal_polindrome(3) << endl;
	cout << "max palindrome for 4 digit nums : " << find_maximal_polindrome(4) << endl;
	cout << "max palindrome for 2 digit nums : " << find_maximal_palindrome_fast(2) << endl;
	cout << "max palindrome for 7 digit nums : " << find_maximal_palindrome_fast(7) << endl;

	cout << "Task #5 Smallest multiple" << endl;
	cout << "Smallest number that can be divided by 1,..,10: " << smallest_multiple_brute(10) << endl;
	cout << "Smallest number that can be divided by 1,..,20: " << smallest_multiple_brute(20) << endl;

	
	cout << "Task #6 Smallest multiple" << endl;
	cout << "(1+2+..+3)^2 - 1^2 - 2^2 - .. - 3^2 = " << square_diff(3) << endl;
	cout << "(1+2+..+10)^2 - 1^2 - 2^2 - .. - 10^2 = " << square_diff(10) << endl;
	cout << "(1+2+..+100)^2 - 1^2 - 2^2 - .. - 100^2 =  " << square_diff(100) << endl;

	cout << "Task #7 Primes" << endl;
	cout << "first prime - " << prime(2) << endl;
	cout << "tenth prime - " << prime(100000) << endl;

	return 0;
}