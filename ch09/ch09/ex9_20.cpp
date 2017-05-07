#include <iostream>
#include <list>
#include <deque>
#include <string>


int main6(){
	std::deque<int> dq1;
	std::deque<int> dq2;
	std::list<int> lst{ 1, 3, 2, 5, 6, 4, 7, 9, 12 };
	for (auto p : lst){
		if (p % 2 == 0)
			dq1.push_back(p);
		else
			dq2.push_back(p);
	}
	std::cout << "even seque: " << std::endl;
	for (auto p1 : dq1)
		std::cout << p1 << std::endl;
	std::cout << "odd seque: " << std::endl;
	for (auto p2 : dq2)
		std::cout << p2 << std::endl;
	system("pause");
	return 0;
}