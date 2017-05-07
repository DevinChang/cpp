#include "Query.h"
#include "TextQuery.h"

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin;

#include <fstream>
using std::ifstream;

#include <stdexcept>
using std::runtime_error;

// these functions are declared in Query.h
TextQuery get_file(int argc, char **argv)
{
    // get a file to read from which user will query words
	ifstream infile;
	if (argc == 2)
    	infile.open(argv[1]);
    if (!infile) {
        throw runtime_error("No input file!");
    }

    return TextQuery(infile);  // builds query map
}

bool get_word(string &s1)
{
    cout << "enter a word to search for, or q to quit, or h to history: ";
    cin >> s1;
    if (!cin || s1 == "q") return false;
    else return true;
}

bool get_words(string &s1, string &s2)
{

    // iterate with the user: prompt for a word to find and print results
    cout << "enter two words to search for, or q to quit: ";
    cin  >> s1;

    // stop if hit eof on input or a "q" is entered
    if (!cin || s1 == "q") return false;
    cin >> s2;
    return true;
}

