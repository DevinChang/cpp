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
        p(sp.p), use(sp.use) { if (use) ++*use; }  // �������캯��
    SP& operator=(const SP&);  // ������ֵ�����
    ~SP();
    T& operator*() { return *p; }       // ������
    T& operator*() const { return *p; } // const��

private:
    T *p;
    size_t *use;
};

template <typename T>
SP<T>::~SP()
{
    if (use && --*use == 0)
    {
        // ������ü�����Ϊ0
        delete p; 		// �ͷŶ����ڴ�
        delete use; 		// �ͷż������ڴ�
    }
}

template <typename T>
SP<T>& SP<T>::operator=(const SP<T> &rhs)
{
    if (rhs.use)
    {
        ++*rhs.use; // �����Ҳ������������ü���
    }
    if (use && --*use == 0)
    {
        // Ȼ��ݼ�����������ü���
        delete p; 		// ���û�������û�
        delete use; 		// �ͷű��������ĳ�Ա
    }
    p = rhs.p; 		// ����ָ��
    use = rhs.use;
    return *this; 		// ���ر�����
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
    UP(const UP &) = delete;  // ��ֹ�������캯��
    explicit UP(T* pt) : p(pt) {}  // ���캯��
    UP& operator=(const UP&) = delete;  // ��ֹ������ֵ�����
    ~UP();
    T* release();   // ��������Ȩ
    void reset(T *new_p = nullptr);     // �ͷŶ���
    T& operator*() { return *p; }       // ������
    T& operator*() const { return *p; } // const��

private:
    T *p;
};

template <typename T>
UP<T>::~UP()
{
    if (p)        // ����Ѿ������˿ռ�
    {
        delete p; 	// �ͷŶ����ڴ�
    }
}

template <typename T>
void UP<T>::reset(T *new_p /*= nullptr*/)
{
    if (p)
    {
        delete p;     // �ͷŶ����ڴ�
    }
    p = new_p;      // ָ���¶���
}

template <typename T>
T* UP<T>::release()
{
    T *q = p;
    p = nullptr;  // ���ָ��
    return q; 		// ���ض���ָ��
}

#endif
