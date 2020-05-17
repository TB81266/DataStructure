#ifndef LINKSTACK_H_
#define LINKSTACK_H_
#include"Common.h"

//����һ����ջ�Ľڵ� 
typedef struct LinkStackNode{
	ElemType data;
	struct LinkStackNode* pNext;
}LinkStackNode;

typedef struct LinkStack{
	struct LinkStackNode* pTop;
}LinkStack;



//����������
void Menu();
void LinkStackInit(LinkStack* pLStack);
void LinkStackPush(LinkStack* pLStack, ElemType val);//ͷ�巨ʵ����ջ����ջ
void LinkStackPop(LinkStack* pLStack);//��ջ�ĳ�ջ
void LinkStackShow(LinkStack* pLStack);//��ջ�Ĵ�
ElemType LinkStackTop(LinkStack* pLStack);//ȡ��ջ����Ԫ��
void LinkStackDestory(LinkStack* pLStack);//��ջ�Ĵݻ�
#endif LINKSTACK_H_