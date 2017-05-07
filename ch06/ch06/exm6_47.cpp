#include <iostream>
#include <cassert>
#include <vector>

void foo(std::vector<int> arr){
#ifndef NDEBUG
	std::cout << arr.size() << std::endl;
#endif
	while (!arr.empty()){
		auto it = arr.back();
		arr.pop_back();
		foo(arr);
		std::cout << it << std::endl;
	}
	
}