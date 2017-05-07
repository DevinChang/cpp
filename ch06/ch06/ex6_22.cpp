#include <iostream>



void swappoint(int *&p1, int *&p2){
	int *tmp = p1;
	p1 = p2;
	p2 = tmp;
}

