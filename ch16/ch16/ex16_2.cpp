#include <iostream>
#include "exm_7_2._11_21.h"





template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}


int main1() {
	std::cout << compare(1, 0) << std::endl;
	std::cout << compare(1.1, 2.1) << std::endl;
	std::cout << "ex16_3: " << std::endl;
	//error!
	//std::cout << compare(Sales_data("01-234", 5, 1.1), Sales_data("02-212", 4, 2.1));
	system("pause");
	return 0;
}