#include <iostream>
#include <typeinfo>
using std::cout; using std::endl;

template <typename T> void f(T a)
{
    cout << "f(T), T是" << typeid(T).name() << endl;
}

template <typename T> void f(const T *a)
{
    cout << "f(const T*), const T*是" << typeid(const T*).name() << endl;
}

template <typename T> void g(T a)
{
    cout << "g(T), T是" << typeid(T).name() << endl;
}

template <typename T> void g(T *a)
{
    cout << "g(T*), T*是" << typeid(T*).name() << endl;
}

int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42); g(p); g(ci); g(p2);
    f(42); f(p); f(ci); f(p2);
	return 0;
}
