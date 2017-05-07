#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vString;		//元素类型为string的vector对象
    string s;					//记录用户的输入值
    char cont = 'y';			//与用户交互，决定是否继续输入
    while (cin >> s)
    {
        vString.push_back(s);	//向vector对象中添加元素
        cout << "您要继续吗（y or n）？ " << endl;
        cin >> cont;
        if(cont != 'y' && cont != 'Y')
        {
            break;
        }
    }
    for (auto mem : vString)	//使用范围for循环语句遍历vString中的每个元素
    {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}
