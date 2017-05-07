#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <memory>
#include <utility>
#include <initializer_list>

// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec {
public:
	// copy control members
    StrVec():
	  elements(nullptr), first_free(nullptr), cap(nullptr) { }

	StrVec(const StrVec&);            // copy constructor
	StrVec &operator=(const StrVec&); // copy assignment

	StrVec(StrVec&&) noexcept;            // move constructor
	StrVec &operator=(StrVec&&) noexcept; // move assignment

	~StrVec() noexcept;                   // destructor

	// additional constructor
	StrVec(std::initializer_list<std::string>);

    void push_back(const std::string&);  // copy the element
    void push_back(std::string&&);       // move the element

	// add elements
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t n) { if (n > capacity()) reallocate(n); }
    void resize(size_t);
    void resize(size_t, const std::string&);

	// iterator interface
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	// operator functions covered in chapter 14
	StrVec &operator=(std::initializer_list<std::string>);

	std::string& operator[](std::size_t n)
		{ return elements[n]; }

	const std::string& operator[](std::size_t n) const
		{ return elements[n]; }

	// emplace member covered in chapter 16
	template <class... Args> void emplace_back(Args&&...);
private:
    static std::allocator<std::string> alloc; // allocates the elements

	// utility functions:
	//  used by members that add elements to the StrVec
	void chk_n_alloc()
		{ if (size() == capacity()) reallocate(); }
    // used by the copy constructor, assignment operator, and destructor
	std::pair<std::string*, std::string*> alloc_n_copy
	    (const std::string*, const std::string*);
	void free();             // destroy the elements and free the space
    void reallocate();       // get more space and copy the existing elements
    void reallocate(size_t);       // get more space and copy the existing elements
    std::string *elements;   // pointer to the first element in the array
    std::string *first_free; // pointer to the first free element in the array
    std::string *cap;        // pointer to one past the end of the array
};

#include <algorithm>

inline
StrVec::~StrVec() noexcept { free(); }

inline
std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	// allocate space to hold as many elements as are in the range
	auto data = alloc.allocate(e - b);

	// initialize and return a pair constructed from data and
	// the value returned by uninitialized_copy
	return {data, uninitialized_copy(b, e, data)};
}

inline
StrVec::StrVec(StrVec &&s) noexcept  // move won't throw any exceptions
  // member initializers take over the resources in s
  : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	// leave s in a state in which it is safe to run the destructor
	s.elements = s.first_free = s.cap = nullptr;
}

inline
StrVec::StrVec(const StrVec &s)
{
	// call alloc_n_copy to allocate exactly as many elements as in s
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

inline
void StrVec::free()
{
    // may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
	if (elements) {
    	// destroy the old elements in reverse order
		//for (auto p = first_free; p != elements; /* empty */)
			//alloc.destroy(--p);
    for_each(elements, first_free, [](std::string &s){ alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);
	}
}

inline
StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
	// alloc_n_copy allocates space and copies elements from the given range
	auto data = alloc_n_copy(il.begin(), il.end());
	free();   // destroy the elements in this object and free the space
	elements = data.first; // update data members to point to the new space
	first_free = cap = data.second;
	return *this;
}

inline
StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	// direct test for self-assignment
	if (this != &rhs) {
		free();                   // free existing elements
		elements = rhs.elements;  // take over resources from rhs
		first_free = rhs.first_free;
		cap = rhs.cap;
		// leave rhs in a destructible state
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

inline
StrVec &StrVec::operator=(const StrVec &rhs)
{
	// call alloc_n_copy to allocate exactly as many elements as in rhs
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

inline
void StrVec::reallocate()
{
    // we'll allocate space for twice as many elements as the current size
    auto newcapacity = size() ? 2 * size() : 1;

	// allocate new memory
	auto newdata = alloc.allocate(newcapacity);

	// move the data from the old memory to the new
	auto dest = newdata;  // points to the next free position in the new array
    auto elem = elements; // points to the next element in the old array
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));

	free();  // free the old space once we've moved the elements

    // update our data structure to point to the new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

inline
void StrVec::reallocate(size_t newcapacity)
{
	// allocate new memory
	auto newdata = alloc.allocate(newcapacity);

	// move the data from the old memory to the new
	auto dest = newdata;  // points to the next free position in the new array
    auto elem = elements; // points to the next element in the old array
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));

	free();  // free the old space once we've moved the elements

    // update our data structure to point to the new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

// 添加或销毁对象
inline
void StrVec::resize(size_t n)
{
  if (n > size()) {   // 添加空字符串
    while (size() < n)
      push_back("");
  } else if (n < size()) {  // 销毁字符串
    while (size() > n)
      alloc.destroy(--first_free);
  }
}

// 添加对象
inline
void StrVec::resize(size_t n, const std::string &s)
{
  if (n > size()) {
    while (size() < n)
      push_back(s);
  }
}

inline
StrVec::StrVec(std::initializer_list<std::string> il)
{
	// call alloc_n_copy to allocate exactly as many elements as in il
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

inline
void StrVec::push_back(const std::string& s)
{
    chk_n_alloc(); // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}

inline
void StrVec::push_back(std::string &&s)
{
    chk_n_alloc(); // reallocates the StrVec if necessary
	alloc.construct(first_free++, std::move(s));
}


// emplace member covered in chapter 16
template <class... Args>
inline
void StrVec::emplace_back(Args&&... args)
{
    chk_n_alloc(); // reallocates the StrVec if necessary
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif
