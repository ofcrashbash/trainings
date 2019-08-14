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
	double golden_ratio_1 = (1. + sqrt(5.)) / 2.;
	double golden_ratio_2 = (1. - sqrt(5.)) / 2.;
	int value = (int)floor( (pow(golden_ratio_1, n) - pow(golden_ratio_2, n)) / sqrt(5.));
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
bool is_largest_prime(vector<unsignllongint> & prime_vector, unsignllongint number)
{
	for (auto prime : prime_vector)
		if (number % prime == 0)
			return false;
	return true;
}


unsignllongint largest_prime_factor(unsignllongint number)
{
	unsignllongint last_prime = 2;
	vector<unsignllongint> primes_vector = { last_prime };
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
			last_prime = last_number;
	}

	for (auto prime : primes_vector)
		cout << prime << " ";
	cout << endl;

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
		 cout << "{ " << factor << ", " << count << " }" <<  endl;
	}
	unsignllongint maxFactor = (unsignllongint) sqrt(number);
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
			maxFactor = (unsignllongint) sqrt(number);
			 cout << "{ " << factor << ", " << count << " }" << endl;
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

bool is_palindrome(unsignllongint val)
{
	vector<unsignllongint> digits;
	digits.reserve(6);
	auto temp_val = val;
	unsignllongint modulo = 0;

	while (val > 0)
	{
		modulo = val % 10;
		if(val > 0)
			digits.push_back(modulo);
		val /= 10;
	}

	vector<unsignllongint> rev_digits(digits);

	//FIXME: !!
	//reverse(rev_digits.begin(), rev_digits.end());

	if (rev_digits == digits)
		return true;
	else
		return false;
}

bool is_palindrome_fast(unsignllongint val)
{
	unsignllongint reversed = 0;
	auto temp_val = val;
	while (val > 0)
	{
		reversed = 10 * reversed + val % 10;
		val /= 10;
	}
	return reversed == temp_val;
}

unsignllongint find_maximal_polindrome(unsignllongint digit_num)
{
	unsignllongint max_palindrome = 0;
	for (unsignllongint i = (unsignllongint)pow(10, digit_num) - 1; i > (unsignllongint)pow(10, digit_num - 1); --i)
		for (unsignllongint j = i; j > (unsignllongint)pow(10, digit_num - 1); --j)
			if (is_palindrome_fast(i * j) && i*j > max_palindrome)
			{
				cout << i <<" * "<< j <<" = " << i * j << endl;
				max_palindrome = i * j;
			}
	return max_palindrome;
}

unsignllongint find_maximal_palindrome_fast(unsignllongint digit_num)
{
	unsignllongint i = (unsignllongint)(pow(10, digit_num) - 1);
	unsignllongint j, dj, max_palindrome{0};
	unsignllongint maxi{ 0 }, maxj{ 0 };
	while (i > pow(10, digit_num - 1))
	{
		if (i % 11 == 0)
		{
			j = (unsignllongint)(pow(10, digit_num) - 1);
			dj = 1;
		}
		else
		{
			j = (unsignllongint)(floor((int)pow(10, digit_num) / 11) * 11);
			dj = 11;
		}

		while (j >= i) 
		{
			if (i * j <= max_palindrome)
				break;
			if (is_palindrome_fast(i * j))
			{
				max_palindrome = i * j;
				maxi = i;
				maxj = j;
			}
			j -= dj;
		}
		i -= 1;
	}
	cout << maxi << " * " << maxj << " = " << max_palindrome << endl;
	return max_palindrome;
}


//TASK 5
//BRUTE FORCE

bool is_multile_of_brute(int max_div, unsignllongint value)
{
	for (int i = 1; i < max_div; ++i)
		if (value % i != 0)
			return false;
	return true;
}


unsignllongint smallest_multiple_brute(int max_div)
{
	unsignllongint max_multiple = 1, next_multiple = 0;
	for (int i = 1; i < max_div; ++i)
		max_multiple *= i;

	for (unsignllongint i = max_multiple - 1; i > 0; --i)
		if (is_multile_of_brute(max_div, i)) 
		{
			next_multiple = i;
			break;
		}

	return max_multiple - next_multiple;
}


//TASK 6
//probably fastes solution
unsignllongint square_diff(int max_num)
{
	unsignllongint sum = 0;
	for (unsignllongint i = 1; i < max_num; ++i)
		for (unsignllongint j = i + 1; j <= max_num; ++j)
			sum += i * j;

	return sum *= 2;
}


//Task 7
//primes
unsignllongint prime(unsigned num)
{
	vector<unsignllongint> prime_vector;
	prime_vector.reserve(num);
	unsignllongint first_prime = 2;
	prime_vector.push_back(first_prime);

	unsignllongint i = first_prime + 1;
	
	while (prime_vector.size() < num)
	{
		bool is_prime = true;
		for (auto prime : prime_vector)
			if (i % prime == 0)
			{
				is_prime = false;
				break;
			}
		
		if (is_prime)
			prime_vector.push_back(i);

		i += 2;
	}


	return prime_vector.back();
}

//Task 8
//Largest product in series
unsignllongint largest_product(const string str, const int num_of_digits)
{
	unsignllongint max_prod = 0;
	for (unsigned i = 0; i <= str.length() - num_of_digits; ++i)
	{	
		//getting num_of_digits sub string
		auto part_str = str.substr(i, num_of_digits);
		
		//calculation of product of those digits
		unsignllongint cur_prod = 1;
		for (auto digit : part_str) 
			cur_prod *= atoi(&digit);


		//updating max value if it is bigger
		if (cur_prod > max_prod)
			max_prod = cur_prod;
	}
	return max_prod;
}

//Task 9
//Pithagorian numbers
unsignllongint product_of_pithagorian_numbers()
{
	unsignllongint 
		product = 0,
		total = 1000;

	for (unsignllongint a = 1; a < 500; ++a)
		for (unsignllongint b = a + 1; b < 500; ++b)
			if (pow(a, 2) + pow(b, 2) == pow(1000 - a - b, 2))
				product = a * b * (1000 - a - b);

	return product;
}
