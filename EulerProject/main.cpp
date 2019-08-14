#include <iostream>
#include "theEulerProject.h"
#include <limits.h>

int main(int argc, char ** argv)
{

	cout << "##################" << endl;
	cout << "The Eulear Project" << endl;
	cout << "##################" << endl;
	
	cout << "Task #10 Total of prime numbers" << endl;
	cout << "bellow limit 2 000 000 is " << fast_sum_of_prime(2000000) << endl;
	
	cout << "Task #9 Pithagorian product" << endl;
	cout << product_of_pithagorian_numbers();
	
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
	cout << endl;

	cout << "Task #8 Max product in string" << endl;
	auto str = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	cout << "largest product of " << 13 << " digits in string: " << str << " is: " << largest_product(str, 13) << endl;


	return 0;
}