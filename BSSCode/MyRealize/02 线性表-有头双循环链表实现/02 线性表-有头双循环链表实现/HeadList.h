#ifndef HEADLIST_H_
#define HEADLIST_H_

#include"Common.h"

//定义有头节点的循环双链表的节点
typedef struct Node{
	int data;
	struct Node * pNext;
	struct Node * pLast;
}NODE;

//定义有头节点的循环双链表
typedef struct DoubleCyclicList{
	NODE* head;
}DoubleCyclicList;


//////////////////////////////////////////////////////////
//函数的声明
void Menu();
static NODE* BuyNode(Elemtype val);//申请节点
void DoubleCyclicListInit(DoubleCyclicList* pMyList);//有头双向循环链表的初始化
void DoubleCyclicListPushBack(DoubleCyclicList* pMyList, Elemtype val);//尾插法 插入数据
void DoubleCyclicListShow(DoubleCyclicList* pMyList);//有头双向循环链表的show
void DoubleCyclicListPushFront(DoubleCyclicList* pMyList, Elemtype val);//头插法 插入数据
void DoubleCyclicListPopBack(DoubleCyclicList* pMyList);//有头双向循环链表尾部删除
void DoubleCyclicListPopFront(DoubleCyclicList* pMyList);//有头双向循环链表头部删除
NODE*  DoubleCyclicListByFind(DoubleCyclicList* pMyList, Elemtype val);//按值查找
size_t DoubleCyclicListLength(DoubleCyclicList* pMyList);//求链表的长度
void DoubleCyclicListClear(DoubleCyclicList* pMyList);//链表的清理
void DoubleCyclicListDestroy(DoubleCyclicList* pMyList);//链表的销毁
void DoubleCyclicListByDel(DoubleCyclicList* pMyList, Elemtype val);//按值删除
void DoubleCyclicListByVal(DoubleCyclicList* pMyList, Elemtype val);//按值插入
void DoubleCyclicLisReverse(DoubleCyclicList* pMyList);//反转链表
void DoubleCyclicLisSort(DoubleCyclicList* pMyList);//链表的排序

#endif /*HEADLIST_H_*/