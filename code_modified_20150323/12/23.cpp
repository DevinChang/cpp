#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
	const char *c1 = "Hello ";
	const char *c2 = "World";

    // �ַ�������ռ�����ַ���+1
	char *r = new char[strlen(c1) + strlen(c2) + 1];
	strcpy(r, c1);    // ������һ���ַ�������
	strcat(r, c2);    // ���ӵڶ����ַ�������
	cout << r << endl;

    string s1 = "hello ";
    string s2 = "world";
    strcpy(r, (s1+s2).c_str()); // �������ӽ��
    cout << r << endl;

    // �ͷŶ�̬����
    delete [] r;
	return 0;
}
