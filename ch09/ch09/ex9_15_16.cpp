#include <iostream>
#include <vector>
#include <list>
#include <string>

//9_15
bool com_vec(std::vector<int> vec1, std::vector<int> vec2){
	return vec1 == vec2 ? true : false;
}

//9_16 compare vector and list. we could initializaiton new vector with list iterator,then we compare two vector.
bool com_vec_list(std::vector<int>vec, std::list<int> lst){
	std::vector<int> vec2(lst.begin(), lst.end());
	return vec == vec2 ? true : false;
}

int main4(){
	std::vector<int> vec1{ 1, 2, 3, 4, 5 };
	std::vector<int> vec2{ 1, 2, 4, 3 };
	std::list<int> lst{ 1, 2, 3, 4, 5 };
	
	if (com_vec(vec1, vec2))
		std::cout << "Two vector are equal." << std::endl;
	else
		std::cout << "Two vector are not equal!" << std::endl;

	if (com_vec_list(vec1, lst))
		std::cout << "The vector and list are equal." << std::endl;
	else
		std::cout << "The vector and list are not equal!" << std::endl;
	system("pause");
	return 0;
}