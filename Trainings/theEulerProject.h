#pragma once
#include <iostream>
#include <cmath>
#include <vector>

//first task
int multipliers_of_5_and_3(int max);
int multipliers_of_5_and_3_fast(int max);

//second one
int sum_of_fibonachi_even_numbers(int max);
int sum_of_fibonachi_even_numbers_fast(int max);

//third
using unsignllongint = unsigned long long int;
bool is_largest_prime(std::vector<unsignllongint> &prime_vector, unsignllongint number);
unsignllongint largest_prime_factor(unsignllongint number);

//from web
unsignllongint largest_prime_web(unsignllongint);