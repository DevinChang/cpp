#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vInt;		//Ԫ������Ϊint��vector����
    int i;					//��¼�û�������ֵ
    char cont = 'y';			//���û������������Ƿ��������
    while (cin >> i)
    {
        vInt.push_back(i);	//��vector���������Ԫ��
        cout << "��Ҫ������y or n���� " << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
        {
            break;
        }
    }
    for (auto mem : vInt)	//ʹ�÷�Χforѭ��������vInt�е�ÿ��Ԫ��
    {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}
