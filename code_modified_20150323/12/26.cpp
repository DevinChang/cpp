#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main(int argc, char **argv)
{
    allocator<string> alloc;
    // ����100��δ��ʼ����string
    auto const p = alloc.allocate(100);
    string s;
    string *q = p; 					// qָ���һ��string
    while (cin >> s && q != p + 100)
    {
        alloc.construct(q++, s); 		// ��s��ʼ��*q
    }
    const size_t size = q - p; 		// ��ס��ȡ�˶��ٸ�string

    // ʹ������
    for (size_t i = 0; i < size; i++)
    {
        cout << p[i] << " " << endl;
    }

    while (q != p)        // ʹ����Ϻ��ͷ��ѹ����string
    {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, 100); // �ͷ��ڴ�
    return 0;
}
