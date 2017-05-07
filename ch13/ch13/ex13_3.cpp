#include "ex13_3.h"



inline void swap(HasPtr &lhs, HasPtr &rhs){
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

//HasPtr & HasPtr::operator=(const HasPtr & p){
//	auto newp = new std::string(*p.ps);
//	delete ps;
//	ps = newp;
//	i = p.i;
//	return *this;
//}

HasPtr & HasPtr::operator= (HasPtr rhs){
	swap(*this, rhs);
	return *this;
}

HasPtr & HasPtr::operator=(HasPtr && p){
	if (this != &p) {
		delete ps;
		ps = p.ps;
		i = p.i;
		p.ps = nullptr;
		p.i = 0;
	}
	return *this;
}


