#include "ex13_39.h"
#include <utility>
#include <algorithm>

//static bug fixed
std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &s){
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap){
	s.elements = s.first_free = s.cap = nullptr;
}



//ex13_40
StrVec::StrVec(std::initializer_list<std::string> il){
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = newdata.second;
}

StrVec & StrVec::operator=(const StrVec &rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}

StrVec & StrVec::operator=(std::initializer_list<std::string> il){
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;

}

std::string & StrVec::operator[](std::size_t n){
	return elements[n];
}

const std::string & StrVec::operator[](std::size_t n) const{
	return elements[n];
}

StrVec & StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::~StrVec(){
	free();
}

void StrVec::push_back(const std::string &s){
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::resize(size_t n, std::string s){
	if (n < size()) {
		while (n < size())
			push_back(s);
	}
}

void StrVec::resize(size_t n){
	if (n > size()) {
		while (n < size())
			push_back("");
	}
	else if (n < size()) {
		while (size() < n)
			alloc.destroy(--first_free);
	}
}

void StrVec::reserve(size_t n) {
	if (n > capcity())
		reallocate(n);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	auto data = alloc.allocate(e - b);
	return{data, std::uninitialized_copy(e, b, data)};
}

void StrVec::free(){
	if (elements) {
		/*
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		*/

		//ex13_43
		std::for_each(elements, first_free, [](const std::string &s) {alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate(){
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;

}

void StrVec::reallocate(size_t n){
	auto newdata = alloc.allocate(n);
	auto dest = elements;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

bool operator==(const StrVec &lhs, const StrVec &rhs){
	if (lhs.size() != rhs.size())
		return false;
	for (auto it1 = lhs.begin(), it2 = rhs.begin(); it1 != lhs.end(), it2 != rhs.end(); it1++, it2++) {
		if (*it1 != *it2)
			return false;
	}
	return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs){
	return !(lhs == rhs);
}

bool operator<(const StrVec & lhs, const StrVec & rhs){
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator<=(const StrVec & lhs, const StrVec & rhs){
	return !(lhs > rhs);
}

bool operator>(const StrVec & lhs, const StrVec & rhs)
{
	return rhs < lhs;
}

bool operator>=(const StrVec & lhs, const StrVec & rhs)
{
	return !(lhs < rhs);
}
