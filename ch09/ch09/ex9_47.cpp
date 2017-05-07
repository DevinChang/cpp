#include <iostream>
#include <string>

//find_first_of
void find_num_cha(const std::string &s, const std::string &com){
	std::string::size_type pos = 0;


	while ((pos = s.find_first_of(com, pos)) != std::string::npos){
		std::cout << pos << " num: " << s[pos] << std::endl;
		++pos;
	}
}

void find_dig_let(const std::string &str, const std::string &com){
	std::string::size_type pos = 0;
	while ((pos = str.find_first_not_of(com, pos)) != std::string::npos){
		std::cout << pos << " num: " << str[pos] << std::endl;
		++pos;
	}
}

int main18(){
	std::string str("a21jlfQ4l4llm345");
	std::string digit("0123456789");
	std::string letter("abcdefghijklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ");
	//find_num_cha(str, letter);
	//find_dig_let(str, digit);
	//9_48 test
	std::string numbers("0123456789");
	std::string name("r2d2");
	std::cout << name.find(numbers);
	system("pause");
	return 0;
}