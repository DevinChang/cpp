#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vString;		//Ԫ������Ϊstring��vector����
    string s;					//��¼�û�������ֵ
    char cont = 'y';			//���û������������Ƿ��������
    while (cin >> s)
    {
        vString.push_back(s);	//��vector���������Ԫ��
        cout << "��Ҫ������y or n���� " << endl;
        cin >> cont;
        if(cont != 'y' && cont != 'Y')
        {
            break;
        }
    }
    for (auto mem : vString)	//ʹ�÷�Χforѭ��������vString�е�ÿ��Ԫ��
    {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}
