#include <iostream>
//#include <cerrno>
#include <vector>
#include "ex7_2_11_21.h"
//#include "exm_7_23_24_27_32.h"
#include "ex7_43.h"



int main() {
	/*
	//7_1 answer
	Sales_data total;
	if (std::cin >> total.bookNo) {
		Sales_data trans;
		while (std::cin >> trans.bookNo) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				std::cout << total.revenue << std::endl;
				total.revenue = trans.revenue;
			}
		}
		std::cout << total.revenue << std::endl;
	}
	else {
		std::cout << "No data?!" << std::endl;
		return -1;
	}
	*/
	
	/*
	//7_11 cpp 7_41 text
	Sales_data item1;
	print(std::cout, item1) << std::endl;
	Sales_data item2("01-xbb-36");
	print(std::cout, item2) << std::endl;
	Sales_data item3("02-xbc-23", 20, 30);
	print(std::cout, item3) << std::endl;
	Sales_data item4(std::cin);
	print(std::cout, item4) << std::endl;
	*/

	//7_13 
	/*
	Sales_data total(std::cin);
	if (!total.isbn().empty()){
		//notice!!!
		std::istream &is = std::cin;
		while (is){
			Sales_data trans(is);
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else{
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else{
		std::cout << "No data!" << std::endl;
		return -1;
	}
	*/
	
	//7_27 text
	/*
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(std::cout);
	std::cout << std::endl;
	myScreen.display(std::cout);
	std::cout << std::endl;
	*/

	

	//7_28 result (without &):
	/*
	XXXXXXXXXXXXXXXXXXXX#XXXX
	XXXXXXXXXXXXXXXXXXXXXXXXX
	*/
	
	//7_44 result: illegal, cause no default constructor!
	//std::vector<NoDefault> vec(10);
	//7_45 result: if the prama of vector is C, the result no problem! cause the class has default constructor!
	//std::vector<C> vec(10);

	//7_49 text 
	//b) reusult: std::string can not convert to Sales_data &
	//c) Sales_data &combine(const Sales_data &) is legal.Because combine's parameter is const to reference.
	//we can pass a temporary to that paramter. As b)'s parameter is no-const,so it's wrong.
	//std::string s("i can do all things.");
	//Sales_data i;
	//i.combine(s);
	
	system("pause");
	return 0;
}