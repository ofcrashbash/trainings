#include "stl_experience.h"

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
	std::vector<int> test_vec = {0, 1, 2, 3};
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