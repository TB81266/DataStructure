#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct BTNode{
	char data;
	struct BTNode* pLchild;//p��ָ�� L ���� child �Ǻ���
	struct BTNode* pRchild;
}BTNODE ,*PBTNODE;

PBTNODE CreateBTree(){
	PBTNODE pA = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pB = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pC = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pD = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pE = (PBTNODE)malloc(sizeof(BTNODE));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;
	
	return pA;
}

//�������
void PreTraverseBTree(PBTNODE pT){
	//�ȷ��ʸ��ڵ� ��������������� ����������������
	if (pT != NULL){
		printf("%c\n", pT->data);
		if (pT->pLchild != NULL){
			PreTraverseBTree(pT->pLchild);
		}
		if (pT->pRchild != NULL){
			PreTraverseBTree(pT->pRchild);
		}
	}
}

void InTraverseBTree(PBTNODE pT){
	if (pT != NULL){
		if (pT->pLchild != NULL){
			InTraverseBTree(pT->pLchild);
		}
		printf("%c\n", pT->data);
		if (pT->pRchild != NULL){
			InTraverseBTree(pT->pRchild);
		}
	}
}

void PostTraverseBTree(PBTNODE pT){
	if (pT != NULL){
		if (pT->pLchild != NULL){
			PostTraverseBTree(pT->pLchild);
		}
		if (pT->pRchild != NULL){
			PostTraverseBTree(pT->pRchild);
		}
		printf("%c\n", pT->data);
	}
}
int main(){
	PBTNODE pT = CreateBTree();
	PreTraverseBTree(pT);//�������
	InTraverseBTree(pT);//�������
	PostTraverseBTree(pT);//�������
	return 0;
}