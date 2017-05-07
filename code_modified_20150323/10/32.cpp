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

    // ���뽻�׼�¼������vector
    while (in_iter != eof)
    {
        vs.push_back(*in_iter++);
    }

    if (vs.empty())
    {
        //û�����룡�������
        std::cerr << "No data?!" << std::endl;
        return -1; // ��ʾʧ��
    }

    // �����׼�¼��ISBN������
    sort(vs.begin(), vs.end(), compareIsbn);

    auto l = vs.begin();
    while (l != vs.end())
    {
        auto item = *l;   // ��ͬISBN�Ľ��׼�¼�е�һ��
        // �ں�����¼�в��ҵ�һ��ISBN��item��ͬ��
        auto r = find_if(l + 1, vs.end(),
                         [item] (const Sales_item &item1) { return item1.isbn() != item.isbn(); } );
        // ����Χ[l, r)��Ľ��׼�¼�ۼӲ����
        cout << accumulate(l + 1, r, item) << endl;
        // lָ����һ�ν��׼�¼�еĵ�һ��
        l = r;
    }

    return 0;
}
