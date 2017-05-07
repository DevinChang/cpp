#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main1()
{
	int h;
	while (scanf("%d", &h) != EOF)
	{
		int maxline = h + (h - 1) * 2;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= maxline; j++)
			{
				if (j < maxline - h - (i - 1) * 2 + 1)
					printf(" ");
				else
					printf("*");
			}
			printf("\n");  
		}
	}
	system("pause");
	return 0;
}

int main()
{
	int outPutBuf[82][82];
	char a, b;
	int n;
	bool firstCase = true;
	while (scanf("%d %c %c", &n, &a, &b) == 3)
	{
		if (firstCase == true)
			firstCase = false;
		else
			printf("\n");
		for (int i = 1, j = 1; i <= n; i += 2, j++)
		{
			int x = n / 2 + 1, y = x;
			x -= j - 1;
			y -= j - 1;
			char c = j % 2 == 1 ? a : b;
			for (int k = 1; k <= i; k++)
			{
				outPutBuf[x + k - 1][y] = c;
				outPutBuf[x][y + k - 1] = c;
				outPutBuf[x + i - 1][y + k - 1] = c;
				outPutBuf[x + k - 1][y + i - 1] = c;
			}
		}
		if (n != 1)
		{
			outPutBuf[1][1] = ' ';
			outPutBuf[n][1] = ' ';
			outPutBuf[1][n] = ' ';
			outPutBuf[n][n] = ' ';
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%c", outPutBuf[i][j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}