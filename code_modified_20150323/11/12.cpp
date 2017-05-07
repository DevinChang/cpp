#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }

    vector<pair<string, int>> data; // pair的vector
    string s;
    int v;
    while (in >> s && in >> v)  // 读取一个字符串和一个整数
    {
        data.push_back({s, v});
    }

  	for (const auto &d : data)  // 打印单词行号
    {
  	   	cout << d.first << " " << d.second << endl;
    }

    return 0;
}
