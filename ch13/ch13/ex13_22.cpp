#include <iostream>
#include <string>
#include <vector>



class Employee {
public:
	Employee(std::string &sname) : name(sname) {
		static int snum = 10;
		number = snum++;
	}
	//ex13_19 cause employee can't be copy.
	Employee(Employee &emp) = delete;
	Employee &operator= (const Employee &emp) = delete;
	~Employee();
private:
	std::string name;
	int number;
};