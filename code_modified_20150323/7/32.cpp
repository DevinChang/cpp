#include <iostream>
#include <string>
using namespace std;

class Window_mgr
{
public:
    void clear();
};

class Screen
{
friend void Window_mgr::clear();
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
public:
	Screen() = default;	//默认构造函数
	Screen(unsigned ht, unsigned wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) { }
};

void Window_mgr::clear()
{
    Screen myScreen(10, 20, 'X');
    cout << "清理之前myScreen的内容是：" << endl;
    cout << myScreen.contents << endl;
    myScreen.contents = "";
    cout << "清理之后myScreen的内容是：" << endl;
    cout << myScreen.contents << endl;
}

int main()
{
    Window_mgr w;
    w.clear();
    return 0;
}
