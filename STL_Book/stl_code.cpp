#include "stl_code.h"

void LOG_PRINT(string str)
{
	cout << endl << endl;
	cout << "-------------------------" << endl;
	cout << str << endl << endl;
}
template <typename T>
void PRINT_ITERABLE(T vec, string str = "")
{
	cout << str << endl;
	cout << "{ ";
	for (auto& el : vec)
		cout << el << ", ";
	cout << " }" << endl;
}

//docs http://www.cplusplus.com/reference/vector/vector/
int vetor_test() {
	std::vector<int> vec;
	//adding elements at the end of vector
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(1);
	vec.push_back(8);
	vec.push_back(5);

	//iterating over vector and printing elements
	for (auto val : vec)
		std::cout << val << std::endl;



	//TODO continue.. vec.to() etc

	//#########
	//iterators 
	//#########
	std::vector<int>::iterator vec_iterator;
	for (vec_iterator = vec.begin(); vec_iterator != vec.end(); ++vec_iterator)
		std::cout << *vec_iterator << std::endl;

	//what is reverse begin
	std::vector<int>::reverse_iterator vec_riterator;
	for (vec_riterator = vec.rbegin(); vec_riterator != vec.rend(); ++vec_riterator) {
		//*vec_iterator += 1; // TODO resolve this
		std::cout << *vec_riterator << std::endl;
	}


	//also there is  const iterator for both.. dirrect and reverse
	std::vector<int>::const_iterator cvec_iter;
	for (cvec_iter = vec.cbegin(); cvec_iter != vec.cend(); ++cvec_iter)
		std::cout << *cvec_iter << std::endl;


	//########
	//CAPACITY
	//########

	std::cout << "size : " << vec.size() << std::endl;
	std::cout << "max_size : " << vec.max_size() << std::endl;
	std::cout << "resize(void) to " << 15 << std::endl;
	vec.resize(15);
	std::cout << "capacity(returns size of allocated memory) : " << vec.capacity() << std::endl;
	std::cout << "empty(test whenever vector is empty) : " << vec.empty() << std::endl;
	std::cout << "reserve(reserve memory for resize) : " << 20 << std::endl;
	vec.reserve(20);
	std::cout << "shrink_to_fit(Requests the container to reduce its capacity to fit its size.)" << std::endl;
	vec.shrink_to_fit();


	//##############
	//ELEMENT ACCESS
	//##############

	//Constant complexity
	std::cout << "[3] : " << vec[3] << std::endl;
	//same as [] but checks for bouds validity and throw error
	std::cout << "at() : " << vec.at(3) << std::endl;
	//access firs element
	std::cout << "front : " << vec.front() << std::endl;
	//access last element
	std::cout << "back : " << vec.back() << std::endl;



	//#########
	//MODIFIERS
	//#########

	//assign
	std::vector<int> test_vec = { 0, 1, 2, 3 };
	vec.assign(test_vec.begin(), test_vec.end());
	for (cvec_iter = vec.cbegin(); cvec_iter != vec.cend(); ++cvec_iter)
		std::cout << *cvec_iter << std::endl;


	vec.assign(5, 1);
	for (cvec_iter = vec.cbegin(); cvec_iter != vec.cend(); ++cvec_iter)
		std::cout << *cvec_iter << std::endl;

	//push_back
	vec.push_back(10000);

	//pop_back - deletes last element
	vec.pop_back();

	//insert 
	//single element
	std::cout << "insertion: " << std::endl;
	cvec_iter = vec.cbegin();
	cvec_iter += 1;
	vec.insert(cvec_iter, 999999);

	//fill
	vec.insert(vec.cbegin() + 2, 10, 8888);
	for (cvec_iter = vec.cbegin(); cvec_iter != vec.cend(); ++cvec_iter)
		std::cout << *cvec_iter << std::endl;




	if (!vec.empty())
		vec.clear();

	return 0;
}

