#include "ex15_35.h"
#include <fstream>


int main() {
	std::ifstream ifile("file.txt");
	TextQuery3 tQuery(ifile);
	chapter15::Query q = chapter15::Query("fiery") & chapter15::Query("bird") | chapter15::Query("wind");
	std::cout << q.eval(tQuery);
	

	system("pause");
	return 0;
}