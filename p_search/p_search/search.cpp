#include "stdafx.h"

int main1()
{
	int buf[200];
	int n;
	while (scanf_s("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			//debug
			scanf_s("%d,", &buf[i]);
		}
		int x, ans = -1;
		scanf_s("%d", &x);
		for (int i = 0; i < n; i++)
		{
			if (x == buf[i])
			{
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	
	system("pause");
	return 0;
}