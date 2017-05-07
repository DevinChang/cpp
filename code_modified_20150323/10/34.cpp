#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "�÷���execise.exe in_file" << endl;
        return -1;
    }

    ifstream in(argv[1]);
    if (!in)
    {
        cout << "�������ļ�ʧ�ܣ�" << endl;
        exit(1);
    }

    vector<int> vi;
    int v;
    while (in >> v)   // ���ļ��ж�ȡ����
    {
        vi.push_back(v);
    }

    for (auto r_iter = vi.crbegin(); r_iter != vi.crend(); ++r_iter)
    {
        cout << *r_iter << " ";
    }
    cout << endl;
    return 0;
}
