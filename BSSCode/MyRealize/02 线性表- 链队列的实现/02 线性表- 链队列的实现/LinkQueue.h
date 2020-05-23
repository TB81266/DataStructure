#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_
#include"Common.h"

//����һ����ջ�Ľڵ� 
typedef struct LinkQueueNode{
	ElemType data;
	struct LinkQueueNode* pNext;
}LinkQueueNode;

typedef struct LinkQueue{
	struct LinkQueueNode* front;
	struct LinkQueueNode* tail;
}LinkQueue;



//����������
void Menu();
void LinkQueueInit(LinkQueue* pLQueue);
void LinkQueueEnQueue(LinkQueue* pLQueue, ElemType val);//β�巨ʵ�������е����
void LinkQueueDeQueue(LinkQueue* pLQueue);//�����еĳ���
void LinkQueueShow(LinkQueue* pLQueue);//�����еĴ�ӡ
ElemType LinkQueueTop(LinkQueue* pLQueue);//ȡ�������ж�����Ԫ��
void LinkQueueDestory(LinkQueue* pLQueue);//�����еĴݻ�

#endif LINKQUEUE_H_