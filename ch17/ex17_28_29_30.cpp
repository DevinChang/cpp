#include <iostream>
#include <random>

unsigned int rand_int() {
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u(0, 9);
	return u(e);
}


int main7() {
	std::cout << "ex17_28: " << std::endl;
	std::default_random_engine e;
	for (size_t i = 0; i < 10; ++i)
		std::cout << e() << " ";

	//std::uniform_int_distribution<unsigned> u(0, 9);
	for (size_t i = 0; i < 10; ++i)
		std::cout << rand_int() << std::endl;

	std::cout << "ex17_29: " << std::endl;
	std::default_random_engine el(123123);
	//std::cout << el << std::endl;

	system("pause");
	return 0;
}