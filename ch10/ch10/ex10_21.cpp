#include <iostream>
#include <vector>
#include <string>
#include <algorithm>




int main10(){
	int i = 3;
	
	//error! ��Ϊ�������ʼ����lambda���壬����ִ�к������ڵ���䡣
	
	/*
	while (i)
		//�����ں�����������
		auto check = [&i](){ return --i ? true : false; };
	*/

	//fixed: �ظ����òŻ�ִ�к������ڵ���䡣
	auto check = [&i](){ return --i ? true : false; };
	while (check())
		std::cout << i << std::endl;
	
	system("pause");
	return 0;
}