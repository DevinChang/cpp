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
    // 查找第一个大于等于s长度的数值
    auto p = find_if(vc.begin(), vc.end(), bind(check_size, s, _1));
    // 打印结果
    cout << "第" << p-vc.begin() + 1 << "个数" << *p << "大于等于" << s << "的长度" << endl;
}

int main(int argc, char *argv[])
{
    vector<int> vc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    biggies(vc, "Hello");
    biggies(vc, "everyone");
    biggies(vc, "!");
    return 0;
}
