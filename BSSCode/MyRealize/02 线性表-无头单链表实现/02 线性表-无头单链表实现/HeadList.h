#ifndef HEADLIST_H_
#define HEADLIST_H_

#include"Common.h"

//定义一个无头节点单链表的 节点
typedef struct Node{
	int data;
	struct Node * pNext;
}NODE;

//定义一个无有头结点的 单链表
typedef struct NoHeadList{
	NODE* head;
}NoHeadList;


//////////////////////////////////////////////////////////
//函数的声明
void Menu();
void NoHeadListInit(NoHeadList* pMyList);//无头单链表的初始化
void NoHeadListPushBack(NoHeadList* pMyList, Elemtype val);//尾插法创建有头结点单链表
static NODE* BuyNode(Elemtype val);//申请节点
void NoHeadListTraverse(NoHeadList* pMyList);//遍历链表
void NoHeadListPushFront(NoHeadList* pMyList, Elemtype val);//头插法创建有头结点单链表
void NoHeadListPopBack(NoHeadList* pMyList);//尾部删
void NoHeadListPopFront(NoHeadList* pMyList);//头部删
NODE*  NoHeadListByFind(NoHeadList* pMyList, Elemtype val);//按值查找
void NoHeadListInsertByVal(NoHeadList* pMyList, Elemtype val);//按值插入
void NoHeadListByDel(NoHeadList* pMyList, Elemtype val);//按值删除
size_t NoHeadListLength(NoHeadList* pMyList);//求链表的长度
void NoHeadListReverse(NoHeadList* pMyList);//反转链表
void NoHeadListSort(NoHeadList* pMyList);//链表的排序
void NoHeadListClear(NoHeadList* pMyList);//链表的清理
void NoHeadListDestroy(NoHeadList* pMyList);//整个链表摧毁
void NoHeadListRemoveAllSameElement(NoHeadList* pMyList, Elemtype val);//按值删除所有相同的元素
#endif /*HEADLIST_H_*/