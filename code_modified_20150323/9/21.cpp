#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> svec;     // string��vector
    string word;
    auto iter = svec.begin(); // ��ȡvector��λ�õ�����
    while (cin >> word)   // ��ȡ�ַ�����ֱ�������ļ�������
    {
        iter = svec.insert(iter, word);
    }

    // ��cbegin()��ȡvector��Ԫ�ص�����������vector������Ԫ��
    for (auto iter = svec.cbegin(); iter != svec.cend(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}
