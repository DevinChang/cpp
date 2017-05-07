#include <iostream>
#include <bitset>
using namespace std;

int main(int argc, char **argv)
{
    unsigned bp = 2 | (11 << 2) | (1 << 5) | (1 << 8) | (1 << 13) | (1 << 21);
	bitset<32> bv(bp);
	cout << bv << endl;

	bitset<32> bv1;
	bv1.set(1); bv1.set(2); bv1.set(3); bv1.set(5);
	bv1.set(8); bv1.set(13); bv1.set(21);
	cout << bv1 << endl;

	return 0;
}
