#include <iostream>
using std::cerr; using std::endl;

#include <fstream>
using std::fstream;

#include <string>
using std::string;

#include <cstdlib> // for EXIT_FAILURE

int main(int argc, char *argv[])
{
    // open for input and output and preposition file pointers to end-of-file
	// file mode argument
    fstream inOut(argv[1], fstream::ate | fstream::in | fstream::out);
    if (!inOut)
    {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE; // EXIT_FAILURE
    }

    // inOut is opened in ate mode, so it starts out positioned at the end
    auto end_mark = inOut.tellg();// remember original end-of-file position
    inOut.seekg(0, fstream::beg); // reposition to the start of the file
    size_t cnt = 0;               // accumulator for the byte count
    string line;                  // hold each line of input

    // while we haven't hit an error and are still reading the original data
    while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) // and can get another line of input
    {
        std::cout << line << ":" << line.size() << std::endl;
        cnt += line.size() + 1;       // add 1 to account for the newline
		auto mark = inOut.tellg();    // remember the read position
		std::cout << mark << endl;
        inOut.seekp(0, fstream::end); // set the write marker to the end
        inOut << cnt;                 // write the accumulated length
        // print a separator if this is not the last line
        if (mark != end_mark)
        {
            inOut << " ";
        }
        inOut.seekg(mark);            // restore the read position
    }
    inOut.seekp(0, fstream::end);     // seek to the end
    inOut << "\n";                    // write a newline at end-of-file

    return 0;
}
