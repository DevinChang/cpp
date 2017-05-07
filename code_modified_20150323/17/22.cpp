#include <iostream>
using std::cin; using std::cout; using std::cerr;
using std::istream; using std::ostream; using std::endl;

#include <sstream>
using std::ostringstream; using std::istringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <regex>
using std::regex; using std::smatch; using std::regex_match;
using std::sregex_iterator;

// members are public by default
struct PersonInfo
{ 
	string name;
	vector<string> phones;
};

// we'll see how to reformat phone numbers in chapter 17
// for now just return the string we're given
string format(const string &s)
{
	return s;
}

bool valid(const smatch& m)
{
	if(m[1].matched)
	{
		// the area code must be followed by a close parenthesis
		// and followed immediately by the rest of the number or a space sequence 
	    return m[3].matched && (m[4].matched == 0 || (m[4].str() != "-" && m[4].str() != "."));
	}
	else
	{
		// then there can't be a close after the area code 
		// the delimiters between the other two components must match
		return !m[3].matched
		       && ((m[4].str() == "-" && m[6].str() == ".") 
					 || (m[4].str() == "." && m[6].str() == ".")
					 || (m[4].str() != "-" && m[4].str() != "."
					 && m[6].str() != "-" && m[6].str() != "."));
	}
}

vector<PersonInfo>
getData(istream &is)
{
	string phone = "(\\()?(\\d{3})(\\))?([-.]|(\\s)*)?(\\d{3})([-.]|(\\s)*)?(\\d{4})";
	regex r(phone);  // a regex to find our pattern
	smatch m;        // a match object to hold the results

	// will hold a line and word from input, respectively
	string line, word;

	// will hold all the records from the input
	vector<PersonInfo> people;

	// read the input a line at a time until end-of-file (or other error)
	while (getline(is, line))
	{       
		PersonInfo info;            // object to hold this record's data
	  	istringstream record(line); // bind record to the line we just read
		record >> info.name;        // read the name
		getline(record, line);
		for (sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it) // match the phone numbers
		{
			if (valid(*it))			  // and check and store them
			{
				info.phones.push_back("V" + it->str());
			}
			else
			{
				info.phones.push_back("I" + it->str());
			}
		}
		people.push_back(info); // append this record to people
	}
	
	return people;
}

ostream& process(ostream &os, vector<PersonInfo> people)
{
	for (const auto &entry : people)    // for each entry in people
	{
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto &nums : entry.phones)  // for each number
		{
			if (nums[0] == 'I')
			{           
				badNums << " " << nums.substr(1) << endl;  // string in badNums
			}
			else
			{
				// ``writes'' to formatted's string
				formatted << " " << format(nums.substr(1)) << endl;
			}
		}
		if (badNums.str().empty())      // there were no bad numbers
		{
			os << entry.name << endl     // print the name 
			   << formatted.str() << endl; // and reformatted numbers 
		}
		else                   // otherwise, print the name and bad numbers
		{
			cerr << "input error: " << entry.name 
			     << " invalid number(s) " << badNums.str() << endl;
		}
	}
	
	return os;
}

int main()
{
	process(cout, getData(cin));
	return 0;
}
