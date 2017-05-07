#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>


int main1(){
	//int a, b;
	//while (scanf("%d%d", &a, &b) != EOF){
	//	int buf1[20], buf2[20];
	//	int size1 = 0, size2 = 0;
	//	while (a != 0){
	//		buf1[size1++] = a % 10;
	//		a /= 10;
	//	}
	//	while (b != 0){
	//		buf2[size2++] = b % 10;
	//		b /= 10;
	//	}
	//	int ans = 0;
	//	for (int i = 0; i < size1; i++){
	//		for (int j = 0; j < size2; j++)
	//			ans += buf1[i] * buf2[j];
	//	}
	//	printf("%d", ans);
	//}

	//method2
	char a[20], b[20];
	while (scanf("%s%s", a, b) != EOF){
		int ans = 0;
		for (int i = 0; a[i] != 0; i++){
			for (int j = 0; b[j] != 0; j++)
				ans += (a[i] - '0') * (b[j] - '0');
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}