#include <iostream>
#include <vector>
#include <list>
#include <string>

int main3(){
	std::list<const char *> lst = { "ab", "ca", "edg", "qwqr" };
	std::vector<std::string> vec(10);
	vec.assign(lst.cbegin(), lst.cend());
	for (auto p : vec)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}