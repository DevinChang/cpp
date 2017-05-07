#include "StrVec.h"
using namespace std;

void StrVec::push_back(const string& s)
{
    chk_n_alloc();  // 确保有空间容纳新元素
    alloc.construct(first_free++, s);  // 在first_free指向的元素中构造s的副本
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    // 分配空间保存给定范围中的元素
    // auto data = alloc.allocate(e - b);
    auto data = static_cast<string*>(operator new[]((e - b) * sizeof(string)));
    // 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // 不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
    if (elements)
    {
        // 逆序销毁旧元素
        for (auto p = first_free; p != elements; /* 空 */)
        {
            alloc.destroy(--p);
        }
        // alloc.deallocate(elements, cap - elements);
        operator delete[](elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    // 调用alloc_n_copy分配空间以容纳与s中一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    // 调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    // 我们将分配当前大小两倍的内存空间
    auto newcapacity = size() ? 2 * size() : 1;
    // 分配新内存
    // auto newdata = alloc.allocate(newcapacity);
    auto newdata = static_cast<string*>(operator new[](newcapacity * sizeof(string)));
    // 将数据从旧内存移动到新内存
    auto dest = newdata;  // 指向新数组中下一个空闲位置
    auto elem = elements;  // 指向旧数组中下一个元素
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();  // 一旦我们移动完元素就释放旧内存空间
    // 更新我们的数据结构，执行新元素
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

