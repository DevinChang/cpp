#include <iostream>
#include <forward_list>


int main10(){
	std::forward_list<int> fst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto pre = fst.before_begin();
	auto cur = fst.begin();
	while (cur != fst.end()){
		if (*cur % 2)
			cur = fst.erase_after(pre); //modify: forget to update the cur pointer.
		else{
			pre = cur;
			cur++;
		}
	}
	for (auto p : fst)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}