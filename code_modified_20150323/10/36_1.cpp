#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    list<int> li = { 0, 1, 2, 0, 3, 4, 5, 0, 6 };
    // ����ͨ���������ҵ�һ��0��λ��
    auto prev = find(li.begin(), li.end(), 0);
    if (prev == li.end())   // δ�ҵ�
    {
        cout << "������û��0" << endl;
    }
    else
    {
        auto curr = prev;
        // ����Ѱ�Һ���0��ֱ������β��λ��
        while (curr != li.end())
        {
            // ��ס��һ��0��λ��
            prev = curr;
            curr++;
            // Ѱ����һ��0
            curr = find(curr, li.end(), 0);
        }
        // ������ͷ��ʼ����prev��λ�ñ��
        int p = 1;
        for (auto iter = li.begin(); iter != prev; iter++, p++)
        {
        }

        cout << "���һ��0�ڵ�" << p << "��λ��" << endl;
    }

    return 0;
}
