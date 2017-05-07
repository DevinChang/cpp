#include "ex13_44_Str.h"
#include <algorithm>


Str::Str(const char *c) : n(std::strlen(c)), p(alloc.allocate(n)){
	std::cout << "call Str(const char*) " << c << std::endl;
	std::uninitialized_copy(c, c + n, p);
}

Str::Str(const Str &s) : p(alloc.allocate(s.n)) {
	std::cout << "call Str(const Str&) " << s.p << std::endl;
	std::uninitialized_copy(s.p, s.p + s.n, p);
}

Str::Str(Str &&s) : n(s.n), p (s.p){
	std::cout << "call Str(const Str &&)" << s.p << std::endl;
	s.n = 0;
	s.p = 0;
}

Str & Str::operator=(const Str &rhs){
	std::cout << "call opreator = (const Str&) " << rhs.p << std::endl;
	auto newp = alloc.allocate(rhs.n);
	std::uninitialized_copy(rhs.p, rhs.p + rhs.n, newp);
	free();
	p = newp;
	n = rhs.n;
	return *this;
}

Str & Str::operator=(Str &&rhs){
	std::cout << "call operatro = (Str&&) " << rhs.p << std::endl;
	if (this != &rhs) {
		free();
		p = rhs.p;
		n = rhs.n;
		rhs.p = 0;
		rhs.n = 0;
	}
	return *this;
}

Str::~Str(){
	free();
}

void Str::free(){
	if (p) {
		std::for_each(p, p + n, [this](char &c) {alloc.destroy(&c); });
		alloc.deallocate(p, n);
	}
}
