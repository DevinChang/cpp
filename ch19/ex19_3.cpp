#include <iostream>




class A{
public:
	virtual void foo() { std::cout << "A" << std::endl; }
};
class B : public A {};
class C : public B {};
class D : public B, public A{};





int main() {

	A *pa = new C;
	if (B *pb = dynamic_cast<B*> (pa)) {
		std::cout << "convert success!" << std::endl;
	}
	else {
		std::cout << "convert fail!!" << std::endl;
	}

	//B *pb = new B;
	//if (C *pc = dynamic_cast<C*> (pb)) {
	//	std::cout << "convert success!" << std::endl;
	//}
	//else {
	//	std::cout << "convert fail!!" << std::endl;
	//}

	system("pause");
	return 0;
}