#ifndef _TREE_H_
#define _TREE_H_

#include"Common.h"

//定义二叉树节点
typedef struct BinTreeNode{
	ElemType data;
	BinTreeNode* leftChild;
	BinTreeNode* rightChild;
}BinTreeNode;

typedef struct BinTree{
	BinTreeNode* root;
}BinTree;


/////////////////////////////////////////////////////////////////////
//函数声明

//初始化
void BinTreeInit(BinTree* pbt);

//创建
void BinTreeCreate(BinTree* bt);
void BitTreeCreate_1(BinTreeNode** bt);
BinTreeNode* BinTreeCreate_2();

//遍历
void PreOrder(BinTree* bt);
void PreOrder_1(BinTreeNode* t);
void InOrder(BinTree* bt);
void PostOrder(BinTree* bt);
void LevelOrder(BinTree* bt);

#endif /* _TREE_H_ */