#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[] = "Welcome to ";
    char str2[] = "C++ family!";
    //����strlen�������������ַ����ĳ��ȣ�����ý���ַ����ĳ���
    char result[strlen(str1) + strlen(str2) - 1];

    strcpy(result, str1);   //�ѵ�һ���ַ�������������ַ�����
    strcat(result, str2);   //�ѵڶ����ַ���ƴ�ӵ�����ַ�����

    cout << "��һ���ַ����ǣ�" << str1 << endl;
    cout << "�ڶ����ַ����ǣ�" << str2 << endl;
    cout << "ƴ�Ӻ���ַ����ǣ�" << result << endl;
    return 0;
}
