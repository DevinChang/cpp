#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "�������ļ�ʧ�ܣ�" << endl;
        exit(1);
    }

    vector<int> vi;
    int val;
    while (in >> val)
    {
        vi.push_back(val);
    }

    cout << "������Ҫ������������";
    cin >> val;
    cout << "�����а���" << count(vi.begin(), vi.end(), val) << "��" << val;
    return 0;
}
