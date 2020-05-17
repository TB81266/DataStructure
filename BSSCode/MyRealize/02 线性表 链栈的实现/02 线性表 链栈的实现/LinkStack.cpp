#include"LinkStack.h"


//�����ӿڵ�ʵ��
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

//ͷ�巨ʵ����ջ����ջ
void LinkStackPush(LinkStack* pLStack, ElemType val){
	assert(pLStack != NULL);
	LinkStackNode* pNew = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(pNew != NULL);
	pNew->data = val;
	pNew->pNext = pLStack->pTop;
	pLStack->pTop = pNew;
}

//��ջ�ĳ�ջ
void LinkStackPop(LinkStack* pLStack){
	assert(pLStack != NULL);
	LinkStackNode* pNew = pLStack->pTop;
	pLStack->pTop = pNew->pNext;
	free(pNew);
	pNew = NULL;
}

//��ջ�Ĵ�ӡ
void LinkStackShow(LinkStack* pLStack){
	assert(pLStack != NULL);
	LinkStackNode* pNew = pLStack->pTop;
	while (pNew != NULL){
		printf("%d ", pNew->data);
		pNew = pNew->pNext;
	}
	printf("\n");
}

//ȡ��ջ����Ԫ��
ElemType LinkStackTop(LinkStack* pLStack){
	assert(pLStack != NULL);
	if (pLStack->pTop == NULL){
		printf("��ջWΪ�գ�\n");
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