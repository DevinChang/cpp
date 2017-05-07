#include <iostream>
#include <string>
#include <forward_list>


void insert_fst(std::forward_list<std::string> &fst, std::string key, std::string str){
	auto pre = fst.before_begin();
	auto cur = fst.begin();
	while (cur != fst.end()){
		if (*cur == key){
			fst.insert_after(cur, str);
			return;
		}
		else{
			pre = cur;
			cur++;
		}
	}
	//error: fst.insert_after(cur, str); Because cur points to the last element of the container's tail element,this is undefined.	
	fst.insert_after(pre, str);
	return;
}

int main11(){
	std::forward_list<std::string> fst = { "i", "can", "all", "things"};
	std::string key = "t", str = "do";
	insert_fst(fst, key, str);
	for (auto p : fst)
		std::cout << p << " ";
	std::cout << std::endl;
	system("pause");
	return 0;
}