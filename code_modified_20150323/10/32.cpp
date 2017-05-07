#include <iostream>
#include <algorithm>
#include <iterator>
#include "Sales_item.h"
using namespace ::std;

int main()
{
    vector<Sales_item> vs;
    istream_iterator<Sales_item> in_iter(cin);
    istream_iterator<Sales_item> eof;

    // 读入交易记录，存入vector
    while (in_iter != eof)
    {
        vs.push_back(*in_iter++);
    }

    if (vs.empty())
    {
        //没有输入！警告读者
        std::cerr << "No data?!" << std::endl;
        return -1; // 表示失败
    }

    // 将交易记录按ISBN号排序
    sort(vs.begin(), vs.end(), compareIsbn);

    auto l = vs.begin();
    while (l != vs.end())
    {
        auto item = *l;   // 相同ISBN的交易记录中第一个
        // 在后续记录中查找第一个ISBN与item不同者
        auto r = find_if(l + 1, vs.end(),
                         [item] (const Sales_item &item1) { return item1.isbn() != item.isbn(); } );
        // 将范围[l, r)间的交易记录累加并输出
        cout << accumulate(l + 1, r, item) << endl;
        // l指向下一段交易记录中的第一个
        l = r;
    }

    return 0;
}
