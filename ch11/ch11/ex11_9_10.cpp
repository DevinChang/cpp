#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>



int main4(){
	//ex11_9
	std::map<std::string, std::list<int>> word;

	//ex11_10
	std::map<std::vector<int>::iterator, int> m1;
	std::map<std::list<int>::iterator, int> m2;

	std::vector<int> vec;
	m1.insert(std::pair<std::vector<int>::iterator, int>(vec.begin(), 0));

	std::list<int> lst;
	//error!
	//m2.insert(std::pair<std::list<int>::iterator, int>(lst.begin(), 0));

	system("pause");
	return 0;
}