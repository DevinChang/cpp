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
	//�������ȸ�vec������ڴ�ռ䣬��ÿ�ز����ʱ����Ҫִ��һ����ʱ����Ŀ����������磺��vec��û�ж��󣬵�һ��push_back��
	//ִ��һ�ο������캯��.���ٴ�push_back����󣬹���һ����ʱ�Ŀ����������Ȼ��������֮���ٽ��˶�����뵽�������˹�����Ҫ
	//ִ�п������캯����֮��ÿ�β��룬ִ�п������캯�������������Ĵ���ȡ���������ڵĶ�����Ŀ���е������ڽ��������򣬽������е�
	//�����ƶ����ٿ�����
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