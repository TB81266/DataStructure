#include"tree.h"

int main(){
	system("title ��������ʵ��");
	system("color 0B");
	system("date/T");
	system("TIME/T");
	printf("**************************\n");

	BinTree bt;//����һ��������

	BinTreeInit(&bt);//��ʼ��������
	BinTreeCreate(&bt);
	printf("VLR:  ");
	PreOrder(&bt);
	printf("\n");
	 
	return 0;
}