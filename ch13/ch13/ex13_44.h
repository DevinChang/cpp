#pragma once
#include <iostream>
#include <memory>



class String{
public:
	String() : elements(nullptr), first_free(nullptr){}
	String(const char*);
	String(const String &s);
	String(String &&);
	String &operator= (const String &);
	String &operator= (String &&);
	~String() { free(); }
	size_t size() const { return first_free - elements; }
	//size_t capacity() const { return cap - elements; }
	char *begin() const  { return elements; }
	char *end()  const { return first_free; }
private:
	static std::allocator<char> alloc;
	void range_initializer(const char *, const char *);
	std::pair<char *, char *> alloc_n_copy(const char *, const char *);
	void free();
	char *elements;
	char *first_free;
	//char *cap;
};

