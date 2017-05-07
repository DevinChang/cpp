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

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words); // 将words按字典序排序，删除重复单词
    // 按长度排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(),
          [](const string &a, const string &b) { return a.size() < b.size();});
    // 获取一个迭代器，指向第一个满足size()>= sz的元素
    auto wc = find_if(words.begin(), words.end(),
          [sz](const string &a) { return a.size() >= sz; });
    // 计算满足size >= sz的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc, words.end(),
         [](const string &s) {cout << s << " ";});
    cout << endl;
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

    biggies(words, 4);
    return 0;
}
