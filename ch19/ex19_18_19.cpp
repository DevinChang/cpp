#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include "ex7_2_11_21.h"


bool check_value(Sales_data &rhs, double t) {
	return rhs.avg_price() > t;
}

std::vector<Sales_data>::iterator find_first_high(std::vector<Sales_data> &vc, double t) {
	auto f = std::bind(check_value, std::placeholders::_1, t);
	return std::find_if(vc.begin(), vc.end(), f);
}

int main() {
	//ex19_18
	std::vector<std::string> vec;
	std::count_if(vec.begin(), vec.end(), std::mem_fn(&std::string::empty));

	system("pause");
	return 0;
}