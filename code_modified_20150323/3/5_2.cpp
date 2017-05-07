#include <iostream>
#include <string>
using namespace std;

int main()
{
    char cont = 'y';
    string s, result;
    cout << "请输入第一个字符串：" << endl;
    while (cin >> s)
    {
        if (!result.size())	//第一个拼接的字符串之前不加空格
        {
            result += s;
        }
        else				//之后拼接的每个字符串之前加一个空格
        {
            result = result + " " + s;
        }
        cout << "是否继续（y or n）？" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
        {
            cout << "请输入下一个字符串：" << endl;
        }
        else
        {
            break;
        }
    }
    cout << "拼接后的字符串是：" << result <<endl;
    return 0;
}
