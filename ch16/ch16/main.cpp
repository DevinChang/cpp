#include "ex16_4.h"
#include <vector>
#include <list>
#include <string>
#include "ex16_5.h"
#include "ex16_12.h"
#include "ex16_14.h"
#include "ex16_16.h"
#include "ex16_19.h"
#include "ex16_28.h"
#include "ex16_47.h"
#include "ex16_48.h"
#include "ex16_50.h"
#include "ex16_52.h"
#include "ex16_53.h"
#include "ex16_56.h"


void f(int v1, int &v2) {
	std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int &&i, int &j) {
	std::cout << i << " " << j << std::endl;
}

int main() {
	std::cout << "ex16_4: " << std::endl;
	std::vector<int> vec{ 0, 2, 1, 8, 3, 6, 9, 2 };
	std::list<int> lst{ 1, 8, 6, 2, 3, 2, 6 };
	std::list<std::string> ls{ "hello", "world", "devin" };
	int value = 6;
	auto it = ifind(vec.begin(), vec.end(), value);
	if (it == vec.end())
		std::cout << "can not find " << value << std::endl;
	else
		std::cout << "find " << value << " successful." << std::endl;

	std::cout << "ex16_5: " << std::endl;
	int arr[5] = { 1, 2, 3, 4, 5 };
	char s[4] = { 'd', 'e', 'v' };
	iprint(arr);
	iprint(s);

	std::cout << "ex16_12: " << std::endl;
	Blob<std::string> b;
	std::cout << b.size() << std::endl;

	std::cout << "ex16_14_15: " << std::endl;
	Screen<5, 3> iscreen;
	iscreen.display(std::cout);
	iscreen.move(4, 0).set('*').display(std::cout);
	std::cout << iscreen << std::endl;
	std::cout << "input anything you want: " << std::endl;
	std::cin >> iscreen;
	std::cout << std::endl;
	std::cout << iscreen;
	
	std::cout << "ex16_16: " << std::endl;
	
	Vec<std::string> sv{ "devin", "chang" };
	std::cout << sv.size() << std::endl;
	sv.emplace_back("warriors.");
	sv.emplace_back(10, '!');
	for (auto &p : sv)
		std::cout << p << std::endl;

	std::cout << "ex16_19: " << std::endl;
	mprint(std::cout, vec) << std::endl;
	mprint2(std::cout, lst) << std::endl;
	//mprint(lst);

	std::cout << "ex16_21: " << std::endl;
	auto foo = SharePointer<int>(new int(21));
	auto bar(foo);
	std::cout << *foo << std::endl;
	std::cout << foo.use_count() << std::endl;
	auto foo2 = SharePointer<std::string>(new std::string("DevinChang"));
	std::cout << *foo2 << std::endl;

	std::cout << "ex16_47: " << std::endl;
	int i = 22, j = 21;
	flip(f, j, 42);
	flip(g, i, 42);

	std::cout << "ex16_48: " << std::endl;
	std::string s2("hi");
	std::cout << debug_rep(s2) << std::endl;
	std::cout << debug_rep("hello world") << std::endl;
	
	std::cout << "ex16_50: " << std::endl;
	int im = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);
	g(p);
	g(ci);
	g(p2);
	f(42);
	f(p);
	f(ci);
	f(p2);

	std::cout << "ex16_51:" << std::endl;
	int ii = 21;
	double d = 3.14; 
	std::string ss = "how now brown cow";
	ifoo(i, s, 42, d);
	ifoo(s, 42, "hi");
	ifoo(d, s);
	ifoo("hi");

	std::cout << "ex16_53: " << std::endl;
	print(std::cout, ii, s, 42, d) << std::endl;
	print(std::cout, ss, ii) << std::endl;
	print(std::cout, d) << std::endl;

	std::cout << "ex16_56: " << std::endl;
	
	
	system("pause"); 
	return 0;
}