#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vInt;		//元素类型为int的vector对象
    int i;					//记录用户的输入值
    char cont = 'y';			//与用户交互，决定是否继续输入
    while (cin >> i)
    {
        vInt.push_back(i);	//向vector对象中添加元素
        cout << "您要继续吗（y or n）？ " << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
        {
            break;
        }
    }
    for (auto mem : vInt)	//使用范围for循环语句遍历vInt中的每个元素
    {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}
