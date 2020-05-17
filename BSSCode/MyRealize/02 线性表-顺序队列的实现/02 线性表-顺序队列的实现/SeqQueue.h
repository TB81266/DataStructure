#ifndef SEQQUEUE_H_
#define SEQQUEUE_H_
#include"Common.h"

#define SEQQUEUE_DEFAULT_SZIE 8

typedef struct SeqQueue{
	ElemType * base;
	int       capacity;
	int       front;
	int       tail;
}SeqQueue;


//����������
void Menu();
static bool IncSeqQueueCapacity(SeqQueue* pSQueue);//�Զ�����
bool SeqQueueIsFull(SeqQueue* pSQueue);
bool SeqQueueIsEmpty(SeqQueue* pSQueue);
void SeqQueueInit(SeqQueue* pSQueue);//˳����еĳ�ʼ��
void SeqQueueEnQueue(SeqQueue* pSQueue, ElemType val);//��ջ
void SeqQueueDeQueue(SeqQueue* SeqQueue);//��ջ
void SeqQueueShow(SeqQueue* pSQueue);//˳��ջ�Ĵ�ӡ
ElemType SeqQueueTop(SeqQueue* pSQueue);//ȡ˳��ջ��ջ��Ԫ�� SeqStackPeek();Ҳ��ʹ������������Ƶ�

void SeqQueueClear(SeqQueue* pSQueue);//˳��ջ������
void SeqQueueDestroy(SeqQueue* pSQueue);//˳��ջ������

#endif SEQQUEUE_H_