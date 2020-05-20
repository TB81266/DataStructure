#include"CycleQueue.h"

void Menu(){
	printf("**********************************************************\n");
	printf("[1] CycleQueueEnQueue           [2] CycleQueueDeQueue    *\n");
	printf("[3] CycleQueueShow              [4] CycleQueueTop        *\n");
	printf("[5] CycleQueueClear             [6] CycleQueueDestroy    *\n");
	printf("**********************************************************\n");
}


//循环对列的初始化
void CycleQueueInit(CycleQueue* pCQueue){
	assert(pCQueue != NULL);
	pCQueue->base = (ElemType*)malloc(sizeof(ElemType)*(CYCLEQUEUE_DEFAULT_SZIE+1));
	assert(pCQueue->base != NULL);
	pCQueue->capacity = CYCLEQUEUE_DEFAULT_SZIE + 1;
	pCQueue->front = 0;
	pCQueue->tail = 0;
}
bool CycleQueueIsFull(CycleQueue* pCQueue){
	assert(pCQueue != NULL);
	if ((pCQueue->tail + 1) % (pCQueue->capacity) == pCQueue->front){
		return true;
	}
	else{
		return false;
	}
}
bool CycleQueueIsEmpty(CycleQueue* pCQueue){
	assert(pCQueue != NULL);
	if (pCQueue->front == pCQueue->tail){
		return true;
	}
	else{
		return false;
	}
}
//入队列
void CycleQueueEnQueue(CycleQueue* pCQueue, ElemType val){
	assert(pCQueue != NULL);
	if (CycleQueueIsFull(pCQueue)){
		printf("循环队列已经满了,入队失败！\n");
		return;
	}
	else{
		pCQueue->base[pCQueue->tail] = val;
		pCQueue->tail = (pCQueue->tail + 1) % pCQueue->capacity;
	}
}

//出队列
void CycleQueueDeQueue(CycleQueue* pCQueue){
	assert(pCQueue != NULL);
	if (CycleQueueIsEmpty(pCQueue)){
		printf("循环对列为空，出对失败！\n");
		return;
	}
	else{
		pCQueue->front = (pCQueue->front + 1) % pCQueue->capacity;
	}
}

//循环队列的打印
void CycleQueueShow(CycleQueue* pCQueue){
	assert(pCQueue != NULL);
	if (CycleQueueIsEmpty(pCQueue)){
		printf("循环对列为空，打印失败！\n");
		return;
	}
	else{
		for (int i = pCQueue->front; i != pCQueue->tail; ){
			printf("%d ", pCQueue->base[i]);
			i = (i + 1) % pCQueue->capacity;
		}
		printf("\n");
	}
}

//取循环对列的顶元素
ElemType CycleQueueTop(CycleQueue* pCQueue){
	assert(pCQueue != NULL);
	if (CycleQueueIsEmpty(pCQueue)){
		printf("循环对列为空，打印失败！\n");
		return -1;
	}
	else{
		return pCQueue->base[pCQueue->front];
	}
}

//循环对列的清理
void CycleQueueClear(CycleQueue* pCQueue){
	assert(pCQueue != NULL);
	if (CycleQueueIsEmpty(pCQueue)){
		printf("循环对列为空，清理失败！\n");
		return;
	}
	else{
		for (int i = pCQueue->front; i < pCQueue->tail; ++i){
			pCQueue->base[i] = 0;
		}
		printf("\n");
	}
}

//循环对列的销毁
void CycleQueueDestroy(CycleQueue* pCQueue){
	assert(pCQueue != NULL);
	free(pCQueue->base);
	pCQueue->base = NULL;
	pCQueue->capacity = pCQueue->front = pCQueue->tail = 0;
}