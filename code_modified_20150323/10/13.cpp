#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline void output_words(vector<string>::iterator beg, vector<string>::iterator end)
{
    for (auto iter = beg; iter != end; iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

bool five_or_more(const string &s1)
{
    return s1.size() >= 5;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }

    vector<string> words;
    string word;
    while (in >> word)
    {
        words.push_back(word);
    }
    output_words(words.begin(), words.end());

    auto iter = partition(words.begin(), words.end(), five_or_more);
    output_words(words.begin(), iter);
    return 0;
}
