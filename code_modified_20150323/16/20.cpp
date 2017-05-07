#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <typename C>
void print(const C &c)
{
	for (auto i = c.begin(); i != c.end(); i++)
    {
		cout << *i << " " ;
    }
	cout <<endl;
}

int main()
{
	string s = "Hello!";
	print(s);

    vector<int> vi = { 0, 2, 4, 6, 8 };
    print(vi);

    list<string> ls = { "Hel", "lo", "!" };
    print(ls);

	return 0;
}
