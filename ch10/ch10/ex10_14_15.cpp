#include <iostream>
#include <algorithm>



int main7(){
	//10_14
	auto f = [](int a, int b){ return a + b; };

	//10_15
	int i = 1;
	auto f1 = [i](int b){ return b + i; };
	std::cout << f1(2) << std::endl;
	system("pause");
	return 0;
}