#ifndef SP_H
#define SP_H

#include <iostream>
using namespace std;

template <typename T>
class SP
{
public:
    SP() : p(nullptr), use(nullptr) {}
    explicit SP(T* pt) : p(pt), use(new size_t(1)) {}
    SP(const SP &sp):
        p(sp.p), use(sp.use) { if (use) ++*use; }  // 拷贝构造函数
    SP& operator=(const SP&);  // 拷贝赋值运算符
    ~SP();
    T& operator*() { return *p; }       // 解引用
    T& operator*() const { return *p; } // const版

private:
    T *p;
    size_t *use;
};

template <typename T>
SP<T>::~SP()
{
    if (use && --*use == 0)
    {
        // 如果引用计数变为0
        delete p; 		// 释放对象内存
        delete use; 		// 释放计数器内存
    }
}

template <typename T>
SP<T>& SP<T>::operator=(const SP<T> &rhs)
{
    if (rhs.use)
    {
        ++*rhs.use; // 递增右侧运算对象的引用计数
    }
    if (use && --*use == 0)
    {
        // 然后递减本对象的引用计数
        delete p; 		// 如果没有其他用户
        delete use; 		// 释放本对象分配的成员
    }
    p = rhs.p; 		// 拷贝指针
    use = rhs.use;
    return *this; 		// 返回本对象
}

template <typename T, class... Args>
SP<T> make_SP(Args&&... args)
{
    return SP<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
class UP
{
public:
    UP() : p(nullptr) {}
    UP(const UP &) = delete;  // 禁止拷贝构造函数
    explicit UP(T* pt) : p(pt) {}  // 构造函数
    UP& operator=(const UP&) = delete;  // 禁止拷贝赋值运算符
    ~UP();
    T* release();   // 交出控制权
    void reset(T *new_p = nullptr);     // 释放对象
    T& operator*() { return *p; }       // 解引用
    T& operator*() const { return *p; } // const版

private:
    T *p;
};

template <typename T>
UP<T>::~UP()
{
    if (p)        // 如果已经分配了空间
    {
        delete p; 	// 释放对象内存
    }
}

template <typename T>
void UP<T>::reset(T *new_p /*= nullptr*/)
{
    if (p)
    {
        delete p;     // 释放对象内存
    }
    p = new_p;      // 指向新对象
}

template <typename T>
T* UP<T>::release()
{
    T *q = p;
    p = nullptr;  // 清空指针
    return q; 		// 返回对象指针
}

#endif
