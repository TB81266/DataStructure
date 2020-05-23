#include"LinkQueue.h"


//�����ӿڵ�ʵ��
////////////////////////////////////////
void Menu(){
	printf("**********************************************************\n");
	printf("[1] LinkQueueEnQueue             [2] LinkQueueDeQueue    *\n");
	printf("[3] LinkQueueShow                [4] LinkQueueTop        *\n");
	printf("**********************************************************\n");
}

void LinkQueueInit(LinkQueue* pLQueue){
	assert(pLQueue != NULL);
	pLQueue->front = pLQueue->tail = NULL;

}

//β�巨ʵ�������е����
void LinkQueueEnQueue(LinkQueue* pLQueue, ElemType val){
	assert(pLQueue != NULL);
	LinkQueueNode* pNew = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(pNew != NULL);
	pNew->data = val;
	pNew = NULL;
	if (pLQueue->front == NULL){
		pLQueue->front = pLQueue->tail = pNew;
	}
	else{
		pLQueue->tail->pNext = pNew;
		pLQueue->tail = pNew;
	}
}


//�����еĳ���
void LinkQueueDeQueue(LinkQueue* pLQueue){
	assert(pLQueue != NULL);
	if (pLQueue->front != NULL){
		LinkQueueNode* pNew = pLQueue->front;
		pLQueue->front = pNew->pNext;
		free(pNew);
		pNew = NULL;
	}
}

//�����еĴ�ӡ
void LinkQueueShow(LinkQueue* pLQueue){
	assert(pLQueue != NULL);
	LinkQueueNode* pNew = pLQueue->front;
	while (pNew != NULL){
		printf("%d", pNew->data);
		pNew = pNew->pNext;
	}
	printf("\n");
}

//ȡ�������ж�����Ԫ��
ElemType LinkQueueTop(LinkQueue* pLQueue){
	assert(pLQueue != NULL);
	if (pLQueue->front == NULL){
		printf("������Ϊ�գ�\n");
		return NULL;
	}
	else{
		return pLQueue->front->data;
	}
}

void LinkQueueDestory(LinkQueue* pLQueue){
	assert(pLQueue != NULL);
	LinkQueueNode* pNew = pLQueue->front;
	while (pLQueue->front != NULL){
		pLQueue->front = pNew->pNext;
		free(pNew);
		pNew = NULL;
	}
}