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
			std::cout << mult_of_3 << std::endl;
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
				std::cout << mult_of_5 << std::endl;
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
	std::cout << count_3 << " " << count_5 << " " << count_5_3 << std::endl;
	
	sum = 3 * count_3 * (count_3 + 1) / 2 + 5 * count_5 * (count_5 + 1) / 2 - 15 * count_5_3 * (count_5_3 + 1) / 2;
	
	return sum;
}