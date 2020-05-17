#include"LinkStack.h"


//函数接口的实现
////////////////////////////////////////
void Menu(){
	printf("**********************************************************\n");
	printf("[1] LinkStackPush             [2] LinkStackPop           *\n");
	printf("[3] LinkStackShow             [4] LinkStackTop           *\n");
	printf("**********************************************************\n");
}

void LinkStackInit(LinkStack* pLStack){
	assert(pLStack != NULL);
	pLStack->pTop = NULL;
}

//头插法实现链栈的入栈
void LinkStackPush(LinkStack* pLStack, ElemType val){
	assert(pLStack != NULL);
	LinkStackNode* pNew = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(pNew != NULL);
	pNew->data = val;
	pNew->pNext = pLStack->pTop;
	pLStack->pTop = pNew;
}

//链栈的出栈
void LinkStackPop(LinkStack* pLStack){
	assert(pLStack != NULL);
	LinkStackNode* pNew = pLStack->pTop;
	pLStack->pTop = pNew->pNext;
	free(pNew);
	pNew = NULL;
}

//链栈的打印
void LinkStackShow(LinkStack* pLStack){
	assert(pLStack != NULL);
	LinkStackNode* pNew = pLStack->pTop;
	while (pNew != NULL){
		printf("%d ", pNew->data);
		pNew = pNew->pNext;
	}
	printf("\n");
}

//取出栈顶的元素
ElemType LinkStackTop(LinkStack* pLStack){
	assert(pLStack != NULL);
	if (pLStack->pTop == NULL){
		printf("链栈W为空！\n");
		return NULL;
	}
	else{
		return pLStack->pTop->data;
	}
}

void LinkStackDestory(LinkStack* pLStack){
	assert(pLStack != NULL);
	LinkStackNode* pNew = pLStack->pTop;
	while (pLStack->pTop != NULL){
		pLStack->pTop = pNew->pNext;
		free(pNew);
		pNew = NULL;
	}
}