#include <iostream>
#include <vector>

#define NO_FIND -99999

bool vec_find(std::vector<int>::iterator ist1, std::vector<int>::iterator ist2, int key){
	while (ist1 != ist2){
		if ((*ist1) == key)
			return true;
		ist1++;
	}
	return false;
}


//9_5
int vec_find_re(std::vector<int>::iterator ist1, std::vector<int>::iterator ist2, int key){
	while (ist1 != ist2){
		if ((*ist1) == key)
			return key;
		ist1++;
	}
	return NO_FIND;
}

int main1(int argc, char **argv){
	std::vector<int> vec{ 1, 3, 5, 7, 9 };
	int key = 6;
	
	//9_4
	/*
	if (vec_find(vec.begin(), vec.end(), key))
		std::cout << key << " can be find!" << std::endl;
	else
		std::cout << key << " can not be find!" << std::endl;
	*/

	//9_5 test
	if (vec_find_re(vec.begin(), vec.end(), key) == key)
		std::cout << key << " can be find!" << std::endl;
	else
		std::cerr << key << " can not be find!!!" << std::endl;

	system("pause");
	return 0;
}