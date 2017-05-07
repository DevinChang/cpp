#include <iostream>
#include <vector>
#include <string>
#include <algorithm>




int main10(){
	int i = 3;
	
	//error! 因为这种语句始终是lambda定义，不会执行函数体内的语句。
	
	/*
	while (i)
		//类似于函数的声明。
		auto check = [&i](){ return --i ? true : false; };
	*/

	//fixed: 重复调用才会执行函数体内的语句。
	auto check = [&i](){ return --i ? true : false; };
	while (check())
		std::cout << i << std::endl;
	
	system("pause");
	return 0;
}