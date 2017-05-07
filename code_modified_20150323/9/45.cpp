#include <iostream>
#include <vector>
#include <string>
using namespace std;

void name_string(string &name, const string &prefix, const string &suffix)
{
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());  // ����ǰ׺
    name.append(" ");
    name.append(suffix.begin(), suffix.end());    // �����׺
}

int main()
{
  	string s="James Bond";
  	name_string(s, "Mr.", "II");
  	cout << s << endl;

    s = "M";
  	name_string(s, "Mrs.", "III");
  	cout << s << endl;

    return 0;
}
