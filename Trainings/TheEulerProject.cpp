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