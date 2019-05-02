#pragma once

using namespace std;

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
		void deque_test(void);
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
	namespace iter {
		void custom_iterator_test();
		void iter_adaptor();
		void fibonachi_iterator_test();
	};
}