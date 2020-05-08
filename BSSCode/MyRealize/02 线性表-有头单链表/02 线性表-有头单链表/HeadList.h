#ifndef HEADLIST_H_
#define HEADLIST_H_

#include"Common.h"

//定义一个有头节点单链表的节点
typedef struct Node{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

//定义一个链表
typedef struct Node* LinkList;
//PNODE LinkList; //第二种定义的方式

//////////////////////////////////////////////////////////
//函数的声明
void Menu();
void LinkListInit(LinkList* pMyList);
void LinkListCreateTail(LinkList* pMyList);//尾插法创建有头结点单链表
void LinkListCreateHead(LinkList* pMyList);//头插法创建有头节点单链表
void TraverseLinkList(LinkList pMyList);//遍历链表(有头尾插法)
bool LinkListIsEmpty(LinkList *pMyList);//判断链表是否为空(有头尾插法)
void InsertLinkList(LinkList *pMyList, int pos, int data);//插入链表的node(有头尾插法)
void LinkListSort(LinkList *pMyList);//链表排序(有头尾插法)
int  LinkListLength(LinkList *pMyList);//求链表的长度(有头尾插法)
void LinkListDestroy(LinkList *pMyList);//销毁链表  释放空间(无头尾插法)
#endif /*HEADLIST_H_*/