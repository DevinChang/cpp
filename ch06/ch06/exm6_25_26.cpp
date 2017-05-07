#include <iostream>
#include <string>





int main1(int argc, char **argv){
	std::string str;
	for (int i = 1; i < argc; i++){
		str += argv[i];
	}
	std::cout << str << std::endl;

	//debug: string and char
	std::string t_str;
	char a[] =  "i can do all things" ;
	for (int i = 0; i < strlen(a); i++){
		t_str += a[i];
	}
	std::cout << t_str << std::endl;
	system("pause");
	return 0;
}