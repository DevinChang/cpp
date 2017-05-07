#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include "make_plural.h"
using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words); // ��words���ֵ�������ɾ���ظ�����
    for_each(words.begin(), words.end(),
         [](const string &s) {cout << s << " ";});
    cout << endl;
    // ��ȡһ����������ָ�����һ������size()>= sz��Ԫ��֮��λ��
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    // ��������size >= sz��Ԫ�ص���Ŀ
    auto count = wc - words.begin();
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    // ��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�
    for_each(words.begin(), wc,
         [](const string &s) {cout << s << " ";});
    cout << endl;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "�������ļ�ʧ�ܣ�" << endl;
        exit(1);
    }

    vector<string> words;
    string word;
    while (in >> word)
    {
        words.push_back(word);
    }

    biggies(words, 6);
    return 0;
}
