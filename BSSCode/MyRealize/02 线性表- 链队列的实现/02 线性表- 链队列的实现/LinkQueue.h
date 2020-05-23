#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_
#include"Common.h"

//定义一个链栈的节点 
typedef struct LinkQueueNode{
	ElemType data;
	struct LinkQueueNode* pNext;
}LinkQueueNode;

typedef struct LinkQueue{
	struct LinkQueueNode* front;
	struct LinkQueueNode* tail;
}LinkQueue;



//函数的声明
void Menu();
void LinkQueueInit(LinkQueue* pLQueue);
void LinkQueueEnQueue(LinkQueue* pLQueue, ElemType val);//尾插法实现链对列的入队
void LinkQueueDeQueue(LinkQueue* pLQueue);//链队列的出队
void LinkQueueShow(LinkQueue* pLQueue);//链队列的打印
ElemType LinkQueueTop(LinkQueue* pLQueue);//取出链队列顶部的元素
void LinkQueueDestory(LinkQueue* pLQueue);//链队列的摧毁

#endif LINKQUEUE_H_