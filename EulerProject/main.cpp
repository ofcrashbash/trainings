#include <iostream>
#include "theEulerProject.h"
#include <limits.h>

int main(int argc, char ** argv)
{

	cout << "##################" << endl;
	cout << "The Eulear Project" << endl;  
	cout << "##################" << endl;
	
	cout << "Task #11 maximal product of numbers in matrix" << endl;
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
	cout << num_matrix << " max product is: " << max_line_product_in_matrix(num_matrix) << endl;

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