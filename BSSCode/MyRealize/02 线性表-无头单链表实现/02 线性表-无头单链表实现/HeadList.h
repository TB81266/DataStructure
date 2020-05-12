#ifndef HEADLIST_H_
#define HEADLIST_H_

#include"Common.h"

//����һ����ͷ�ڵ㵥����� �ڵ�
typedef struct Node{
	int data;
	struct Node * pNext;
}NODE;

//����һ������ͷ���� ������
typedef struct NoHeadList{
	NODE* head;
}NoHeadList;


//////////////////////////////////////////////////////////
//����������
void Menu();
void NoHeadListInit(NoHeadList* pMyList);//��ͷ������ĳ�ʼ��
void NoHeadListPushBack(NoHeadList* pMyList, Elemtype val);//β�巨������ͷ��㵥����
static NODE* BuyNode(Elemtype val);//����ڵ�
void NoHeadListTraverse(NoHeadList* pMyList);//��������
void NoHeadListPushFront(NoHeadList* pMyList, Elemtype val);//ͷ�巨������ͷ��㵥����
void NoHeadListPopBack(NoHeadList* pMyList);//β��ɾ
void NoHeadListPopFront(NoHeadList* pMyList);//ͷ��ɾ
NODE*  NoHeadListByFind(NoHeadList* pMyList, Elemtype val);//��ֵ����
void NoHeadListInsertByVal(NoHeadList* pMyList, Elemtype val);//��ֵ����
void NoHeadListByDel(NoHeadList* pMyList, Elemtype val);//��ֵɾ��
size_t NoHeadListLength(NoHeadList* pMyList);//������ĳ���
void NoHeadListReverse(NoHeadList* pMyList);//��ת����
void NoHeadListSort(NoHeadList* pMyList);//���������
void NoHeadListClear(NoHeadList* pMyList);//���������
void NoHeadListDestroy(NoHeadList* pMyList);//��������ݻ�
void NoHeadListRemoveAllSameElement(NoHeadList* pMyList, Elemtype val);//��ֵɾ��������ͬ��Ԫ��
#endif /*HEADLIST_H_*/