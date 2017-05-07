#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "make_plural.h"
using namespace std;

inline void output_words(vector<string> &words)
{
    for (auto iter = words.begin(); iter != words.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    output_words(words);
    // 统计满足size()>= sz的元素的个数
    auto bc = count_if(words.begin(), words.end(),
        [sz](const string &a) { return a.size() >= sz; });
    cout << bc << " " << make_plural(bc, "word", "s") << " of length " << sz << " or longer" << endl;
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

    biggies(words, 6);
    return 0;
}
