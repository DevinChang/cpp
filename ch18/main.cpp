#include "ex7_2_11_21.h"





int main() {
	std::cout << "ex18_9: " << std::endl;
	Sales_data item1, item2, sum;
	while (std::cin >> item1 >> item2) {
		try {
			sum = item1 + item2;
		}
		catch (const isbn_mismatch &e) {
			std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
		}
	}


	system("pause");
	return 0;
}