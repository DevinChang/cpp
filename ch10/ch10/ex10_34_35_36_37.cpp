#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>



int main(){
	//10_34
	std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto it = vec.crbegin(); it != vec.crend(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << "ex10_35: " << std::endl;
	//10_35
	auto it = vec.cend();
	for (--it; ; --it){
		std::cout << *it << std::endl;
		if (it == vec.cbegin())
			break;
	}

	//10_36
	std::cout << "ex10_36: " << std::endl;
	std::list<int> lst{ 0, 1, 3, 2, 6, 3, 0, 9, 8, 2 };
	auto ret = std::find(lst.crbegin(), lst.crend(), 0);
	
	//10_37
	std::cout << "ex10_37: " << std::endl;
	std::list<int> lst2(5);
	//0 1 2 3 4 5 6 7 8 9
	//      ^         ^
	//   cbegin      cend
	//0 1 2 3 4 5 6 7 8 9
	//    ^         ^
	//   crend     crbegin
	std::copy(vec.cbegin() + 3, vec.cbegin() + 8, lst2.rbegin());
	for (auto p : lst2)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}