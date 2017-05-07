#include <iostream>
#include <memory>
#include <string>





int main10() {
	std::allocator <std::string> astr;
	int len = 5;
	auto p = astr.allocate(len);
	auto q = p;
	std::string s;
	while (std::cin >> s && q != p + len)
		astr.construct(q++, s);

	while (q != p) {
		std::cout << *--q << std::endl;
		astr.destroy(q);
	}
	
	astr.deallocate(p, len);


	system("pause");
	return 0;
}