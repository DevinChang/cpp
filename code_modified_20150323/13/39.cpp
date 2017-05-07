#include "StrVec.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;
using std::istream;

#include <fstream>
using std::ifstream;

void print(const StrVec &svec)
{
	for (auto it : svec)
    {
		cout << it << " " ;
    }
	cout <<endl;
}

StrVec getVec(istream &is)
{
	StrVec svec;
	string s;
	while (is >> s)
    {
		svec.push_back(s);
    }
	return svec;
}

int main()
{
	StrVec sv = {"one", "two", "three"};
	// run the string empty funciton on the first element in sv
	if (!sv[0].empty())
    {
		sv[0] = "None"; // assign a new value to the first string
    }

	// we'll call getVec a couple of times
	// and will read the same file each time
	ifstream in("storyDataFile");
	StrVec svec = getVec(in);
	print(svec);
	in.close();

	cout << endl << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	cout << endl << "assign" << endl;
	StrVec svec3;
	svec3 = svec2;
	print(svec3);

	StrVec v1, v2;
	v1 = v2;                   // v2 is an lvalue; copy assignment

	in.open("storyDataFile");
	v2 = getVec(in);          // getVec(in) is an rvalue; move assignment
	in.close();

	StrVec vec;  // empty StrVec
	string s = "some string or another";
	vec.push_back(s);      // calls push_back(const string&)
	vec.push_back("done"); // calls push_back(string&&)

	// emplace member covered in chpater 16
	s = "the end";
	vec.emplace_back(10, 'c'); // adds cccccccccc as a new last element
	vec.emplace_back(s);  // uses the string copy constructor
	string s1 = "the beginning", s2 = s;
	vec.emplace_back(s1 + s2); // uses the move constructor

    cout << endl << "capacity: " << sv.capacity() << endl;
    cout << "reserve..." << endl;
    sv.reserve(sv.capacity() * 3);
    cout << "new capacity: " << sv.capacity() << endl;
    sv.push_back("four");
    print(sv);

    cout << endl << "size: " << sv.size() << endl;
    cout << "resize 6..." << endl;
    sv.resize(6, "max");
    cout << "new size: " << sv.size() << endl;
    print(sv);
    cout << "resize 2..." << endl;
    sv.resize(2);
    cout << "new size: " << sv.size() << endl;
    print(sv);

	return 0;
}

