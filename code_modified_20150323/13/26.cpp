#include <iostream>
#include "my_StrBlob.h"
using namespace std;

int main(int argc, char **argv)
{
	StrBlob b1;
	{
	    StrBlob b2 = { "a", "an", "the" };
	    b1 = b2;
	    b2.push_back("about");
      	cout << "b2��СΪ" << b2.size() << endl;
      	cout << "b2��βԪ��Ϊ" << b2.front() << " " << b2.back() << endl;
	}
	cout << "b1��СΪ" << b1.size() << endl;
	cout << "b1��βԪ��Ϊ" << b1.front() << " " << b1.back() << endl;

	StrBlob b3 = b1;
	b3.push_back("next");
	cout << "b3��СΪ" << b3.size() << endl;
	cout << "b3��βԪ��Ϊ" << b3.front() << " " << b3.back() << endl;

	cout << "b1ȫ��Ԫ�أ�" << endl;
	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
	{
		cout << it.deref() << endl;
	}

	return 0;
}
