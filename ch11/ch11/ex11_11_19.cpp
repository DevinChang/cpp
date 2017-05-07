#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "exm_7_2._11_21.h"


bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
	return lhs.isbn() < rhs.isbn();
}




int main5(){
	//ex11_11
	//error: use multimap!
	using FF = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
	std::multiset<Sales_data, FF> bookstore(compareIsbn);

	//ex11_19
	std::multiset<Sales_data, FF>::iterator set_it = bookstore.begin();


	system("pause");
	return 0;
}