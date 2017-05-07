#include <vector>
#include <algorithm>
using namespace std;

class IntCompare
{
public:
	IntCompare(int v) : val(v) {}
	bool operator()(int v) { return val == v; }
private:
	int val;
};

int main()
{
	vector<int> vec = {1, 2, 3, 2, 1};
	const int oldValue = 2;
	const int newValue = 200;
	IntCompare icmp(oldValue);
	std::replace_if(vec.begin(), vec.end(), icmp, newValue);
	
	return 0;
}
