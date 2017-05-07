#pragma once
#include <iostream>
#include <string>

//7_21 modify: struct -> class
class Sales_data {
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend std::ostream &operator<< (std::ostream &, const Sales_data &);
	friend std::istream &operator >> (std::istream &,  Sales_data &);
	friend Sales_data operator+ (const Sales_data &, const Sales_data &);
	friend Sales_data operator- (const Sales_data &, const Sales_data &);
public:
	//7_11 add
	//Sales_data() = default;
	//Sales_data(const std::string &s) : bookNo(s){}
	//Sales_data(std::istream &);
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), unite_told(n), revenue(p) {
		//7_41 modify
		std::cout << "three param" << std::endl;
	}

	//7_41 modify: delegating constructor
	Sales_data() : Sales_data("", 0, 0) { std::cout << "default constructor" << std::endl; }
	Sales_data(const std::string &s) : Sales_data(s, 0, 0) { std::cout << "one param constructor" << std::endl; }
	Sales_data(std::istream &is) : Sales_data() {
		std::cout << "istream constructor" << std::endl;
		read(is, *this);
	}
	Sales_data &operator= (const Sales_data &);
	Sales_data &operator= (const std::string &);
	Sales_data &operator+= (const Sales_data &);
	Sales_data &operator-= (const Sales_data &);

	explicit operator std::string() const { return bookNo; }
	explicit operator double() const { return revenue; }
	//7_12
	//Sales_data(std::istream &){ read(is, *this); }


	//7_2 reserve
	std::string isbn() const { return bookNo; }
	//Sales_data &combine(const Sales_data &);
	//7_49 text
	Sales_data &combine(const Sales_data &);

private:
	std::string bookNo;
	unsigned unite_told = 0;
	double revenue = 0.0;

};


/*
Sales_data::Sales_data(std::istream &is){
read(is, *this);
}
*/