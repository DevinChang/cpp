#include "stdafx.h"
using namespace std;

stack<int> s;
char cstr[110];
char ans[110];

int main1()
{
	while (scanf("%s", cstr) != EOF)
	{
		int i;
		for (i = 0; cstr[i] != 0; i++)
		{
			if (cstr[i] == '(')
			{
				s.push(i);
				ans[i] = ' ';
			}
			else if (cstr[i] == ')'){
				if (s.empty() == false)
				{
					s.pop();
					ans[i] = ' ';
				}
				else
					ans[i] = '?';
			}
			else
				ans[i] = ' ';
		}
		while (!s.empty())
		{
			ans[s.top()] = '$';
			s.pop();
		}
		ans[i] = 0;
		puts(cstr);
		puts(ans);
	}
	system("pause");
	return 0;
}