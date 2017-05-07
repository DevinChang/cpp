#include <iostream>




class numbered {
public:
	numbered() {
		static int unique = 10;
		mysn = unique++;
	}
	//ex13_15
	numbered(const numbered& n) {
		mysn = n.mysn + 1;
	}

	int mysn;
	
};



//ex13_16 modify numbered s to const numbered &s.
void f(const numbered &s) {
	std::cout << s.mysn << std::endl;
}

int main3()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	system("pause");
	return 0;
}
