#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family)
{
    families[family];
}

void add_child(map<string, vector<pair<string, string>>> &families,
               const string &family, const string &child, const string &birthday)
{
    families[family].push_back({child, birthday});
}

int main(int argc, char *argv[])
{
    map<string, vector<pair<string, string>>> families;

    add_family(families, "��");
    add_child(families, "��", "ǿ", "1970-1-1");
    add_child(families, "��", "��", "1980-1-1");
    add_child(families, "��", "��", "1990-1-1");
    add_family(families, "��");

    for (auto f : families)
    {
        cout << f.first << "�ҵĺ��ӣ�";
        for (auto c : f.second)
        {
            cout << c.first << "(����" << c.second << "), ";
        }
        cout << endl;
    }

    return 0;
}
