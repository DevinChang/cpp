//#include "stdafx.h"


//struct Node{
//	Node *lchild;
//	Node *rchild;
//	char c;
//}Tree[110];

//int loc;
//char str1[30], str2[30];
////Notice:静态分配节点内存
//Node *Create(){
//	Tree[loc].lchild = Tree[loc].rchild = NULL;
//	return &Tree[loc++];
//}
//
//void PostOrder(Node *T)
//{
//	if (T->lchild != NULL)
//		PostOrder(T->lchild);
//	if (T->rchild != NULL)
//		PostOrder(T->rchild);
//	printf("%c", T->c);
//}
//
//Node *Build(int s1, int e1, int s2, int e2){
//	Node *ret = Create();
//	ret->c = str1[s1];
//	int rootindex = 0;
//	for (int i = s2; i <= e2; i++){
//		if (str2[i] == str1[s1]){
//			rootindex = i;
//			break;
//		}
//		
//	}
//	if (rootindex != s2){
//		ret->lchild = Build(s1 + 1, s1 + (rootindex - s2), s2, rootindex - 1);
//	}
//	if (rootindex != e2){
//		ret->rchild = Build(s1 + (rootindex - s2) + 1, e1, rootindex + 1, e2);
//	}
//	return ret;
//}

//int main1(){
//	while (scanf("%s", str1) != EOF){
//		scanf("%s", str2);
//		loc = 0;
//		int L1 = strlen(str1);
//		int L2 = strlen(str2);
//		Node *T = Build(0, L1 - 1, 0, L2 - 1);
//		PostOrder(T);
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}