#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

map<string, vector<string>> buildMap(ifstream &map_file)
{
  // 允许多种转换方法
    map<string, vector<string>> trans_map;   // holds the transformations
    string key;    // a word to transform
  	string value;  // phrase to use instead
  	// read the first word into key and the rest of the line into value
  	while (map_file >> key && getline(map_file, value))
    {
    		if (value.size() > 1) // check that there is a transformation
        {
          	trans_map[key].push_back(value.substr(1)); // skip leading space
        }
    		else
        {
    		  	throw runtime_error("no rule for " + key);
        }
    }
  	return trans_map;
}

const string &transform(const string &s, const map<string, vector<string>> &m)
{
    static default_random_engine e(time(0));   // 随机数引擎，静态变量保持状态
  	// the actual map work; this part is the heart of the program
  	auto map_it = m.find(s);
  	// if this word is in the transformation map
  	if (map_it != m.cend())
    {
  	    // 随机数分布
        uniform_int_distribution<unsigned> u(0, map_it->second.size()-1);
  	   	return map_it->second[u(e)]; // 随机选择一种转换方式
  	}
  	else
    {
  	   	return s;              // otherwise return the original unchanged
    }
}

// first argument is the transformations file;
// second is file to transform
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file); // store the transformations

     // for debugging purposes print the map after its built
    cout << "Here is our transformation map: \n\n";
    for (auto entry : trans_map)
    {
        cout << "key: "   << entry.first << "\tvalue: ";
        for (auto s : entry.second)
        {
            cout << s << ", ";
        }
        cout << endl;
    }
    cout << endl << endl;

    // do the transformation of the given text
    string text;                    // hold each line from the input
    while (getline(input, text))  // read a line of input
    {
        istringstream stream(text); // read each word
        string word;
        bool firstword = true;      // controls whether a space is printed
        while (stream >> word)
        {
            if (firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";  // print a space between words
            }
            // transform returns its first argument or its transformation
            cout << transform(word, trans_map); // print the output
        }
        cout << endl;        // done with this line of input
    }
}

int main(int argc, char **argv)
{
	// open and check both files
    if (argc != 3)
    {
        throw runtime_error("wrong number of arguments");
    }

    ifstream map_file(argv[1]); // open transformation file
    if (!map_file)              // check that open succeeded
    {
        throw runtime_error("no transformation file");
    }

    ifstream input(argv[2]);    // open file of text to transform
    if (!input)                 // check that open succeeded
    {
        throw runtime_error("no input file");
    }

	  word_transform(map_file, input);
    return 0;  // exiting main will automatically close the files
}
