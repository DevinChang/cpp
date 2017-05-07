#include <iostream>
#include <vector>
#include <string>
using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    int p = 0;
    while ((p = s.find(oldVal, p)) != string::npos)   // ��s�в���oldVal
    {
        s.replace(p, oldVal.size(), newVal);  // ���ҵ����Ӵ��滻ΪnewVal������
        p += newVal.size();   // �±�������²�������֮��
    }
}

int main()
{
	string s="tho thru tho!";
	replace_string(s, "thru", "through");
	cout << s << endl;

	replace_string(s, "tho", "though");
	cout << s << endl;

	replace_string(s, "through", "");
	cout << s << endl;

    return 0;
}
