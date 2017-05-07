#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>



class StrBolb {
public:
	friend class StrBolbPtr;
	StrBolbPtr begin();
	StrBolbPtr end();

	typedef std::vector<std::string>::size_type size_type;
	StrBolb();
	StrBolb(std::initializer_list<std::string> il);
	//error: data(std::make_shared<std::vector<std::string>>(sb.data))
	//fixed: data(std::make_shared<std::vector<std::string>>(*sb.data))
	//cause sb.data is shared_ptr, *sb.data是把指针解引用得到其值。
	StrBolb(const StrBolb &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)){}
	StrBolb &operator = (const StrBolb &sb) {
		data = std::make_shared<std::vector<std::string>>(*sb.data);
		return *this;
	}
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void push_back(std::string &&t) { data->push_back(std::move(t)); }
	void pop_back();
	std::string &front();
	std::string &front() const;
	std::string &back();
	std::string &back() const;


private:

	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;

};