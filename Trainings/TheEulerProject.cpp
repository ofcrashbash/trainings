#include "theEulerProject.h"


int multipliers_of_5_and_3(int max)
{
	int sum{0};
	int mult_of_3{1}, mult_of_5{ 1 };

	//Brute force
	int i = 1;
	
	while(true)
	{
		mult_of_3 = 3 * i++;
		if (mult_of_3 < max)
		{
			sum += mult_of_3;
		}
		else
			break;
	}
	
	
	//but now except of mulipliers of 3.. cos they are already
	//catched by previous cycle!
	i = 1;
	while(true)
	{
		mult_of_5 = 5 * i;
		if (mult_of_5 < max )
		{
			if (i % 3 != 0) {
				sum += mult_of_5;
			}
		}
		else
			break;
		i++;
	}

	return sum;
}
int multipliers_of_5_and_3_fast(int max)
{
	int count_3 = (max - 1) / 3;
	int count_5 = (max - 1) / 5;
	int count_5_3 = (max - 1) / 3 / 5;
	int sum = 0;
	
	sum = 3 * count_3 * (count_3 + 1) / 2 + 5 * count_5 * (count_5 + 1) / 2 - 15 * count_5_3 * (count_5_3 + 1) / 2;
	
	return sum;
}
//brute force
//O(N)
int sum_of_fibonachi_even_numbers(int max) 
{
	int sum = 0;
	
	int p1 = 0;
	int p2 = 1;
	while (p1 < max)
	{

		if (p1 % 2 == 0) 
			sum += p1;

		//fibonachi sequence calculation
		int temp = p2;
		p2 += p1;
		p1 = temp;
	}

	return sum;
}

//fast O(ln(N)???)
//TODO how about type overflow???
int fibonachi(int n)
{
	double golden_ratio_1 = (1. + std::sqrt(5.)) / 2.;
	double golden_ratio_2 = (1. - std::sqrt(5.)) / 2.;
	int value = std::floor( (std::pow(golden_ratio_1, n) - std::pow(golden_ratio_2, n)) / std::sqrt(5.));
	return value;
}
int sum_of_fibonachi_even_numbers_fast(int max)
{
	int val = 0;
	int n = 1;
	int sum = 0;

	do 
	{
		sum += val;
		val = fibonachi(3*n++);
	} while (val < max);

	return sum;
}



//Task 3 
//Brute Force
bool is_largest_prime(std::vector<unsignllongint> & prime_vector, unsignllongint number)
{
	for (auto prime : prime_vector)
		if (number % prime == 0)
			return false;
	return true;
}


unsignllongint largest_prime_factor(unsignllongint number)
{
	unsignllongint last_prime = 2;
	std::vector<unsignllongint> primes_vector = { last_prime };
	unsignllongint last_number = 2;

	if (number < 1)
		throw("number is less then 1");

	//init
	if (number % last_prime == 0)
		last_number = last_prime;

	while (last_number <= number)
	{
		//looking for next prime number
		while (!is_largest_prime(primes_vector, ++last_number) && last_number <= number);

		//collecting all prime numbers
		
		primes_vector.push_back(last_number);

		if (number % last_number == 0)
			std::cout << last_number << std::endl;
			last_prime = last_number;
	}

	for (auto prime : primes_vector)
		std::cout << prime << " ";
	std::cout << std::endl;

	return last_prime;
}

unsignllongint largest_prime_web(unsignllongint number)
{
	
	int lastFactor = 1;

	int factor = 2;
	if (number % factor == 0)//2
	{
		lastFactor = factor;
		number /= factor;
		int count = 1;
		while (number % factor == 0) {
			count++;
			number /= factor;
		}
		std::cout << "{ " << factor << ", " << count << " }" << std::endl;
	}
	unsignllongint maxFactor = std::sqrt(number);
	factor = 3;
	while (number > 1 && factor < maxFactor)
	{
		if (number % factor == 0)
		{
			lastFactor = factor;
			number /= factor;
			int count = 1;
			while (number % factor == 0) {
				count++;
				number /= factor;
			}
			maxFactor = std::sqrt(number);
			std::cout << "{ " << factor << ", " << count << " }" << std::endl;
		}
		factor += 2;
	}
	if (number == 1)
		return maxFactor;
	else
		return number;
}

//Task 4
//Brute Force

bool is_palindrome(int val)
{
	std::vector<int> digits;
	digits.reserve(6);
	auto temp_val = val;
	int modulo = 0;

	while (val > 0)
	{
		modulo = val % 10;
		if(val > 0)
			digits.push_back(modulo);
		val /= 10;
	}

	std::vector<int> rev_digits(digits);
	std::reverse(rev_digits.begin(), rev_digits.end());

	if (rev_digits == digits)
		return true;
	else
		return false;
}

bool is_palindrome_fast(int val)
{
	int reversed = 0;
	auto temp_val = val;
	while (val > 0)
	{
		reversed = 10 * reversed + val % 10;
		val /= 10;
	}
	return reversed == temp_val;
}

int find_maximal_polindrome(int digit_num)
{
	int max_palindrome = 0;
	for (int i = (int)std::pow(10, digit_num) - 1; i > (int)std::pow(10, digit_num - 1); --i)
		for (int j = i; j > (int)std::pow(10, digit_num - 1); --j)
			if (is_palindrome_fast(i * j) && i*j > max_palindrome)
			{
				std::cout << i <<" * "<< j <<" = " << i * j << std::endl;
				max_palindrome = i * j;
			}

	return max_palindrome;
}