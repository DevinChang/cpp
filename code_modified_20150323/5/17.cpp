#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int> v3 = {3, 5, 8};
    vector<int> v4 = {3, 5, 0, 9, 2, 7};

    auto it1 = v1.cbegin(); //����v1�ĵ�����
    auto it2 = v2.cbegin(); //����v2�ĵ�����
    auto it3 = v3.cbegin(); //����v3�ĵ�����
    auto it4 = v4.cbegin(); //����v4�ĵ�����
    //�趨ѭ��������v1��v2����δ�����
    while (it1 != v1.cend() && it2 != v2.cend())
    {
        //�����ǰλ�õ�����Ԫ�ز���ȣ���϶�û��ǰ׺��ϵ���˳�ѭ��
        if (*it1 != *it2)
        {
            cout << "v1��v2֮�䲻����ǰ׺��ϵ" << endl;
            break;
        }
        ++it1;  //�������ƶ�����һ��Ԫ��
        ++it2;  //�������ƶ�����һ��Ԫ��
    }
    if (it1 == v1.cend())    //���v1�϶�
    {
        cout << "v1��v2��ǰ׺" << endl;
    }
    if (it2 == v2.cend())    //���v2�϶�
    {
        cout << "v2��v1��ǰ׺" << endl;
    }
    return 0;
}
