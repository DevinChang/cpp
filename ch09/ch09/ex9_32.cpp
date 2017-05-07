#include <iostream>
#include <vector>


int main13(){
	std::vector<int> iv = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = iv.begin();
	//std::cout << *iter++ << std::endl;
	while (iter != iv.end()){
		if (*iter % 2){
			iter = iv.insert(iter, *iter++);
			std::advance(iter, 1);
		}
		else
			iter = iv.erase(iter);
	}
	for (auto p : iv)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}