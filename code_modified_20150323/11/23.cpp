#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void add_child(multimap<string, string> &families, const string &family, const string &child)
{
    families.insert({family, child});
}

int main(int argc, char *argv[])
{
    multimap<string, string> families;

    add_child(families, "��", "ǿ");
    add_child(families, "��", "��");
    add_child(families, "��", "��");

    for (auto f : families)
    {
        cout << f.first << "�ҵĺ��ӣ�" << f.second << endl;
    }
    return 0;
}
