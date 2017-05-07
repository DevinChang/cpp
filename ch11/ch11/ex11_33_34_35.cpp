#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

std::map<std::string, std::string> buildMap(std::ifstream &map_file){
	std::map<std::string, std::string> trans_map;
	std::string key;
	std::string value;

	while (map_file >> key && std::getline(map_file, value)){
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
			//ex11_35: insert�������ص���һ��pair���ͣ���һ����const iterator��ָ��ؼ��֣��ڶ�����bool���ͣ���ʾ�ؼ����Ƿ���ڡ�
			//���ؼ����Ѵ��ڣ���boolΪfalse��ʲôҲ������������key-value.
			//�±���������۹ؼ��ִ治���ڶ������mapһ��key-value�����ԣ����ж���ؼ��ִ���ʱ��������map�е���Զ�����һ����
			//exmaple: �ı��У���������ͬ�Ĺؼ��֣�����ͬԪ�صļ�ֵ�ԡ�k okay?��k ok?
			//��ʹ��[]ʱ������k��Ӧ����ok��ʹ��insertʱ��k��Ӧ�Ļ���okay?
			//trans_map.insert({ key, value.substr(1) });
		else
			throw std::runtime_error("no rule for " + key);
	}
	return trans_map;
}

const std::string &transform(const std::string &s, const std::map<std::string, std::string> &m){
	auto map_it = m.find(s);
	//ex11_34 �˴�����ʹ���±��������Ϊֻ�ܶԷ�const��mapʹ���±ꡣ
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}

void word_transform(std::ifstream &map_file, std::ifstream &input){
	auto trans_map = buildMap(map_file);
	std::string text;
	while (std::getline(input, text)){
		std::istringstream stream(text);
		std::string word;
		bool ispace = true;
		while (stream >> word){
			if (ispace)
				ispace = false;
			else
				std::cout << " ";
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

int main(){
	std::ifstream trans("trans.txt"), text("word.txt");
	word_transform(trans, text);

	system("pause");
	return 0;
}