int map_test()
{
	std::map<std::string, char> map;

	map["Key"] = 'B';
	map["Milena"] = 'A';
	map["Vasa"] = 'A';



	std::cout << "map size : " << map.size() << std::endl;
	std::cout << "is map empty : " << map.empty() << std::endl;

	//iterator
	std::map<std::string, char>::iterator map_iter;

	for (map_iter = map.begin(); map_iter != map.end(); ++map_iter)
		std::cout << map_iter->first << " " << map_iter->second << std::endl;

	map.erase("Vasa");
	map.clear();


	return 0;
}

int list_test()
{
	std::list<int> list;
	list.push_front(0);
	list.push_back(1);
	std::list<int>::iterator list_iter;
	for (list_iter = list.begin(); list_iter != list.end(); ++list_iter)
		std::cout << *list_iter << std::endl;

	return 0;
}

int array_test()
{
	//fixed compile time size
	std::array<int, 100> arr;
	arr.fill(10);
	for (auto el : arr)
		std::cout << el << std::endl;

	std::cout << arr.at(10) << std::endl;
	//std::cout << arr.at(1000) << std::endl;
	std::cout << arr.max_size() << std::endl;

	return 0;
}

struct coord
{
	int x, y;
};

bool operator==(const coord &l, const coord &r)
{
	return l.x == r.x && l.y == r.y;
}

//hash template specialization
template<>
struct std::hash<coord>
{
	using argument_type = coord;
	using result_type = std::size_t;
	result_type operator()(const argument_type &c) const
	{
		return static_cast<result_type>(c.x) +
			static_cast<result_type>(c.y);
	}
};

namespace stl_book {
	namespace first {
		void decomposition(void)
		{
			cout << endl;
			cout << "###################" << endl;
			cout << "decomposiotion test" << endl;

			//old approach
			std::pair<int, int> divide_remainder{ 3, 4 };
			const auto result{ divide_remainder };
			std::cout << "16 / 3 is "
				<< result.first << " with a remainder of "
				<< result.second << std::endl;

			//C++17 approach
			//also known ass syntax sugar
			auto[first, second] = divide_remainder;

			//also it is valid for tuples
			std::tuple some_value{ "lalal", std::chrono::system_clock::now(), 1 };
			auto[str, time, usign] = some_value;

			//struct decomposotion
			struct{
				int a;
				int b[2];
				std::string c = "lalalala";
			} my_str;
			auto[a, b, c] = my_str;
			std::cout << c << std::endl;
			//poiters.. perfomance efficient
			auto&[ap, bp, cp] = my_str;
			std::cout << cp << std::endl;

			//it pobably doesn't work with ordinar arrays
			cout << "array decomposition" << endl;
			int f[]{1, 2};
			auto&[b1, b2] = f;
			cout << "b1 = " << b1 << "; b2 = " << b2 << endl;


			//cool iterating over map
			map<string, __int64> animals{
				{ "humans", 7000000000 },
				{ "chickens", 17863376000 },
				{ "camels", 24246291 },
				{ "sheep", 1086881528 },
				/* … */
			};


			// in moment of iterating over map we are receiving pairs: key - value
			for (const auto &[animal, count] : animals)
				cout << animal << " " << count << endl;


		}

		void name_visibility(void)
		{
			if (auto trig = true; trig)
				std::cout << "lala" << std::endl;

			switch (auto key = 'l'; key)
			{
			case 'l':
				break;
			default:
				break;
			}
		}

