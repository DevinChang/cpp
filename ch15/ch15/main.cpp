#include "ex15_35.h"
#include <fstream>


int main() {
	std::ifstream ifile("file.txt");
	TextQuery3 tQuery(ifile);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << q.eval(tQuery);
	

	system("pause");
	return 0;
}