#include <iostream>
#include <deque>
#include <list>
#include <string>


int main5(){
	std::string str;
	std::deque<std::string> dq;
	std::list<std::string> lst;
	while (std::cin >> str){
		//9_18
		dq.push_back(str);
		//9_19
		lst.push_back(str);
	}
	for (std::deque<std::string>::iterator it = dq.begin(); it != dq.end(); it++){
		std::cout << *it << std::endl;
	}
	system("pause");
	return 0;
}