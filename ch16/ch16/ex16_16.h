#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <initializer_list>
#include <algorithm>

//2017/5/9 error: 成员函数运算符重载的时候不用在类外再声明。
//template <typename> class Vec;
//template <typename T>
//Vec<T> &operator= (const Vec<T> &);


template <typename T> class Vec {

public:
	Vec() = default;
	Vec(std::initializer_list<T>);
	Vec(const Vec<T> &);
	Vec(Vec<T> && ) noexcept;
	Vec &operator= (const Vec<T> &);
	Vec &operator= (std::initializer_list<T>);
	Vec &operator= (Vec<T> &&) noexcept;
	T &operator[] (size_t n);
	const T &operator[] (std::size_t n) const;
	~Vec();
public:
	void push_back(const T&);
	size_t size() { return first_free - elements; }
	size_t capacity() { return cap - elements; }
	T *begin() { return elements; }
	T *end() { return first_free; }
	void resize(size_t n);
	void resize(size_t n, T &);
	void reserve(size_t);
private:
	static std::allocator<T> alloc;
	void check_n_copy() { if (size() == capacity()) realloc(); }
	std::pair<T *, T *> alloc_n_copy(const T *, const T *);
	void reallocate();
	void reallocate(size_t);
	void free();
	T *elements;
	T *first_free;
	T *cap;
};

template <typename T>
std::allocator<T> Vec<T>::alloc;


template<typename T>
inline Vec<T>::Vec(std::initializer_list<T> il){
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T>
inline Vec<T>::Vec(const Vec<T> &vec){
	auto newdata = alloc_n_copy(vec.begin(), vec.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T>
inline Vec<T>::Vec(Vec<T> &&vec) noexcept : elements(vec.elements), first_free(vec.firstr_free), cap(vec.cap){
	vec.elements = vec.first_free = vec.cap = nullptr;
}

template<typename T>
inline Vec<T> & Vec<T>::operator=(const Vec<T> &v){
	auto newdata = alloc_n_copy(v.begin(), v.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

template<typename T>
inline Vec<T> & Vec<T>::operator=(std::initializer_list<T> il){
	auto newdata = alloc_n_copy(il.begin(), il.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

template<typename T>
inline Vec<T> & Vec<T>::operator=(Vec<T> &&v) noexcept{
	if (this != &v) {
		free();
		elements = v.elements;
		first_free = v.first_free;
		cap = v.cap;
		v.elements = v.first_free = v.cap = nullptr;
	}
	return *this;
}

template<typename T>
inline T & Vec<T>::operator[](size_t n){
	return elements[n];
}

template<typename T>
inline const T & Vec<T>::operator[](std::size_t n) const{
	return elements[n];
}

template<typename T>
inline Vec<T>::~Vec(){
	free();
}

template<typename T>
inline void Vec<T>::push_back(const T &t){
	check_n_copy();
	alloc.construct(first_free++, t);
}

template<typename T>
inline void Vec<T>::resize(size_t n){
	if (n > size()) {
		while (n < size())
			push_back(T());
	}
	else if (size() > n) {
		while (size() > n)
			alloc.destroy(--first_free);
	}
}

template<typename T>
inline void Vec<T>::resize(size_t n, T &t){
	if (n > size()) {
		while (n > size())
			push_back(t);
	}
}

template<typename T>
inline void Vec<T>::reserve(size_t n){
	if (n > capacity())
		reallocate(n);
}

template<typename T>
inline std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e){
	auto newdata = alloc.allocate(e - b);
	return{ newdata, std::uninitialized_copy(b, e, newdata) };
}

template<typename T>
inline void Vec<T>::reallocate(){
	auto newcap = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcap;
}

template<typename T>
inline void Vec<T>::reallocate(size_t n){
	auto newdata = alloc.allocate(n);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}


template<typename T>
inline void Vec<T>::free(){
	if (elements) {
		std::for_each(elements, first_free, [](const T &t) {alloc.destroy(&t); });
		alloc.deallocate(elements, cap - elements);
	}
}
