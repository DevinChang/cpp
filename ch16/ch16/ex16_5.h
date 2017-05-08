#pragma once
#include <iostream>



template <typename T, size_t n>
void iprint(const T (&arr)[n]) {
	for (auto elem : arr)
		std::cout << elem << std::endl;
}