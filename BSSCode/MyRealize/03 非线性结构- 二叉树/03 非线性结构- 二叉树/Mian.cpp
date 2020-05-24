#include"tree.h"

int main(){
	system("title 二叉树的实现");
	system("color 0B");
	system("date/T");
	system("TIME/T");
	printf("**************************\n");

	BinTree bt;//定义一个二叉树

	BinTreeInit(&bt);//初始化二叉树
	BinTreeCreate(&bt);
	printf("VLR:  ");
	PreOrder(&bt);
	printf("\n");
	 
	return 0;
}