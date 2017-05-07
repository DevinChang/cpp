#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>



int main2(){
	//10_3
	std::vector<int> iv{ 1, 2, 3, 4, 5, 6 };
	std::cout << std::accumulate(iv.begin(), iv.end(), 0) << std::endl;

	//10_4
	//std::vector<double> v{ 1.1, 2.2, 3.3, 4.4 };
	//std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;
	system("pause");
	return 0;
}