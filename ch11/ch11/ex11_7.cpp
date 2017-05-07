#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>




int main2(){
	std::map<std::string, std::vector<std::string>> famliy;
	std::string surname, name;

	std::cout << "Input The Surname: " << std::endl;
	for (std::cin >> surname; surname != "exit"; std::cin >> surname){
		std::cout << "Input The Name: " << std::endl;
		for (std::cin >> name; name != "exit"; std::cin >> name)
			famliy[surname].push_back(name);
		std::cout << "Input The Surname: " << std::endl;
	}

	for (auto &p : famliy){
		std::cout << "The surname: " << p.first << " " << std::endl;
		for (auto &p1 : p.second)
			std::cout << "The name : " << p1 << " " << std::endl;
	}
	system("pause");
	return 0;
}