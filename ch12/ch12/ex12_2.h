#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>



class StrBolb{
	friend bool operator== (const StrBolb &, const StrBolb &);
	friend bool operator!= (const StrBolb &, const StrBolb &);
	friend bool operator< (const StrBolb &, const StrBolb &);
	friend bool operator<= (const StrBolb &, const StrBolb &);
	friend bool operator> (const StrBolb &, const StrBolb &);
	friend bool operator>= (const StrBolb &, const StrBolb &);
public:
	friend class StrBolbPtr;
	StrBolbPtr begin();
	StrBolbPtr end();

	typedef std::vector<std::string>::size_type size_type;
	StrBolb();
	StrBolb(std::initializer_list<std::string> il);
	std::string &operator[] (std::size_t n) { return data->at(n); }
	const std::string &operator[] (std::size_t n) const { return (*data)[n]; }
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t){ data->push_back(t); }
	void pop_back();
	std::string &front();
	std::string &front() const;
	std::string &back();
	std::string &back() const;
	

private:
	
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
	
};


