#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "用法：execise.exe in_file out_file1 out_file2" << endl;
        return -1;
    }

    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }

    ofstream out1(argv[2]);
    if (!out1)
    {
        cout << "打开输出文件1失败！" << endl;
        exit(1);
    }

    ofstream out2(argv[3]);
    if (!out2)
    {
        cout << "打开输出文件2失败！" << endl;
        exit(1);
    }

    // 创建流迭代器从文件读入整数
    istream_iterator<int> in_iter(in);
    // 尾后迭代器
    istream_iterator<int> eof;
    // 第一个输出文件以空格间隔整数
    ostream_iterator<int> out_iter1(out1, " ");
    // 第二个输出文件以换行间隔整数
    ostream_iterator<int> out_iter2(out2, "\n");
    while (in_iter != eof)
    {
        if (*in_iter & 1) // 奇数写入第一个输出文件
        {
            *out_iter1++ = *in_iter;
        }
        else
        {
            *out_iter2++ = *in_iter; // 偶数写入第二个输出文件
        }
        in_iter++;
    }

    return 0;
}
