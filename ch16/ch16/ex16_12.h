#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator== (const Blob<T> &, const Blob<T> &);

template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob() try : data(std::make_shared<std::vector<T>>()) {
	}
	catch (const std::bad_alloc &e) { /*handle_out_of_memory(e);*/ }
	Blob(std::initializer_list<T> il) try : data(std::make_shared<std::vector<T>>(il)){
	}
	catch (const std::bad_alloc &e) { /*handle_out_of_memory(e);*/ }
	template <typename It> Blob(It b, It e);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T &back();
	const T &back() const;
	T &front();
	const T &front() const;
	T &at(size_type);
	const T &at(size_type) const;
	T &operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

template<typename T>
inline void Blob<T>::pop_back(){
	check(0, "pop_back empty Blob");
	data->pop_back();
}

template<typename T>
inline T & Blob<T>::back(){
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline const T & Blob<T>::back() const{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline T & Blob<T>::front(){
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
inline const T & Blob<T>::front() const{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
inline T & Blob<T>::at(size_type i){
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline const T & Blob<T>::at(size_type) const{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline T & Blob<T>::operator[](size_type i){
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string & msg) const{
	if (i >= data->size())
		throw std::out_of_range(msg);
}



template <typename T> class BlobPtr {
public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob <T>&a, size_t sz = 0) try : wptr(a.data), curr(sz){
	}
	catch (const std::bad_alloc &e) { /*handle_out_of_memory(e);*/ }
	T &operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr<T> operator++(int);
	BlobPtr<T> operator--(int);
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template<typename T>
inline BlobPtr<T> & BlobPtr<T>::operator++(){
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

template<typename T>
inline BlobPtr<T> & BlobPtr<T>::operator--(){
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int){
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int){
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template<typename T>
inline std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t, const std::string &) const
{
	return std::shared_ptr<std::vector<T>>();
}



template<typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs){
	if (lhs.size() != rhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

template<typename T>
template<typename It>
inline Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)){}
