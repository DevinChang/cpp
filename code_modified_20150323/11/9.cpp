#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

string &trans(string &s)
{
    for (int p = 0; p < s.size(); p++)
    {
        if (s[p] >= 'A' && s[p] <= 'Z')
        {
            s[p] -= ('A' - 'a');
        }
        else if (s[p] == ',' || s[p] == '.')
        {
            s.erase(p, 1);
        }
    }
    return s;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }

    map<string, list<int>> word_lineno; // 单词到行号的映射
    string line;
    string word;
    int lineno = 0;
    while (getline(in, line))
    {
        lineno++;                   // 行号递增
        istringstream l_in(line);   // 构造字符串流，读取单词
        while (l_in >> word)
        {
            trans(word);
            word_lineno[word].push_back(lineno);  // 添加行号
        }
    }

  	for (const auto &w : word_lineno)
    {
    		cout << w.first << "所在行：";
    		for (const auto &i : w.second)
        {
            cout << i << " ";
        }
        cout << endl;
  	}

    return 0;
}
