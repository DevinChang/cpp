#pragma once
#include <iostream>


template <typename T, typename... Args>
void ifoo(const T &t, const Args ...rest) {
	std::cout << t << " Args parameter packet: " << sizeof...(Args) << std::endl;
	std::cout << "rest function parameter packet: " << sizeof...(rest) << std::endl;
}