#include "ex13_30.h"



HasPtr2& HasPtr2::operator=(HasPtr2 rhs) {
	swap(*this, rhs);
	return *this;
}

bool operator<(const HasPtr2 &p1, const HasPtr2 &p2){
	return *p1.ps < *p2.ps;
}

inline void swap(HasPtr2 &p1, HasPtr2 &p2) {
	using std::swap;
	swap(p1.ps, p2.ps);
	swap(p1.i, p2.i);
	std::cout << " call swap(HasPtr2&, HasPtr2&) " << std::endl;
}
