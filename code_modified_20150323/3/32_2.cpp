#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int sz = 10;  //����sz��Ϊvector������
    vector<int> vInt, vInt2;
    //ͨ��forѭ��Ϊvector�����Ԫ�ظ�ֵ
    for (int i = 0; i < sz; i++)
    {
        vInt.push_back(i);
    }
    for (int j = 0; j < sz; j++)
    {
        vInt2.push_back(vInt[j]);
    }
    //ͨ����Χforѭ�����vector�����ȫ��Ԫ��
    for (auto val : vInt2)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
