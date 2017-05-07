#include <iostream>
#include <vector>

int main14(){
	std::vector<int> iv = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = iv.begin();
	while (iter != iv.end()){
		//9_34 result: infinite loop.
		if (*iter % 2)
			//++iter;
			//iv.insert(iter, 42); // error!
			iter = iv.insert(iter, 42);
		++iter;
	}
	for (auto p : iv)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}