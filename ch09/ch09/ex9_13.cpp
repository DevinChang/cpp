#include <iostream>
#include <vector>
#include <list>


int main2(){
	std::vector<double> vec = { 1.0, 2.1, 4.1, 3.4, 7.9 };
	//9_12 Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.
	//Answer:
	//The constructor that takes another container as an argument (excepting array) assumes the container type and element type of both 
	//containers are identical. It will also copy all the elements of the received container into the new one:
	//	list<int> numbers = { 1, 2, 3, 4, 5 };
	//	list<int> numbers2(numbers);        // ok, numbers2 has the same elements as numbers
	//	vector<int> numbers3(numbers);      // error: no matching function for call...
	//	list<double> numbers4(numbers);     // error: no matching function for call...
	//The constructor that takes two iterators as arguments does not require the container types to be identical.
	//Moreover, the element types in the new and original containers can differ as long as it is possible to 
	//convert the elements we¡¯re copying to the element type of the container we are initializing.It will also copy only 
	//the object delimited by the received iterators.
	//	list<int> numbers = { 1, 2, 3, 4, 5 };
	//	list<int> numbers2(numbers.begin(), numbers.end);        // ok, numbers2 has the same elements as numbers
	//	vector<int> numbers3(numbers.begin(), --numbers.end());  // ok, numbers3 is { 1, 2, 3, 4 }
	//	list<double> numbers4(++numbers.beg(), --numbers.end());        // ok, numbers4 is { 2, 3, 4 }
	//	forward_list<float> numbers5(numbers.begin(), numbers.end());   // ok, number5 is { 1, 2, 3, 4, 5 }
	std::list<int> lst(vec.begin(), vec.end());
	for (auto &p : lst){
		std::cout << p << std::endl;
	}
	system("pause");
	return 0;
}