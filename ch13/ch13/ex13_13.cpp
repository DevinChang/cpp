#include <iostream>
#include <vector>


struct X {
	X() { std::cout << "X()" << std::endl; }
	//X(X &obj) { std::cout << "X(X&)" << std::endl; }
	X(const X &obj) { std::cout << "X(const X&)" << std::endl; }
	X& operator = (const X &obj) { std::cout << "X &operator=" << std::endl; return *this; }
	~X() { std::cout << "~X()" << std::endl; }
};

void fuc(const X &x1, X x2) {
	X *b = new X;
	std::vector<X> vec;
	vec.push_back(x1);
	vec.push_back(x2);

	//vec.emplace_back(x1);
	//delete b;

}

void f(const X &rx, X x)
{
	std::vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);
	vec.push_back(x);
}

int main2() {
   	X a;
	
	X b(a);
	//X c = a;


	//fuc(a, a);

	std::vector<X> vec;
	
	//@bref:
	//若不事先给vec分配好内存空间，则每回插入的时候，需要执行一个临时对象的拷贝析构。如：当vec中没有对象，第一次push_back，
	//执行一次拷贝构造函数.当再次push_back对象后，构造一个临时的拷贝构造对象，然后析构，之后再将此对象插入到容器，此过程需要
	//执行拷贝构造函数。之后每次插入，执行拷贝构造函数和析构函数的次数取决于容器内的对象数目。有点类似于将插入排序，将容器中的
	//对象移动，再拷贝。
	//
	//
	//vec.reserve(2);
	vec.push_back(a);
	vec.push_back(b);  
	vec.push_back(a);
	vec.push_back(b);

	/*X *px = new X;
	f(*px, *px);
	delete px;*/

	system("pause");
	return 0;
}