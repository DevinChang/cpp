#pragma once

#include <iostream>
#include <string>

//Notice!!!!! There must be declear defination!
class Person;
std::istream &read(std::istream &is, Person &per);

//7_22 modify: struct -> class
class Person{
	friend std::istream &read(std::istream &is, Person &per);
	friend std::ostream &print(std::ostream &os, const Person &per);
public:
	//7_15 add
	Person() = default;
	Person(const std::string &s, const std::string &addr) : name(s), address(addr){}
	//7_50 modify: add explicit, cause Person(std::istream &s) has one parameter.
	explicit Person(std::istream &s) { read(s, *this); }
	
	std::string getname() const { return name; }
	std::string getaddr() const { return address; }
private:
	std::string name;
	std::string address;
	
};

std::istream &read(std::istream &is, Person &per){
	is >> per.name >> per.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &per){
	os << per.name << " " << per.address;
	return os;
}