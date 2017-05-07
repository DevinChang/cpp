#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include "sp_Blob.h"

int main()
{
	Blob<string> b1; // empty Blob
	cout << b1.size() << endl;
	{  // new scope
		Blob<string> b2 = {"a", "an", "the"};
		b1 = b2;  // b1 and b2 share the same elements
		b2.push_back("about");
		cout << b1.size() << " " << b2.size() << endl;
	} // b2 is destroyed, but the elements it points to must not be destroyed
	cout << b1.size() << endl;
	for(size_t i = 0; i < b1.size(); ++i)
    {
		cout << b1.at(i) << " ";
    }
    cout << endl << endl;

    // test make_SP
    vector<string> vs = {"Hello", "World", "!"};
    Blob<string> b3(vs.begin(), vs.end());
    cout << b3.size() << endl;
    for(size_t i = 0; i < b3.size(); ++i)
    {
    	cout << b3.at(i) << " ";
    }
    cout << endl << endl;

    string as[3] = {"This", "is", "end"};
    Blob<string> b4(as, as + 3);
    cout << b4.size() << endl;
    for(size_t i = 0; i < b4.size(); ++i)
    {
    	cout << b4.at(i) << " ";
    }
    cout << endl << endl;

    UP<int> u1(new int(42));
    cout << *u1 << endl;
    UP<int> u2(u1.release());
    cout << *u2 << endl;

	return 0;
}
