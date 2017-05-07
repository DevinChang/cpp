#include <iostream>
#include <string>
using namespace std;

string::size_type find_char(const string &s, char c, string::size_type &occurs){
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i){
		if (s[i] == c){
			if (ret == s.size()){
				ret = i;
			}
			++occurs;
		}
	}
	return ret;
}


bool p_isupper(const string & s){
	for (auto c : s){
		if (isupper(c))
			return true;
	}
	return false;
}

void p_toupper(string &s){
	for (auto &c : s)
		c = toupper(c);
}

int main(){
	/*string s = "i am a CS master";
	string::size_type ctr;
	auto index = find_char(s, 'a', ctr);
	cout << "'a' in " << index << endl;
	cout << "'a' total is " << ctr << endl;
	*/
	string s1("abcd");
	string s2 = "abc";
	bool is_upper = p_isupper(s1);
	if (is_upper)
		cout << "This string is upper!" << endl;
	else
		cout << "This string is not upper!" << endl;
	cout << "the string is " << s2;
	p_toupper(s2);
	cout << ", the alter string is " << s2 << endl;
	system("pause");
	return 0;
}