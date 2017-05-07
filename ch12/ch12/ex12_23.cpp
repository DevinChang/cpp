
#include <iostream>
#include <string>
#include <vector>



int main8() {

	/*std::string s1("Devin"), s2("Chang"), s3(s1 + s2);
	
	char *str = new char[9];
	int i = 0;
	for (char *q = str; q != str + 9; q++) {
		*str = s3[i++];
		std::cout << *str;
	}
	delete[]str;*/
		
	char *connect_char = new char[strlen("hello world.")]();
	strcat(connect_char, "hello");
	strcat(connect_char, "world.");
	std::cout << connect_char << std::endl;
	delete[]connect_char;
	
	
	system("pause");
	return 0;
}