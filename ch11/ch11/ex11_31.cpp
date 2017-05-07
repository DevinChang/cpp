#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>


int main10(){
	std::multimap<std::string, std::string> authors_book{ { "You", "IO" },{ "Bill", "Cil" }, { "Dio", "MLi" }, { "Pre", "ZOI" }, { "Bill", "War" } };
	std::string author("Bill");
	
	
	auto ret = authors_book.count(author);
	auto iter = authors_book.find(author);
	while (ret){
		if (iter->first == author){
			authors_book.erase(author);
			break;
		}
		++iter;
		--ret;
	}
	
	for (auto &p : authors_book)
		std::cout << p.first << "'s book: " << p.second << std::endl;
	
	system("pause");
	return 0;
}