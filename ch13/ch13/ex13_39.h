#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <initializer_list>
#include <utility>



class StrVec {
	friend bool operator== (const StrVec &, const StrVec &);
	friend bool operator!= (const StrVec &, const StrVec &);
	friend bool operator< (const StrVec &lhs, const StrVec &rhs);
	friend bool operator<= (const StrVec &lhs, const StrVec &rhs);
	friend bool operator> (const StrVec &lhs, const StrVec &rhs);
	friend bool operator>= (const StrVec &lhs, const StrVec &rhs);
	friend std::ostream &operator<< (std::ostream &os, const StrVec &rhs);
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(const StrVec &);
	StrVec(StrVec &&) noexcept;
	StrVec &operator= (StrVec &&) noexcept;
	//ex13_40
	StrVec(std::initializer_list<std::string >);
	StrVec &operator= (const StrVec&);
	StrVec &operator= (std::initializer_list<std::string>);
	std::string &operator[] (std::size_t n);
	const std::string &operator[] (std::size_t n) const;
	~StrVec();
	void push_back(const std::string &);
	std::string &pop();
	size_t size() const { return first_free - elements; }
	size_t capcity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
	template <typename...Args>
	void emplace_back(Args&&... args);
	void resize(size_t n, std::string s);
	void resize(size_t n);
	void reserve(size_t);
private:
	//static必须在类外定义。
	static std::allocator<std::string> alloc;
	void chk_n_alloc() { 
		if (size() == capcity()) reallocate(); 
	}
	std::pair<std::string *, std::string*> alloc_n_copy(const std::string *, const std::string *);
	void free();
	void reallocate();
	void reallocate(size_t n);
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

template<typename ...Args>
inline void StrVec::emplace_back(Args && ...args){
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}
