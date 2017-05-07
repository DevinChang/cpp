#include "ex13_27.h"



HasPtr1& HasPtr1::operator=(const HasPtr1 &rhs) {
	++*rhs.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

HasPtr1::~HasPtr1()
{
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}
