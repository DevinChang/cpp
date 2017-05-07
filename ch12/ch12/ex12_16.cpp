#include <iostream>
#include <memory>
#include <string>




int main6() {
	std::unique_ptr<std::string> ptr(new std::string("devin"));

	//std::unique_ptr<std::string> p2(ptr); //error!!!
	//std::unique_ptr<std::string> p3 = ptr;  //error!!!
	std::cout << *ptr << std::endl;
	std::unique_ptr<std::string> p4;
	p4.reset(ptr.release());
	std::cout << *p4 << std::endl;
	system("pause");
	return 0;
}