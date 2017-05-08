#include "ex16_4.h"
#include <vector>
#include <list>
#include <string>
#include "ex16_5.h"
#include "ex16_12.h"
#include "ex16_14.h"



int main() {
	std::cout << "ex16_4: " << std::endl;
	std::vector<int> vec{ 0, 2, 1, 8, 3, 6, 9, 2 };
	std::list<int> lst{ 1, 8, 6, 2, 3, 2, 6 };
	std::list<std::string> ls{ "hello", "world", "devin" };
	int value = 6;
	auto it = ifind(vec.begin(), vec.end(), value);
	if (it == vec.end())
		std::cout << "can not find " << value << std::endl;
	else
		std::cout << "find " << value << " successful." << std::endl;

	std::cout << "ex16_5: " << std::endl;
	int arr[5] = { 1, 2, 3, 4, 5 };
	char s[4] = { 'd', 'e', 'v' };
	iprint(arr);
	iprint(s);

	std::cout << "ex16_12: " << std::endl;
	Blob<std::string> b;
	std::cout << b.size() << std::endl;

	std::cout << "ex16_14_15: " << std::endl;
	Screen<5, 3> iscreen;
	iscreen.display(std::cout);
	iscreen.move(4, 0).set('*').display(std::cout);
	std::cout << iscreen;
	std::cin >> iscreen;
	std::cout << std::endl;
	std::cout << iscreen;
	system("pause");
	return 0;
}