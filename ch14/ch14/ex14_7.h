#pragma once
#include <iostream>
#include <memory>



class Str {
	friend std::ostream &operator<< (std::ostream &os,  Str &);
	friend bool operator== (const Str &, const Str &);
	friend bool operator!= (const Str &, const Str &);
	friend bool operator< (const Str &lhs, const Str &rhs);
	friend bool operator<= (const Str &lhs, const Str &rhs);
	friend bool operator> (const Str &lhs, const Str &rhs);
	friend bool operator>= (const Str &lhs, const Str &rhs);
public:
	Str() = default;
	Str(const char *);
	Str(const Str&);
	Str(Str &&);
	Str &operator= (const Str&);
	Str &operator= (Str &&);
	~Str();
	//当const在函数名前面的时候修饰的是函数返回值，
	//在函数名后面表示是常成员函数，该函数不能修改对象内的任何成员，只能发生读操作，不能发生写操作。
	const char *begin() const { return p; }
	const char *begin() { return p; }
	const char *end() const { return p + n; }
	const char *end() { return p + n; }
	const size_t size() const { return n; }
	const size_t length() const { return n - 1; }
private:
	size_t n;
	char *p;
	std::allocator<char> alloc;
	void free();
};