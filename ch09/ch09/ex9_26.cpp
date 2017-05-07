#include <iostream>
#include <list>
#include <vector>


int main9(){
	int a[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	//intialize vector with array.we need to specify the head and tail address of array.
	std::vector<int> vec(std::begin(a), std::end(a));
	//intialize list with array, we can use vector to intialization.
	std::vector<int> lst(vec.begin(), vec.end());
	
	auto it_l = lst.begin();
	while (it_l != lst.end()){
		if (*it_l % 2)
			it_l = lst.erase(it_l);
		else
			it_l++;
	}
	auto it_v = vec.begin();
	while (it_v != vec.end()){
		if (*it_v % 2)
			it_v++;
		else
			it_v = vec.erase(it_v);
	}

	std::cout << "elements of vector: " << std::endl;
	for (auto p : vec)
		std::cout << p << std::endl;
	std::cout << "elements of list: " << std::endl;
	for (auto p : lst)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}