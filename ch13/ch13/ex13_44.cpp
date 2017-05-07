#include "ex13_44.h"
#include <algorithm>


std::allocator<char> String::alloc;


String::String(const char *c){
	
	auto len = std::strlen(c);
	auto newdata = alloc_n_copy(c, c + len + 1);
	elements = newdata.first;
	first_free = newdata.second;
	std::cout << "call String(const char*)" << std::endl;
}

String::String(const String & s){
	
	auto newdata = alloc_n_copy(s.elements, s.first_free);
	elements = newdata.first;
	first_free = newdata.second;
	std::cout << "call String(const String&)" << std::endl;
}

String::String(String &&rhs) : elements(rhs.elements), first_free(rhs.first_free){
	rhs.elements = nullptr;
	rhs.first_free = nullptr;
	std::cout << "call String(String &&)" << std::endl;
}

String & String::operator=(const String &s){
	
	auto newdata = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newdata.first;
	first_free = newdata.second;
	std::cout << "call operator =(const String&)" << std::endl;
	return *this;
}

String & String::operator=(String &&rhs){
	if (this != &rhs) {
		elements = rhs.elements;
		first_free = rhs.first_free;
		rhs.elements = nullptr;
		rhs.first_free = nullptr;
	}
	std::cout << "call operator=(String &&)" << std::endl;
	return *this;
}



void String::range_initializer(const char *, const char *)
{
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e){
	/*int n = 0;
	while (*b++) {
		n++;
	}*/
		
	auto data = alloc.allocate(e - b);
	return{ data, std::uninitialized_copy(b, e, data) };
}

void String::free(){
	if (elements) 
		//error: [](char *) fixed: [](char &)
		std::for_each(elements, first_free, [](char &c) {alloc.destroy(&c); });
		alloc.deallocate(elements, first_free - elements);
}