		void curvly_bracket_initialization()
		{
			LOG_PRINT("curvly bracket initialization");

			int f = { 1 };
			auto x = int{1};
			int z{ 1 };

			PRINT_ITERABLE(vector{1,2,3}, "vector{ 1,2,3 }");
			
			PRINT_ITERABLE(vector{ 1,2,3 }, "vector{ 1,2,3 }");
			//both gives [1,2,3] but!..
			//NOTE!!!!
			//next vector holds 10 elements with value 20!!!
			vector q = { 10, 20};
			PRINT_ITERABLE(q, "vector q = { 10, 20 }");

			PRINT_ITERABLE(vector{ 10 , 20 }, "vector q2{ 10, 20 }");

			vector q3( 10, 20 );
			PRINT_ITERABLE(q3, "vector q3( 10, 20 )");

			//with using keyword AUTO

			//x is type of std::initializer_list<int>
			//TODO what is initializer_list
			auto xx = { 1 };
			auto yy = { 1, 2 };
			PRINT_ITERABLE(yy, "auto yy = { 1, 2 };");

			//auto zz{ 1, 2 }; - error
			//eqauls to last element..3
			auto h = (1, 2, 3);
			//auto zz = {1,2,3.0} - throws erro

			//almost similiar but a little different syntax:
			auto zz{ 1 }; //int
			//auto ww{ 1,2 }; - throws error
		}

		void automatic_template_type(){
			pair my_pair(123, "abc");
			tuple my_tuple(123, 12.3, "abc");
		}

		template <typename T>
		class adable
		{
			T val;
		public:

			adable(T v) : val{ v } {}

			template <typename U>
			T add(U x) const
			{
				if constexpr (std::is_same_v<T, std::vector<U>>)
				{
					auto copy(val);
					for (auto &n : copy)
						n += x;
					return copy;
				}
				return val + x;
			}
		};

		void constrexpr_if()
		{
			adable{1}.add(1);
			std::vector<int> v{ 1, 2, 3 };

			//TODO resolve this
			//auto result = adable<std::vector<int>>{v}.add(10);


			//std::cout << "constrexp result - " << std::endl;
			//for (auto& el : result)
			//	std::cout << el << std::endl;


		}

		template <typename ... Ts>
		auto sum(Ts ... ts)
		{
			return (ts + ... + 0);
		}

		template <typename ... Ts>
		auto product(Ts ... ts)
		{
			return (ts*... * 1);
		}

		template <typename R, typename... Ts>
		auto matches(const R& range, Ts ... ts)
		{
			return (count(begin(range), end(range), ts) + ...);
		}

		template <typename R, typename... Ts>
		bool insert_all(R &set, Ts ... ts)
		{
			return (set.insert(ts).second && ...);
		}

		template <typename T, typename... Ts>
		bool within(T min, T max, Ts ... ts)
		{
			return((min <= ts && ts <= max) && ...);
		}

		template <typename T, typename... Ts>
		void insert_all_vec(vector<T> &vec, Ts ... ts)
		{
			(vec.push_back(ts), ...);
		}

		void variable_arguments_count()
		{
			int the_sum{ sum(1,2,3,4,5,6,7,8,9) };
			int the_sum_1{ sum() };
			int the_prod{ product(1,2,3,4,5,6,7,8,9) };
			int the_prod_1{ product() };
			cout << "Sum : " << the_sum << endl;
			cout << "Product : " << the_prod << endl;
			
			//TODO initializer_list - what is it?
			vector<int> v = { 1, 2, 3, 4, 5, 6 };
			cout << matches(v, 1, 2, 3, 4) << endl;
			cout << matches(string{ "abcdefgh" }, 'a', 'b') << endl;

			//cout << insert_all(v, 7, 8, 9) << endl;

			//within
			cout << "within : " << within(0, 10, 1, 2, 3, 4) << endl;

			//insert
			insert_all_vec(v, 1, 2, 3, 4);
		}
	}

	namespace second {
		void deque_test(){
			deque<int> dq;
		}

		void erase_remove_vector(void) {
			LOG_PRINT("erase_remove_vector");
			std::vector<int> v{ 1, 2, 3, 2, 5, 2, 6, 2, 4, 8 };

			//removing only some values equals to..
			const auto new_end(remove(begin(v), end(v), 2));
			v.erase(new_end, end(v));
			PRINT_ITERABLE(v, "v after erase");

			//removing values that satisfies some condition
			const auto odd([](int i) { return i % 2 != 0; });
			v.erase(remove_if(v.begin(), v.end(), odd), v.end());
			PRINT_ITERABLE(v, "v after i % 2 != 0");

			v.shrink_to_fit();
		}

