#include"SeqQueue.h"

void Menu(){
	printf("**********************************************************\n");
	printf("[1] SeqQueueEnQueue           [2] SeqQueueDeQueue        *\n");
	printf("[3] SeqQueueShow              [4] SeqQueueTop            *\n");
	printf("[5] SeqStackClear             [6] SeqStackDestroy        *\n");
	printf("**********************************************************\n");
}

//自动扩容 扩容成功 true ,否则false
static bool IncSeqQueueCapacity(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	ElemType* NewBase = (ElemType*)realloc(pSQueue->base, sizeof(ElemType)*pSQueue->capacity * 2);
	if (NewBase == NULL){
		return false;
	}
	else{
		pSQueue->base = NewBase;
		pSQueue->capacity = pSQueue->capacity * 2;
		return true;
	}

}
//顺序对列的初始化
void SeqQueueInit(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	pSQueue->base = (ElemType*)malloc(sizeof(ElemType)*SEQQUEUE_DEFAULT_SZIE);
	assert(pSQueue->base != NULL);
	pSQueue->capacity = SEQQUEUE_DEFAULT_SZIE;
	pSQueue->front = 0;
	pSQueue->tail = 0;
}

bool SeqQueueIsFull(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	if (pSQueue->tail >= pSQueue->capacity){
		return true;
	}
	else{
		return false;
	}
}
bool SeqQueueIsEmpty(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	if (pSQueue->tail == pSQueue->front){
		return true;
	}
	else{
		return false;
	}
}
//入栈
void  SeqQueueEnQueue(SeqQueue* pSQueue, ElemType val){
	assert(pSQueue != NULL);
	if (SeqQueueIsFull(pSQueue) && !IncSeqQueueCapacity(pSQueue)){
		printf("顺序队列已经满了,扩容失败！\n");
		return;
	}
	else{
		pSQueue->base[pSQueue->tail] = val;// 前面两句话可以合成一句话：pSQueue->base[pSQueue->top++] = val;
		pSQueue->tail++;
	}
}

//出栈
void SeqQueueDeQueue(SeqQueue* SeqQueue){
	assert(SeqQueue != NULL);
	if (SeqQueueIsEmpty(SeqQueue)){
		printf("顺序对列为空，出栈失败！\n");
		return;
	}
	else{
		SeqQueue->front++;
	}
}

//顺序栈的打印
void SeqQueueShow(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	if (SeqQueueIsEmpty(pSQueue)){
		printf("顺序对列为空，打印失败！\n");
		return;
	}
	else{
		for (int i = pSQueue->front; i <pSQueue->tail; ++i){
			printf("%d ", pSQueue->base[i]);
		}
		printf("\n");
	}
}

//取顺序对列的顶元素
ElemType SeqQueueTop(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	if (SeqQueueIsEmpty(pSQueue)){
		printf("顺序栈为空，无法取栈顶的元素！\n");
		return -1;
	}
	else{
		return pSQueue->base[pSQueue->front];
	}
}

//顺序对列的清理
void SeqQueueClear(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	if (SeqQueueIsEmpty(pSQueue)){
		printf("顺序对列为空，无需清除！\n");
		return;
	}
	else{
		for (int i = pSQueue->front; i < pSQueue->tail; ++i){
			pSQueue->base[i] = 0;
		}
		printf("\n");
	}
}

//顺序对列的销毁
void SeqQueueDestroy(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	free(pSQueue->base);
	pSQueue->base = NULL;
	pSQueue->capacity = pSQueue->front = pSQueue->tail = 0;
}