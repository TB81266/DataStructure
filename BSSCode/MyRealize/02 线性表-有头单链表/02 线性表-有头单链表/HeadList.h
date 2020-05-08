#ifndef HEADLIST_H_
#define HEADLIST_H_

#include"Common.h"

//����һ����ͷ�ڵ㵥����Ľڵ�
typedef struct Node{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

//����һ������
typedef struct Node* LinkList;
//PNODE LinkList; //�ڶ��ֶ���ķ�ʽ

//////////////////////////////////////////////////////////
//����������
void Menu();
void LinkListInit(LinkList* pMyList);
void LinkListCreateTail(LinkList* pMyList);//β�巨������ͷ��㵥����
void LinkListCreateHead(LinkList* pMyList);//ͷ�巨������ͷ�ڵ㵥����
void TraverseLinkList(LinkList pMyList);//��������(��ͷβ�巨)
bool LinkListIsEmpty(LinkList *pMyList);//�ж������Ƿ�Ϊ��(��ͷβ�巨)
void InsertLinkList(LinkList *pMyList, int pos, int data);//���������node(��ͷβ�巨)
void LinkListSort(LinkList *pMyList);//��������(��ͷβ�巨)
int  LinkListLength(LinkList *pMyList);//������ĳ���(��ͷβ�巨)
void LinkListDestroy(LinkList *pMyList);//��������  �ͷſռ�(��ͷβ�巨)
#endif /*HEADLIST_H_*/