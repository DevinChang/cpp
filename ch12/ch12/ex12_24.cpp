#include <iostream>
#include <string>
#include <vector>









int main9() {
	std::cout << "input the string length: " << std::endl;
	int len = 0;
	std::cin >> len;
	//��()���Խ���ֵ��ʼ��
	char *str = new char[len + 1]();
	std::cout << "input the string: " << std::endl;
	//ignore������������n���ַ���Ĭ����1��
	std::cin.ignore();
	//cin.get()�Ǳ����س��������������е�.��cin�Ƕ����س���.
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