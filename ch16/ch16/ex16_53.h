#pragma once
#include <iostream>
#include <string>



template <typename T>
std::ostream &print(std::ostream &os, const T &t) {
	return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, Args... rest) {
	os << t << ", ";
	return print(os, rest...);
}