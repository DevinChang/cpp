#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>



int main16(){
	std::istream_iterator<int> in_iter(std::cin), eof;
	std::ostream_iterator<int> out_iter(std::cout, " ");
	std::vector<int> vec(in_iter, eof);
	std::sort(vec.begin(), vec.end());
	//10_30
	//std::copy(vec.begin(), vec.end(), out_iter);

	//10_31 use unique_copy to erase same elements.
	std::unique_copy(vec.begin(), vec.end(), out_iter);
	system("pause");
	return 0;
}