#include "ex13_58.h"
#include <algorithm>

Foo Foo::sorted() && {
	std::cout << "call sorted() &&" << std::endl;
	std::sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const & {
	std::cout << "call sorted() const &" << std::endl; 
	Foo ret(*this);
	std::sort(ret.data.begin(), ret.data.end());
	return ret;
}
