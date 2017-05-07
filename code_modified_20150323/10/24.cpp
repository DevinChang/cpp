#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include "make_plural.h"
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

void biggies(vector<int> &vc, const string &s)
{
    // ���ҵ�һ�����ڵ���s���ȵ���ֵ
    auto p = find_if(vc.begin(), vc.end(), bind(check_size, s, _1));
    // ��ӡ���
    cout << "��" << p-vc.begin() + 1 << "����" << *p << "���ڵ���" << s << "�ĳ���" << endl;
}

int main(int argc, char *argv[])
{
    vector<int> vc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    biggies(vc, "Hello");
    biggies(vc, "everyone");
    biggies(vc, "!");
    return 0;
}
