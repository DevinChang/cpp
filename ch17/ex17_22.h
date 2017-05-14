#pragma once
#include <iostream>
#include <regex>
#include <string>

std::string phone = "(\\()?(\\d{3})(\\))?([-. ]|(\\s)*)?(\\d{3})([-. ]|(\\s)*)?(\\d{4})";

bool valid_space(std::smatch &m) {
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || (m[4].str() != "-" && m[4].str() != "."));
	else
		return !m[3].matched && ((m[4].str() == m[6].str()));
}