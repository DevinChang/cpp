#include "ex13_44.h"
#include <vector>
#include <algorithm>


int main() {
	std::vector<String> vec;
	String s1("devin"), s2("chang");
	String s3(s2);
	s3 = s1;
	s3 = String("warriors");
	vec.push_back(s1);
	vec.push_back(std::move(s2));
	vec.push_back(s3);
	vec.push_back("champion");


	//char *c = "devin";
	//std::cout << c << " " << c + 5 << std::endl;
	//char *s = const_cast<char *>(c);
	//int n = 0;
	//while (*s){
	//	++s;
	//	++n;
	//}
	//std::cout << s - c << std::endl;
	


	system("pause");
	return 0;
}

	