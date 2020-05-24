#include<stdio.h>
#include<stdlib.h>
typedef  int ElemType;

typedef struct Node{
	ElemType data;
	struct Node* left;
	struct Node* right;
}NODE;


void PreOrder(NODE* node){
	if (node != NULL){
		printf("%d ", node->data);

		PreOrder(node->left);
		PreOrder(node->right);
	}
}

void InOrder(NODE* node){
	if (node != NULL){
		InOrder(node->left);
		printf("%d ", node->data);
		InOrder(node->right);
	}
}

void PostOrder(NODE* node){
	if (node != NULL){
		PostOrder(node->left);
		PostOrder(node->right);
		printf("%d ", node->data);
	}
}
int main(){
	NODE n1;
	NODE n2;
	NODE n3;
	NODE n4;
	NODE n5;

	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n5.data = 5;

	n1.left = &n2;
	n1.right = &n5;
	n2.left = &n3;
	n2.right = &n4;
	n3.left = n3.right = NULL;
	n4.left = n4.right = NULL;
	n5.left = n5.right = NULL;

	PreOrder(&n1);
	printf("\n");
	InOrder(&n1);
	printf("\n");
	PostOrder(&n1);
	printf("\n");
	return 0;
}