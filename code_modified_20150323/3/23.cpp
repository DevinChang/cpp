#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    vector<int> vInt;
    srand((unsigned) time(NULL));    //�������������
    for (int i = 0; i < 10; i++)     	//ѭ��10��
    {
        //ÿ��ѭ������һ��1000���ڵ����������ӵ�vInt��
        vInt.push_back(rand() % 1000);
    }
    cout << "������ɵ�10�������ǣ�" << endl;
    //���ó�����������ȡԭʼ����
    for (auto it = vInt.cbegin(); it != vInt.cend(); it++)
    {
        cout << *it << " ";        //�����ǰ����
    }
    cout << endl;
    cout << "�������10�������ǣ�" << endl;
    //���÷ǳ����������޸�vInt���ݲ����
    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        *it *= 2;
        cout << *it << " ";        //�����ǰ����
    }
    cout << endl;

    return 0;
}
