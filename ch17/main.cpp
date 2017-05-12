#include "ex17_4_5.h"
#include <bitset>
#include "ex17_11.h"


int main2() {
	//ex17_10
	std::cout << "ex17_10: " << std::endl;
	std::vector<int> iv{ 1, 2, 3, 5, 8, 13, 21 };
	std::bitset<32> bit;
	for (auto p : iv)
		bit.set(p);

	std::cout << bit << std::endl;

	//ex17_11
	std::cout << "ex17_11: " << std::endl;
	std::string str("1011001001");
	Quiz<10> solution(str);
	std::string answer1("1000110110"), answer2("1111000011");
	Quiz<10> stu1(answer1), stu2(answer2);
	std::cout << "the correct solution: " << solution.get_solusion() << std::endl;
	std::cout << "student1's grade: " << grade(stu1, solution) << std::endl
		<< "student2's grade: " << grade(stu2, solution) << std::endl;
	system("pause");
	return 0;
}