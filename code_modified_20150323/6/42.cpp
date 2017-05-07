#include <iostream>
#include <string>
using namespace std;

//最后一个形参赋予了默认实参
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    cout << "success的单数形式是：" << make_plural(1, "success", "es") << endl;
    cout << "success的复数形式是：" << make_plural(2, "success", "es") << endl;
	//一般情况下调用该函数只需要两个实参
    cout << "failure的单数形式是：" << make_plural(1, "failure") << endl;
    cout << "failure的单数形式是：" << make_plural(2, "failure") << endl;
    return 0;
}
