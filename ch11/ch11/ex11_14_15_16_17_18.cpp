#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

//ex11_15
//std::map<int, std::vector<int>> m1;
//mapped_type: std::vector<int>; 
//key_type: int;
//value_type: std::pair<int, std::vector<int>>



int main7(){
	//ex11_14
	std::map<std::string, std::vector<std::pair<std::string, int>>> famliy;

	//ex11_16
	std::map<std::string, int> m1 = { { "a", 18 } };
	std::map<std::string, int>::iterator it = m1.begin();
	it->second = 6;

	//ex11_17
	std::cout << "ex11_17: " << std::endl;
	std::vector<std::string> v;
	std::multiset<std::string> c{ "a", "bb", "a", "c", "e", "d" };
	//1) std::copy(v.begin(), v.end(), std::inserter(c, c.end()));  //OK!
	//2) std::copy(v.begin(), v.end(), std::back_inserter(c));   //ERROR!! Cause no 'push_back' in set.
	//3) std::copy(c.begin(), c.end(), std::inserter(v, v.end())); //OK!
	//4) std::copy(c.begin(), c.end(), std::back_inserter(v));   //OK!
	std::copy(c.begin(), c.end(), std::inserter(v, v.end()));

	for (auto &p : v)
		std::cout << p << std::endl;

	//ex11_18
	std::map<std::string, size_t> word_count;
	std::map<std::string, size_t>::const_iterator map_it = word_count.cbegin();
	
	system("pause");
	return 0;
}