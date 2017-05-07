#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

//unique_copy: Copies elements from a source range into a destination range except for the duplicate elements that are adjacent to each other.
int main14(){
	//10_27
	std::vector<int> vec{ 2, 2, 4, 1, 1, 1, 7, 8 };
	std::list<int> lst;
	std::unique_copy(vec.begin(), vec.end(), std::inserter(lst, lst.begin()));

	//10_28
	std::vector<int> iv{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::list<int> lst1, lst2, lst3;
	std::copy(iv.begin(), iv.end(), std::front_inserter(lst1));
	std::copy(iv.begin(), iv.end(), std::back_inserter(lst2));
	std::copy(iv.begin(), iv.end(), std::inserter(lst3, lst3.begin()));
	for (auto &p : lst3)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}