#pragma once
#include <iostream>
#include <string>

template <typename T> void f(T t) {
	std::cout << "f(T) " << std::endl;
}

template <typename T> void f(const T * p) {
	std::cout << "f(const T*)" << std::endl;
}

template <typename T> void g(T t) {
	std::cout << "g(T)" << std::endl;
}

template <typename T> void g(T *p) {
	std::cout << "g(T*)" << std::endl;
}