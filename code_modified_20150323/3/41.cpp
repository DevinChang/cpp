#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    const int sz = 10;  //����sz��Ϊ�����ά��
    int a[sz];
    srand((unsigned) time(NULL)); //�������������
    cout << "����������ǣ�" << endl;
    //���÷�Χforѭ�����������ÿ��Ԫ��
    for (auto &val : a)
    {
        val = rand() % 100;   //����һ��100���ڵ������
        cout << val << " ";
    }
    cout << endl;

    //����begin��end��ʼ��vector����
    vector<int> vInt(begin(a), end(a));
    cout << "vector�������ǣ�" << endl;
    //���÷�Χforѭ������vector��ÿ��Ԫ��
    for (auto val : vInt)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