		void sorted_vector(void)
		{
			vector<string> v{ "some", "sorted", "str", "without", "order", "aaa", "zzz" };
			cout << is_sorted(begin(v), end(v)) << endl;
			sort(v.begin(), v.end());
			cout << is_sorted(begin(v), end(v)) << endl;

			//to preserve order
			auto pos = lower_bound(begin(v), end(v), "lala");
			v.insert(pos, "lala");
		}

		struct billionaire {
			std::string name;
			double dollars;
			std::string country;
		};

		template <typename M>
		void print(const M &m)
		{
			std::cout << "Race palacement:" << std::endl;
			for (const auto &[placement, driver] : m)
				std::cout << placement << " : " << driver << std::endl;
		}

		void insert_into_map(void)
		{
			std::list<billionaire> billionaires{
				{"Bill Gates", 86.0, "USA"},
				{"Warren Buffet", 75.6, "USA"},
				{"Jeff Bezos", 72.8, "USA"},
				{ "Mark Zuckerberg", 56.0, "USA" },
				{ "Carlos Slim", 54.5, "Mexico" },
				// ...
				{ "Bernard Arnault", 41.5, "France" },
				// ...
				{ "Liliane Bettencourt", 39.5, "France" },
				// ...
				{ "Wang Jianlin", 31.3, "China" },
				{ "Li Ka-shing", 31.2, "Hong Kong" }
				// ...
			};

			std::map<std::string, std::pair<const billionaire, std::size_t>> m;
			for (const auto &b : billionaires)
			{
				auto[iterator, sucess] = m.try_emplace(b.country, b, 1);
				if (!sucess)
					iterator->second.second += 1;
			}

			for (const auto &[key, value] : m) {
				const auto &[b, count] = value;
				std::cout << b.country << " : " << count
					<< " billionaires. Richest is "
					<< b.name << " with " << b.dollars
					<< " B$\n";
			}


			//insertion with hint
			std::pair<const billionaire, std::size_t> new_el{ { "Oleg Kmechak", 19.1, "UA"}, 1 };
			m.insert(std::end(m), { "UA", new_el });

			//changing name of key
			std::map<int, std::string> race_placement{
				{ 1, "Mario" }, { 2, "Luigi" }, { 3, "Bowser" },
				{ 4, "Peach" }, { 5, "Yoshi" }, { 6, "Koopa" },
				{ 7, "Toad" }, { 8, "Donkey Kong Jr." }
			};
			print(race_placement);
			{
				//в загальному випадку ключі є const і їх не можна змінити,
				//але після extracr їх можна змінити
				auto a(race_placement.extract(3));
				auto b(race_placement.extract(8));
				std::swap(a.key(), b.key());
				race_placement.insert(std::move(a));
				race_placement.insert(std::move(b));
			}
			print(race_placement);



		}


		void unordered_map(void)
		{
			std::unordered_map<coord, int> m{ {{0,0}, 1}, {{0,1}, 2}, {{2,1}, 3} };
			for (const auto &[key, value] : m)
				cout << "{(" << key.x << ", " << key.y << "): " << value << "}  ";
			cout << endl;
		}

		void unique_set(void)
		{
			cout << "unique set" << endl;
			set<string> set;
			istream_iterator<string> it{ cin };
			istream_iterator<string> end;
			copy(it, end, inserter(set, set.end()));
			for (const auto &el : set)
				cout << el << endl;
		}

