#include <iostream>
#include <vector>

//9_22 question:
/*
Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?
		vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
		while (iter != mid)
			if (*iter == some_val)
				iv.insert(iter, 2 * some_val);
*/
//problems: mid will be invalid after the insert.Causes reallocation if the new size is greater than the old capacity. 
//If no reallocation happens, all the iterators and references before the insertion point remain valid.
//test:position of mid.
int main7(){
	std::vector<int> iv = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	iv.insert(iter, -1);
	std::cout << "capacity = " << iv.capacity() << std::endl;
	//error: cause the position of mid is after the iterator.
	std::cout << "iter's pos: " << iter - iv.begin() << std::endl;  
	std::cout << "mid's pos: " << mid - iv.begin() << std::endl;  
	system("pause");
	return 0;
}