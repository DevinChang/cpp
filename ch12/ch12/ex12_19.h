#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "ex12_2.h"


class StrBolbPtr {
	friend bool operator== (const StrBolbPtr &, const StrBolbPtr &);
	friend bool operator!= (const StrBolbPtr &, const StrBolbPtr &);
	friend bool operator< (const StrBolbPtr &lhs, const StrBolbPtr &rhs);
	friend bool operator<= (const StrBolbPtr &lhs, const StrBolbPtr &rhs);
	friend bool operator> (const StrBolbPtr &lhs, const StrBolbPtr &rhs);
	friend bool operator>= (const StrBolbPtr &lhs, const StrBolbPtr &rhs);
	
public:
	StrBolbPtr() : curr(0){}
	StrBolbPtr(StrBolb &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	StrBolbPtr(const StrBolb &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string &operator[] (std::size_t n) { auto p = check(n, "deference out of range"); return (*p)[n]; }
	const std::string &operator[] (std::size_t n) const { auto p = check(n, "deference out of range"); return (*p)[n]; }
	StrBolbPtr &operator++();
	StrBolbPtr operator++(int);
	StrBolbPtr &operator--();
	StrBolbPtr operator--(int);
	StrBolbPtr operator+ (int n);
	StrBolbPtr operator- (int n);
	std::string &operator* () const;
	std::string *operator-> () const;
	std::string &deref() const;
	StrBolbPtr &incr();
	//bool operator !=(const StrBolbPtr &p) { return p.curr != curr; }
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

