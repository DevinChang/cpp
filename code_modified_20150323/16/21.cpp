#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

// function-object class that calls delete on a given pointer
#include "DebugDelete.h"

int main()
{
	double* p = new double;
	// an object that can act like a delete expression
	DebugDelete d("plain pointer");
	d(p); // calls DebugDelete::operator()(double*), which deletes p

	int* ip = new int;
	// calls operator()(int*) on a temporary DebugDelete object
	DebugDelete("plain pointer")(ip);

	// destroying the the object to which upi points
	// instantiates DebugDelete::operator()<int>(int *)
	unique_ptr<int, DebugDelete> upi(new int, DebugDelete());

	// destroying the the object to which ups points
	// instantiates DebugDelete::operator()<string>(string*)
	unique_ptr<string, DebugDelete> ups(new string, DebugDelete());

	// illustrate other types using DebugDelete as their deleter
	shared_ptr<int> sp1(new int(42), DebugDelete("shared_ptr"));

	return 0;
}

