#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word, line;
    cout << "��ѡ���ȡ�ַ����ķ�ʽ��1��ʾ��ʶ�ȡ��2��ʾ���ж�ȡ" << endl;
    char ch;
    cin >> ch;
    if (ch == '1')
    {
        cout << "�������ַ�����   Welcome to C++ family!   " << endl;
        cin >> word;
        cout << "ϵͳ��ȡ����Ч�ַ����ǣ�" << endl;
        cout << word << endl;
        return 0;
    }
	//������뻺����
    cin.clear();
    cin.sync();
    if (ch == '2')
    {
        cout << "�������ַ�����   Welcome to C++ family!   " << endl;
        getline(cin, line);
        cout << "ϵͳ��ȡ����Ч�ַ����ǣ�" << endl;
        cout << line << endl;
        return 0;
    }
    cout << "������������";
    return -1;
}
