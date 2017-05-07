#include <iostream>
#include <vector>
#include <string>


//9_43
void replace_str(std::string &s, std::string &oldVal, std::string &newVal){
	auto osz = oldVal.size();
	if (osz == 0)
		return;
	//notice: һ��Ҫע��ѭ������ֹ�������˴���ѭ������iter != s.end()������׳�out of range�쳣��������Ϊÿ��ѭ���滻���ַ���
	//����ƶ�������һ�����ַ��ľ��롣����iter != s.end()�������std::string tmp(iter, iter + osz) ��һ��������Ϊiter != end,����
	//iter��ʣ���ַ����Ѿ��������ټ���osz�ͻ�Խ�硣�磺��������������������ѭ��ʱ��iter=ro, osz=3������iter+osz�Ѿ�Խ�硣
	for (auto iter = s.begin(); iter < s.end() - osz; ){
		std::string tmp(iter, iter + osz);
		if (tmp == oldVal){
			iter = s.erase(iter, iter + osz);
			iter = s.insert(iter, newVal.begin(), newVal.end());
			//Noitce����string��vector��deque�н���insert����ʱ����Ϊinsert�ǲ��뵽������֮ǰ�������ƶ��������������ַ��Ĵ�С��ʹ�õ�����
			//ָ���²�����Ԫ���ϣ�
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
	std::string oldVal("tho"); //string�ĳ�ʼ���ã���ʱ�����õ����������±ꡣ
	
	std::string newVal("though");
	//string�ĵ�������ÿ�ε�������ÿ����ĸ��
	//replace_str(s, oldVal, newVal);
	replace_index(s, oldVal, newVal);
	std::cout << s << std::endl;
	system("pause");
	return 0;
}