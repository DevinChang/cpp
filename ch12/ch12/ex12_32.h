#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include "ex12_2.h"

class QueryResult2;

class TextQuery2 {
public:
	using line_no = StrBolb::size_type;
	TextQuery2(std::ifstream &);
	QueryResult2 query(const std::string &) const;
private:
	StrBolb file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult2 {
	friend std::ostream &print(std::ostream &, const QueryResult2 &);
public:
	QueryResult2(std::string s, std::shared_ptr<std::set<TextQuery2::line_no>> p, const StrBolb &f) : 
		sought(s), lines(p), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery2::line_no>> lines;
	StrBolb file;
};

