#ifndef CYCLEQUEUE_H_
#define CYCLEQUEUE_H_
#include"Common.h"

#define CYCLEQUEUE_DEFAULT_SZIE 8

typedef struct CycleQueue{
	ElemType * base;
	int       capacity;
	int       front;
	int       tail;
}CycleQueue;


//����������
void Menu();
void CycleQueueInit(CycleQueue* pCQueue);//ѭ�����еĳ�ʼ��
bool CycleQueueIsFull(CycleQueue* pCQueue);
bool CycleQueueIsEmpty(CycleQueue* pCQueue);
void CycleQueueEnQueue(CycleQueue* pCQueue, ElemType val);//�����
void CycleQueueDeQueue(CycleQueue* pCQueue);//������
void CycleQueueShow(CycleQueue* pCQueue);////ѭ�����еĴ�ӡ
ElemType CycleQueueTop(CycleQueue* pCQueue);////ȡѭ�����еĶ�Ԫ��
void CycleQueueClear(CycleQueue* pCQueue);////ѭ�����е�����
void CycleQueueDestroy(CycleQueue* pCQueue);//ѭ�����е�����

#endif CYCLEQUEUE_H_