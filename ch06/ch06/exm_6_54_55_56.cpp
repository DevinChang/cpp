#include <iostream>
#include <vector>

int f(int, int);
typedef decltype(f) *f1;


inline int add(const int a, const int b){
	return a + b;
}

inline int minus(const int a, const int b){
	return a - b;
}

inline int multiply(const int a, const int b){
	return a * b;
}

inline int divide(const int a, const int b){
	return a / b;
}


using pf = int(*) (const int, const int);
std::vector<pf> parr{ add, minus, multiply, divide };


void print(){
	for (auto it = parr.begin(); it != parr.end(); it++){
		std::cout << (*it)(1, 2) << std::endl;
	}
}
