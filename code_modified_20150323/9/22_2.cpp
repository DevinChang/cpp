#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> iv = {1, 1, 1, 1, 1};  // int��vector
    int some_val = 1;

    vector<int>::iterator iter = iv.begin();
    int org_size = iv.size(), i = 0;  // ԭ��С

    // ��ѭ����������ѭ������
    while (i <= org_size / 2)
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val);  // iterָ����Ԫ��
            iter++; iter++;  // ��iter�ƽ�����Ԫ�ص���һ��λ��
        }
        else
        {
            iter++;  // ���ƽ�iter
        }

        i++;
    }

    // ��begin()��ȡvector��Ԫ�ص�����������vector������Ԫ��
    for (iter = iv.begin(); iter != iv.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}
