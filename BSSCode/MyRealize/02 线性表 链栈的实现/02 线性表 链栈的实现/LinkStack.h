#ifndef LINKSTACK_H_
#define LINKSTACK_H_
#include"Common.h"

//定义一个链栈的节点 
typedef struct LinkStackNode{
	ElemType data;
	struct LinkStackNode* pNext;
}LinkStackNode;

typedef struct LinkStack{
	struct LinkStackNode* pTop;
}LinkStack;



//函数的声明
void Menu();
void LinkStackInit(LinkStack* pLStack);
void LinkStackPush(LinkStack* pLStack, ElemType val);//头插法实现链栈的入栈
void LinkStackPop(LinkStack* pLStack);//链栈的出栈
void LinkStackShow(LinkStack* pLStack);//链栈的打
ElemType LinkStackTop(LinkStack* pLStack);//取出栈顶的元素
void LinkStackDestory(LinkStack* pLStack);//链栈的摧毁
#endif LINKSTACK_H_