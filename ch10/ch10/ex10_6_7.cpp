#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>


int main3(){
	//10_6
	std::vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	std::fill_n(iv.begin(), iv.size(), 0);
	
	//10_7 test
	//a) error! vecor iterator not dereferenceble.
	std::vector<int> vec; 
	std::list<int> lst;
	int i;
	while (std::cin >> i)
		lst.push_back(i);

	//copy(lst.cbegin(), lst.cend(), vec.begin());
	//Fixed : the vec.begin() was replaced by a back_inserter iterator, capable of
    // insert new elements automatically at the end of the container
	copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));
	
	for (auto p : vec)
		std::cout << p << std::endl;

	//b)error! vector iterator + offset out of range!
	std::vector<int> vec2;
	//reserve后，vec2的size仍然是0,相当于在一个空容器上调用了fill_n！P341 exm.

	//vec2.reserve(10);
	//std::fill_n(vec2.begin(), 10, 0);

	//Fixed:1)
	//vec2.resize(10);
	//std::fill_n(vec2.begin(), 10, 0);

	//Fixed:2)
	vec2.reserve(10);
	std::fill_n(std::back_inserter(vec2), 10, 0);

	for (auto p : vec2)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}