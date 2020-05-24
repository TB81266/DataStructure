#ifndef _TREE_H_
#define _TREE_H_

#include"Common.h"

//����������ڵ�
typedef struct BinTreeNode{
	ElemType data;
	BinTreeNode* leftChild;
	BinTreeNode* rightChild;
}BinTreeNode;

typedef struct BinTree{
	BinTreeNode* root;
}BinTree;


/////////////////////////////////////////////////////////////////////
//��������

//��ʼ��
void BinTreeInit(BinTree* pbt);

//����
void BinTreeCreate(BinTree* bt);
void BitTreeCreate_1(BinTreeNode** bt);
BinTreeNode* BinTreeCreate_2();

//����
void PreOrder(BinTree* bt);
void PreOrder_1(BinTreeNode* t);
void InOrder(BinTree* bt);
void PostOrder(BinTree* bt);
void LevelOrder(BinTree* bt);

#endif /* _TREE_H_ */