#include <iostream>
#include <vector>
#include <string>




int main15(){
	std::vector<char> iv{ 'a', 'b', 'c', 'd' };
	std::string s(iv.begin(), iv.end());
	std::cout << s << std::endl;
	system("pause");
	return 0;
}