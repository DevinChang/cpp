#include <iostream>
#include <vector>
#include <string>


//9_43
void replace_str(std::string &s, std::string &oldVal, std::string &newVal){
	auto osz = oldVal.size();
	if (osz == 0)
		return;
	//notice: 一定要注意循环的终止条件。此处的循环若是iter != s.end()，则会抛出out of range异常，这是因为每回循换替换的字符后，
	//向后移动迭代器一个新字符的距离。若是iter != s.end()，则会在std::string tmp(iter, iter + osz) 这一步出错，因为iter != end,但是
	//iter所剩的字符数已经不够，再加上osz就会越界。如：若是上述条件，则跳出循环时，iter=ro, osz=3，所以iter+osz已经越界。
	for (auto iter = s.begin(); iter < s.end() - osz; ){
		std::string tmp(iter, iter + osz);
		if (tmp == oldVal){
			iter = s.erase(iter, iter + osz);
			iter = s.insert(iter, newVal.begin(), newVal.end());
			//Noitce：在string，vector，deque中进行insert操作时，因为insert是插入到迭代器之前，故需移动迭代器插入新字符的大小，使得迭代器
			//指向新插入后的元素上！
			iter += newVal.size();
		}
		else
			iter++;
	}
}

//9_44
void replace_index(std::string &s, std::string &oldVal, std::string &newVal){
	if (!oldVal.size())
		return;
	auto index = 0;
	while (index < s.size() - oldVal.size()){
		std::string tmp(s, index, index + oldVal.size());
		if (oldVal == tmp){
			s.replace(index, index + oldVal.size(), newVal);
			index += newVal.size();
		}
		else
			index++;
	}
}
	

int main16(){
	std::string s("tho, thro");
	std::string oldVal("tho"); //string的初始化用｛｝时，需用迭代器或者下标。
	
	std::string newVal("though");
	//string的迭代器，每次迭代的是每个字母。
	//replace_str(s, oldVal, newVal);
	replace_index(s, oldVal, newVal);
	std::cout << s << std::endl;
	system("pause");
	return 0;
}