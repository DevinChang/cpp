#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

inline void output_words(list<string> &words)
{
    for (auto iter = words.begin(); iter != words.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void elimDups(list<string> &words)
{
    output_words(words);

    words.sort();
    output_words(words);

    words.unique();
    output_words(words);
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }

    list<string> words;
    string word;
    while (in >> word)
    {
        words.push_back(word);
    }

    elimDups(words);
    return 0;
}
