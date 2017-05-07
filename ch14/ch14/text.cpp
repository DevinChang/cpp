//#include "ex14_7.h"
//#include "ex14_34.h"
//#include "ex14_35.h"
#include "ex14_37.h"
#include <vector>
#include <algorithm>



int main1() {
	//ex14_7
	/*Str s("hello world");
	std::cout << s << std::endl;
	*/

	//ex14_34
	/*ITE obj;
	std::cout << obj(0, 2, 3) << std::endl;*/

	//ex14_35
	//PrintString printer;
	//printer("devin");
	//PrintString errors(std::cerr, '\n');
	//errors("error!");
	
	/*std::vector<std::string> vec;
	while (true) {
		std::string line = printer();
		if (!line.empty())
			vec.push_back(line);
		else
			break;
		
	}*/

	//ex14_37
	std::vector<int> vec{ 2, 5, 1, 9, 3, 10, 7, 4, 3 };
	std::replace_if(vec.begin(), vec.end(), IsEqual(3), 6);
	for (auto &p : vec)
		std::cout << p << " ";
	system("pause");
	return 0;
}