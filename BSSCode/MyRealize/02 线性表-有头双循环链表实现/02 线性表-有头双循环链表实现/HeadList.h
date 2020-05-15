#ifndef HEADLIST_H_
#define HEADLIST_H_

#include"Common.h"

//������ͷ�ڵ��ѭ��˫����Ľڵ�
typedef struct Node{
	int data;
	struct Node * pNext;
	struct Node * pLast;
}NODE;

//������ͷ�ڵ��ѭ��˫����
typedef struct DoubleCyclicList{
	NODE* head;
}DoubleCyclicList;


//////////////////////////////////////////////////////////
//����������
void Menu();
static NODE* BuyNode(Elemtype val);//����ڵ�
void DoubleCyclicListInit(DoubleCyclicList* pMyList);//��ͷ˫��ѭ������ĳ�ʼ��
void DoubleCyclicListPushBack(DoubleCyclicList* pMyList, Elemtype val);//β�巨 ��������
void DoubleCyclicListShow(DoubleCyclicList* pMyList);//��ͷ˫��ѭ�������show
void DoubleCyclicListPushFront(DoubleCyclicList* pMyList, Elemtype val);//ͷ�巨 ��������
void DoubleCyclicListPopBack(DoubleCyclicList* pMyList);//��ͷ˫��ѭ������β��ɾ��
void DoubleCyclicListPopFront(DoubleCyclicList* pMyList);//��ͷ˫��ѭ������ͷ��ɾ��
NODE*  DoubleCyclicListByFind(DoubleCyclicList* pMyList, Elemtype val);//��ֵ����
size_t DoubleCyclicListLength(DoubleCyclicList* pMyList);//������ĳ���
void DoubleCyclicListClear(DoubleCyclicList* pMyList);//���������
void DoubleCyclicListDestroy(DoubleCyclicList* pMyList);//���������
void DoubleCyclicListByDel(DoubleCyclicList* pMyList, Elemtype val);//��ֵɾ��
void DoubleCyclicListByVal(DoubleCyclicList* pMyList, Elemtype val);//��ֵ����
void DoubleCyclicLisReverse(DoubleCyclicList* pMyList);//��ת����
void DoubleCyclicLisSort(DoubleCyclicList* pMyList);//���������

#endif /*HEADLIST_H_*/