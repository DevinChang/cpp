#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main(int argc, char **argv)
{
    allocator<string> alloc;
    // 分配100个未初始化的string
    auto const p = alloc.allocate(100);
    string s;
    string *q = p; 					// q指向第一个string
    while (cin >> s && q != p + 100)
    {
        alloc.construct(q++, s); 		// 用s初始化*q
    }
    const size_t size = q - p; 		// 记住读取了多少个string

    // 使用数组
    for (size_t i = 0; i < size; i++)
    {
        cout << p[i] << " " << endl;
    }

    while (q != p)        // 使用完毕后释放已构造的string
    {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, 100); // 释放内存
    return 0;
}
