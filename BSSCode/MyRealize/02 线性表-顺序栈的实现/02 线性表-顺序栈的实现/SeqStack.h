#ifndef SEQSTACK_H_
#define SEQSTACK_H_
#include"Common.h"

#define SEQSTACK_DEFAULT_SZIE 8

typedef struct SeqStack{
	ElemType * base;
	size_t    capacity;
	int       top;
}SeqStack;



//函数的声明
void Menu();
static bool IncSeqStackCapacity(SeqStack* pStack);//自动扩容
bool SeqStackIsFull(SeqStack* pStack);
bool SeqStackIsEmpty(SeqStack* pStack);
void SeqStackInit(SeqStack* pStack);//顺序栈的初始化
void SeqStackPushBack(SeqStack* pStack, ElemType val);//入栈
void SeqStackPop(SeqStack* pStack);//出栈
void SeqStackShow(SeqStack* pStack);//顺序栈的打印
ElemType SeqStackTop(SeqStack* pStack);//取顺序栈的栈顶元素 SeqStackPeek();也有使用这个函数名称的

void SeqStackClear(SeqStack* pStack);//顺序栈的清理
void SeqStackDestroy(SeqStack* pStack);//顺序栈的销毁

#endif SEQSTACK_H_