		//polish notation
		template <typename IT>
		double evaluate_rpn(IT it, IT end)
		{
			std::stack<double> val_stack;
			auto pop_stack([&]() {
				auto r{ val_stack.top() };
				val_stack.pop();
				return r;
			});

			std::map<std::string, double(*)(double, double)> ops{
				{ "+", [](double a, double b) {return a + b; }},
				{ "-", [](double a, double b) {return a - b; } },
				{ "*", [](double a, double b) {return a * b; } },
				{ "/", [](double a, double b) {return a / b; } },
				{ "^", [](double a, double b) {return std::pow(a, b); } },
				{ "%", [](double a, double b) {return std::fmod(a, b); } },
			};

			for (; it != end; ++it) {
				std::stringstream ss{ *it };
				if (double val; ss >> val)
					val_stack.push(val);
				else
				{
					const auto r{ pop_stack() };
					const auto l{ pop_stack() };
					try
					{
						const auto & op(ops.at(*it));
						const double result{ op(l,r) };
						val_stack.push(result);
					}
					catch (const std::out_of_range &)
					{
						throw std::invalid_argument(*it);
					}
				}
			}

			return val_stack.top();
		}

		void working_with_stack(void)
		{
			std::cout << "working with stack" << std::endl;
			std::cout << "polish notation" << std::endl;
			try {
				std::cout << evaluate_rpn(std::istream_iterator<std::string>{std::cin}, {}) << std::endl;
			}
			catch (const std::invalid_argument &e) {
				std::cout << "Invalid operator: " << e.what() << std::endl;
			}
		}

		std::string filter_punctuation(const std::string & s)
		{
			const char *forbidden{ ".,:; " };
			const auto idx_start{ s.find_first_not_of(forbidden) };
			const auto idx_end{ s.find_last_not_of(forbidden) };
			return s.substr(idx_start, idx_end - idx_start + 1);
		}

		void map_histogram(void)
		{
			std::cout << "map histogram" << std::endl;

			using namespace std;

			map<string, size_t> words;
			int max_word_len{ 0 };
			string s;
			while (cin >> s)
			{
				auto filtered{ filter_punctuation(s) };
				max_word_len = max<int>(max_word_len, (int)filtered.length());
				++words[filtered];
			}

			vector<pair<string, size_t>> word_counts;
			word_counts.reserve(words.size());
			move(begin(words), end(words), back_inserter(word_counts));

			sort(begin(word_counts), end(word_counts), [](const auto &a, const auto &b) {
				return a.second > b.second;
			});

			cout << "# " << setw(max_word_len) << "<WORD>" << "#<COUNT>\n";
			for (const auto&[word, count] : word_counts)
				cout << setw(max_word_len + 2) << word << " #" << count << endl;

		}


		std::string filter_ws(const std::string &s)
		{
			const char *ws{ " \r\n\t" };
			const auto a{ s.find_first_not_of(ws) };
			const auto b{ s.find_last_not_of(ws) };
			if (a == std::string::npos)
			{
				return {};
			}
			return s.substr(a, b - a + 1);
		}

		void multimap_test(void)
		{
			std::cout << "multimap test" << std::endl;
			using namespace std;

			string content{ "ja, ls. sdfsdfsdfs dfsdf sdf sdf sf. sdf ,sd fsdf s, sdfsd f,sd s df sd, ,sdf sdf sdf ,sd fsdf sdf . sdfkfds . dsfk sdk." };

			multimap<size_t, string> ret;
			const auto end_it{ end(content) };
			auto it1{ begin(content) };
			auto it2{ find(it1, end_it,'.') };
			while (it1 != end_it && it2 != end_it && distance(it1, it2) > 0)
			{
				string s{ filter_ws({it1, it2}) };

				if (s.length() > 0)
				{
					const auto words(count(begin(s), end(s), ' ') + 1);
					ret.emplace(make_pair(words, move(s)));
				}
				it1 = next(it2, 1);
				it2 = find(it1, end_it, '.');
			}
			for (const auto &[word_count, sentence] : ret)
				cout << word_count << " words: " << sentence << endl;
		}

		void priority_quene_test(void)
		{
			using namespace std;

			using todo_item = pair<size_t, string>;
			priority_queue<todo_item> q;

			initializer_list<todo_item> il{
				{1, "dishes"},
				{0, "watch tv"},
				{2, "do homework"},
				{0, "read comics"}
			};

			for (const auto &p : il)
				q.push(p);

			while (!q.empty()) {
				cout << q.top().first << ": " << q.top().second << endl;
				q.pop();
			}
		}
	}
}