#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "�������ļ�ʧ�ܣ�" << endl;
        exit(1);
    }

    vector<pair<string, int>> data; // pair��vector
    string s;
    int v;
    while (in >> s && in >> v)  // ��ȡһ���ַ�����һ������
    {
        data.push_back({s, v});
    }

  	for (const auto &d : data)  // ��ӡ�����к�
    {
  	   	cout << d.first << " " << d.second << endl;
    }

    return 0;
}
