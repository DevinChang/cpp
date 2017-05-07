#include <iostream>
#include <initializer_list>


int sum(std::initializer_list<int> s){
	int rt = 0;
	for (const auto &elem : s)
		rt += elem;
	return rt;
}


int main(){
	std::cout << sum({ 1, 2, 3, 4,5 }) << std::endl;
	system("pause");
	return 0;
}

