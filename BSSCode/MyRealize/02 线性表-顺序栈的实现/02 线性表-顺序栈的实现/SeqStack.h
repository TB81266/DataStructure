#ifndef SEQSTACK_H_
#define SEQSTACK_H_
#include"Common.h"

#define SEQSTACK_DEFAULT_SZIE 8

typedef struct SeqStack{
	ElemType * base;
	size_t    capacity;
	int       top;
}SeqStack;



//����������
void Menu();
static bool IncSeqStackCapacity(SeqStack* pStack);//�Զ�����
bool SeqStackIsFull(SeqStack* pStack);
bool SeqStackIsEmpty(SeqStack* pStack);
void SeqStackInit(SeqStack* pStack);//˳��ջ�ĳ�ʼ��
void SeqStackPushBack(SeqStack* pStack, ElemType val);//��ջ
void SeqStackPop(SeqStack* pStack);//��ջ
void SeqStackShow(SeqStack* pStack);//˳��ջ�Ĵ�ӡ
ElemType SeqStackTop(SeqStack* pStack);//ȡ˳��ջ��ջ��Ԫ�� SeqStackPeek();Ҳ��ʹ������������Ƶ�

void SeqStackClear(SeqStack* pStack);//˳��ջ������
void SeqStackDestroy(SeqStack* pStack);//˳��ջ������

#endif SEQSTACK_H_