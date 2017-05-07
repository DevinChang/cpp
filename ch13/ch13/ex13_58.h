#pragma once
#include <iostream>
#include <vector>


class Foo {
public:
	Foo sorted() && ;
	Foo sorted() const &;
private:
	std::vector<int> data;
};