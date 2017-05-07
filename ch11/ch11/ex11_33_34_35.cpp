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
			//ex11_35: insert操作返回的是一个pair类型，第一个是const iterator，指向关键字，第二个是bool类型，表示关键字是否存在。
			//若关键字已存在，则bool为false，什么也不错。否则插入该key-value.
			//下标操作，不论关键字存不存在都会插入map一个key-value。所以，当有多个关键字存在时，保存在map中的永远是最后一个。
			//exmaple: 文本中，有两个相同的关键字，但不同元素的键值对。k okay?和k ok?
			//当使用[]时，最后的k对应的是ok？使用insert时，k对应的还是okay?
			//trans_map.insert({ key, value.substr(1) });
		else
			throw std::runtime_error("no rule for " + key);
	}
	return trans_map;
}

const std::string &transform(const std::string &s, const std::map<std::string, std::string> &m){
	auto map_it = m.find(s);
	//ex11_34 此处不能使用下标操作，因为只能对非const的map使用下标。
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