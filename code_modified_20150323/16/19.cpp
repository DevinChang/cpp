#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename C>
void print(const C &c)
{
	for (typename C::size_type i = 0; i < c.size(); i++)
    {
		cout << c.at(i) << " " ;
    }
	cout <<endl;
}

int main()
{
	string s = "Hello!";
	print(s);

    vector<int> vi = { 0, 2, 4, 6, 8 };
    print(vi);

	return 0;
}
