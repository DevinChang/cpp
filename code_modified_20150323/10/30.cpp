#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    // �������������ӱ�׼�����������
    istream_iterator<int> in_iter(cin);
    // β�������
    istream_iterator<int> eof;
    vector<int> vi;
    while (in_iter != eof)
    {
        vi.push_back(*in_iter++);  // ����vector������������
    }

    sort(vi.begin(), vi.end());

    ostream_iterator<int> out_iter(cout, " ");
    copy(vi.begin(), vi.end(), out_iter);
    return 0;
}
