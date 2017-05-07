#include "exm_7_2._11_21.h"
#include <vector>
#include <algorithm>


bool compareIsbn(Sales_data &item1, Sales_data &item2){
	return item1.isbn() < item2.isbn();
}




int main5(){
	std::vector<Sales_data> vec{ Sales_data("01-xcv-cc"), Sales_data("03-cvz-i2"), Sales_data("01-cmd-ba"), Sales_data("06-acc-i2") };
	
	//10_12
	//std::sort(vec.begin(), vec.end(), compareIsbn);

	//10_17 use lambda expression.
	std::sort(vec.begin(), vec.end(), [](Sales_data &item1, Sales_data &item2){ return item1.isbn() < item2.isbn(); });
	
	for (auto &p : vec)
		std::cout << p.isbn() << std::endl;
	


	system("pause");
	return 0;
}