#include <iostream>
using namespace std;

int biger(int a, const int *b){
	return a < *b ? *b : a;
}



