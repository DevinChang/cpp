#include "ex13_44_Str.h"
#include <vector>
#include <algorithm>

int main22() {
	std::vector<Str> vec;
	Str s1("devin"), s2("chang");
	Str s3(s2);
	s3 = s1;
	s3 = Str("warriors");
	vec.push_back(s1);
	vec.push_back(std::move(s2));
	vec.push_back(s3);
	vec.push_back("champion");
	//std::for_each(vec.begin(), vec.end(), [](const Str &s) {std::cout << s << std::endl; });


	system("pause");
	return 0;
}