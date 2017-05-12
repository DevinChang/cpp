#pragma once
#pragma once

#include <string>
#include <iostream>


class Sales_data
{
	// friends
	friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);

	friend std::ostream& operator<< (std::ostream& os, const Sales_data& s);

	friend std::istream& operator >> (std::istream& is, Sales_data& s);

	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);

public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(const Sales_data &s) :
		bookNo(s.bookNo), units_sold(s.units_sold), revenue(s.revenue) { }

	Sales_data(Sales_data&& s) :
		bookNo(s.bookNo), units_sold(s.units_sold), revenue(s.revenue) { }

	~Sales_data() { }
	Sales_data(std::istream &);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

	// assignments
	Sales_data& operator  =(const Sales_data& rhs);
	Sales_data& operator  =(const std::string&  rhs);
	Sales_data& operator +=(const Sales_data& rhs);

	// conversion
	explicit operator std::string() const { return bookNo; }
	explicit operator double() const { return revenue; }

	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


// overloaded operators added 10.Jan.2014 for ex14.2
inline Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum += rhs;

	return sum;
}




// used in future chapters
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}

//#include <string>
//
////7_21 modify: struct -> class
//class Sales_data {
//	friend std::istream &read(std::istream &is, Sales_data &item);
//	friend std::ostream &print(std::ostream &os, const Sales_data &item);
//public:
//	//7_11 add
//	//Sales_data() = default;
//	//Sales_data(const std::string &s) : bookNo(s){}
//	//Sales_data(std::istream &);
//	Sales_data(const std::string &s, unsigned n, double p) :
//		bookNo(s), unite_told(n), revenue(p) {
//		//7_41 modify
//		std::cout << "three param" << std::endl;
//	}
//	
//	//7_41 modify: delegating constructor
//	Sales_data() : Sales_data("", 0, 0){ std::cout << "default constructor" << std::endl; }
//	Sales_data(const std::string &s) : Sales_data(s, 0, 0){ std::cout << "one param constructor" << std::endl; }
//	Sales_data(std::istream &is) : Sales_data() { 
//		std::cout << "istream constructor" << std::endl;
//		read(is, *this); 
//	}
//
//	
//	//7_12
//	//Sales_data(std::istream &){ read(is, *this); }
//	
//
//	//7_2 reserve
//	std::string isbn() const { return bookNo; }
//	//Sales_data &combine(const Sales_data &);
//	//7_49 text
//	Sales_data &combine(const Sales_data &);
//private:
//	std::string bookNo;
//	unsigned unite_told = 0; 
//	double revenue = 0.0;
//
//};
//
//Sales_data  &Sales_data::combine(const Sales_data &rhs) {
//	unite_told += rhs.unite_told;
//	revenue += rhs.revenue;
//	return *this;
//}
//
//std::istream &read(std::istream &is, Sales_data &item){
//	double price = 0.0;
//	is >> item.bookNo >> item.unite_told >> price;
//	item.revenue = price *item.unite_told;
//	return is;
//}
//
//std::ostream &print(std::ostream &os, const Sales_data &item){
//	os << item.isbn() << " " << item.unite_told << " "
//		<< item.revenue;
//	return os;
//}



//Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
//	Sales_data sum = lhs;
//	sum.combine(rhs);
//	return sum;
//}

/*
Sales_data::Sales_data(std::istream &is){
	read(is, *this);
}
*/