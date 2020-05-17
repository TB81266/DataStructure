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


//函数的声明
void Menu();
static bool IncSeqQueueCapacity(SeqQueue* pSQueue);//自动扩容
bool SeqQueueIsFull(SeqQueue* pSQueue);
bool SeqQueueIsEmpty(SeqQueue* pSQueue);
void SeqQueueInit(SeqQueue* pSQueue);//顺序队列的初始化
void SeqQueueEnQueue(SeqQueue* pSQueue, ElemType val);//入栈
void SeqQueueDeQueue(SeqQueue* SeqQueue);//出栈
void SeqQueueShow(SeqQueue* pSQueue);//顺序栈的打印
ElemType SeqQueueTop(SeqQueue* pSQueue);//取顺序栈的栈顶元素 SeqStackPeek();也有使用这个函数名称的

void SeqQueueClear(SeqQueue* pSQueue);//顺序栈的清理
void SeqQueueDestroy(SeqQueue* pSQueue);//顺序栈的销毁

#endif SEQQUEUE_H_