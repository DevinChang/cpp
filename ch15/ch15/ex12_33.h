#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include "ex12_2.h"

namespace chapter10 {
	class QueryResult3;

	class TextQuery3 {
	public:
		using line_no = StrBolb::size_type;
		TextQuery3() {}
		TextQuery3(std::ifstream &);
		QueryResult3 query(const std::string &) const;
	private:
		StrBolb file;
		std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
	};


	class QueryResult3 {
		friend std::ostream &print(std::ostream &, QueryResult3 &);
		friend std::ostream &operator<< (std::ostream &, QueryResult3 &);
		using ResultIt = std::set<TextQuery3::line_no>::iterator;
	public:
		//error: 不能将s声明成引用.
		QueryResult3(std::string s, std::shared_ptr<std::set<TextQuery3::line_no>> p, const StrBolb &f) :
			word(s), lines(p), file(f) { }
		ResultIt begin() { return lines->begin(); }
		ResultIt end() { return lines->end(); }
		std::shared_ptr<StrBolb> get_file() { return std::make_shared<StrBolb>(file); }
	private:
		std::string word;
		StrBolb file;
		std::shared_ptr<std::set<TextQuery3::line_no>> lines;
	};

}
