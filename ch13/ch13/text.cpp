#include "ex13_30.h"
#include <vector>
#include <algorithm>


size_t len(char *c) {
	return std::strlen(c);
}

int main12() {
	/*std::vector<HasPtr2> vec;
	
	HasPtr2 hp1("devin");
	HasPtr2 hp2("chang");
	HasPtr2 hp3(hp1);
	vec.emplace_back(hp1);
	vec.emplace_back(hp2);
	
	std::sort(vec.begin(), vec.end());*/

	char *str = "devinchang";
	std::cout << len(str) << std::endl;

	system("pause");
	return 0;
}