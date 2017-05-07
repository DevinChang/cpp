#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class StrLenBetween
{
public:
	StrLenBetween(int minLen, int maxLen) : minLen(minLen), maxLen(maxLen) {}
	bool operator()(const string &str)
	{
		return str.length() >= minLen && str.length() <= maxLen;
	}

private:
	int minLen;
	int maxLen;
};

class StrNotShorterThan
{
public:
	StrNotShorterThan(int len) : minLen(len) {}
	bool operator()(const string &str) { return str.length() >= minLen; }

private:
	int minLen;
};

extern readStr(istream &is, vector<string> &vec);  // 使用上一题目中的函数

int main()
{
	vector<string> vec;
	readStr(cin, vec);

	StrLenBetween slenBetween(1, 9);
	StrNotShorterThan sNotShorterThan(10);
	cout << "len 1~9 : " << count_if(vec.begin(), vec.end(), slenBetween) << endl;
	cout << "len >= 10 : " << count_if(vec.begin(), vec.end(), sNotShorterThan) << endl;

	return 0;
}
