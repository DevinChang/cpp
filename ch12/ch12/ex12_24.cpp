#include <iostream>
#include <string>
#include <vector>









int main9() {
	std::cout << "input the string length: " << std::endl;
	int len = 0;
	std::cin >> len;
	//加()可以进行值初始化
	char *str = new char[len + 1]();
	std::cout << "input the string: " << std::endl;
	//ignore的作用是跳过n个字符，默认是1。
	std::cin.ignore();
	//cin.get()是保留回车在输入流队列中的.而cin是丢弃回车的.
	std::cin.get(str, len + 1);
	std::cout << str << std::endl;
	delete[]str;

	//text ignore()
	char chararray[10];
	std::cout << "Type 'abcdef': ";
	std::cin.ignore(5, 'c');
	std::cin >> chararray;
	std::cout << chararray;

	system("pause");
	return 0;
}