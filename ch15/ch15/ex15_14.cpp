#include "ex15_13.h"
#include "ex15_20.h"


int main4() {
	base bobj;
	base *bp1 = &bobj;
	base &br1 = bobj;
	derived dobj;
	base *bp2 = &dobj;
	base &br2 = dobj;

	bobj.print(std::cout);
	dobj.print(std::cout);
	bp1->name();
	bp2->name();
	br1.print(std::cout);
	br2.print(std::cout);

	system("pause");
	return 0;
}