#pragma once
#include <iostream>
#include <functional>
#include "ex16_21.h"

template <typename> class SharePointer;
template <typename T>
void swap(SharePointer<T> &lhs, SharePointer<T> &rhs);


template <typename T>
class SharePointer {
	friend void swap<T>(SharePointer<T> &lhs, SharePointer<T> &rhs);
public:
	SharePointer() : p(nullptr), use(nullptr), deleter(DebugDelete()){}
	explicit SharePointer(T *pt) : p(pt), use(new size_t(1)), deleter(DebugDelete()){}
	SharePointer(const SharePointer &sp) : p(sp.p), use(sp.use), deleter(sp.deleter) { if (use)++*use; }
	SharePointer &operator= (const SharePointer &);
	T &operator* () { return *p; }
	const T &operator* () const { return *p; }
	T *operator->() const { return &*p; }
	void get() { return p; }
	void swap(SharePointer &rhs) { ::swap(*this, rhs); }
	int use_count() const { return *use; }
	bool unique() const { return use_count() == 1; }
	void reset() { free(); }
	void reset(T *tp);
	void reset(T *tp, std::function<void(T *)> del);
	
	~SharePointer();
private:
	T *p;
	size_t *use;
	std::function<void(T*)> deleter;
	void free();
};

template<typename T>
inline SharePointer<T> & SharePointer<T>::operator=(const SharePointer &sp){
	++*sp.use;
	if (--*use == 0) {
		delete p;
		delete use;
	}
	p = sp.p;
	use = sp.use;
	deleter = sp.deleter;
	return *this;
}

template<typename T>
inline void SharePointer<T>::reset(T * tp){
	if (p != tp) {
		free();
		p = tp.p;
		use = new size_t(1);	
	}
}

template<typename T>
inline void SharePointer<T>::reset(T * tp, std::function<void(T*)> del){
	reset(tp);
	deleter = del;
}

template<typename T>
inline SharePointer<T>::~SharePointer(){
	/*if (--*use == 0) {
		delete p;
		delete use;
	}*/
	free();
}

template<typename T>
inline void SharePointer<T>::free(){
	//若p不为空，且--*use==0表明p是指向SharePointer唯一对象
	if (p && 0 == --*use) {
		delete use;
		deleter(p);
	}
	//
	else if (!p)
		delete use;
	use = nullptr;
	p = nullptr;
}

template<typename T>
void swap(SharePointer<T> &lhs, SharePointer<T>& rhs){
	using std::swap;
	swap(lhs.p, rhs.p);
	swap(lhs.use, rhs.use);
}


template<typename T, typename...Args>
SharePointer<T> makeshared(Args&&... args) {
	return SharePointer<T>(new T(std::forward<Args>(args)...));
}

template <typename, typename> class UniquePointer;
template<typename T, typename D>
void swap(UniquePointer<T, D> &lhs, UniquePointer<T, D> &rhs);


template <typename T, typename D = DebugDelete>
class UniquePointer {
	friend void swap<T, D>(UniquePointer &lhs, UniquePointer &rhs);
public:
	UniquePointer() : p(nullptr) {}
	explicit UniquePointer(T *up) : p(up) {}
	UniquePointer(const UniquePointer &) = delete;
	UniquePointer &operator= (const UniquePointer &) = delete;
public:
	T &operator* () const { reutrn *p; }
	T *operator->() const { return &*p; }//return &this->operator*(); }
	void get() const { return p; }
	void reset() { deleter(p); p = nullptr; }
	void reset(T *up) { deleter(p); p = up; }
	T* release();
	~UniquePointer() { deleter(p); }
private:
	T *p;
	D deleter = D();
};


template<typename T, typename D>
inline void swap(UniquePointer<T, D>& lhs, UniquePointer<T, D>& rhs){
	using std::swap();
	swap(lhs.p, rhs.p);
	swap(lhs.deleter, rhs.deleter);
}

template<typename T, typename D>
inline T* UniquePointer<T, D>::release(){
	T *ret = p;
	deleter(p);
	return ret;
}


