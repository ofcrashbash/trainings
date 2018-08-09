#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <array>
#include <chrono>
#include <deque>
#include <algorithm>
#include <iterator>
#include <set>
#include <cassert>
#include <unordered_map>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <queue>

int vetor_test();
int map_test();
int list_test();
int array_test();
namespace stl_book {
	namespace first {
		void decomposition(void);
		void name_visibility(void);
		void curvly_bracket_initialization(void);
		void automatic_template_type(void);
		void constrexpr_if(void);
		void variable_arguments_count(void);
	}
	namespace second {
		void deque(void);
		void erase_remove_vector(void);
		void sorted_vector(void);	
		void insert_into_map(void);
		void unordered_map(void);
		void unique_set(void);
		void working_with_stack(void);
		void map_histogram(void);
		void multimap_test(void);
		void priority_quene_test(void);
	}
}