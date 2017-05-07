#include <iostream>
#include <string>

//9_45
std::string &getname(std::string &name, std::string &pre, std::string &tail){
	std::string::iterator it = name.begin();
	name.insert(it, pre.begin(), pre.end());
	
	name.append(tail);
	return name;
}

//9_46
std::string &spellname(std::string &name, std::string &pre, std::string &tail){
	
	name.insert(0, pre);
	name.insert(name.size(), tail);
	return name;
}

int main17(){
	std::string name("Lee"), prename("Devin"), tailname("Chang");
	std::cout << spellname(name, prename, tailname) << std::endl;
	system("pause");
	return 0;
}