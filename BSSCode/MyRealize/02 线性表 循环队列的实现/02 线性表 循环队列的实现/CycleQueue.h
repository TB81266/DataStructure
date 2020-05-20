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


//函数的声明
void Menu();
void CycleQueueInit(CycleQueue* pCQueue);//循环对列的初始化
bool CycleQueueIsFull(CycleQueue* pCQueue);
bool CycleQueueIsEmpty(CycleQueue* pCQueue);
void CycleQueueEnQueue(CycleQueue* pCQueue, ElemType val);//入队列
void CycleQueueDeQueue(CycleQueue* pCQueue);//出队列
void CycleQueueShow(CycleQueue* pCQueue);////循环队列的打印
ElemType CycleQueueTop(CycleQueue* pCQueue);////取循环对列的顶元素
void CycleQueueClear(CycleQueue* pCQueue);////循环对列的清理
void CycleQueueDestroy(CycleQueue* pCQueue);//循环对列的销毁

#endif CYCLEQUEUE_H_