#include <fstream>
#include <istream>
#include "exm_7_2._11_21.h"

int main3(int argc, char **argv){
	std::ifstream input(argv[1]);
	//8_8 add ofstream::app
	std::ofstream output(argv[2], std::ofstream::app);

	Sales_data total;
	if (read(input, total)){
		Sales_data trans;
		while (read(input, trans)){	
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else{
				print(output, total) << std::endl;
				total = trans;
			}
		}
		print(output, total) << std::endl;
	}
	else
		std::cerr << "No data!" << std::endl;

	system("pause");
	return 0;
}