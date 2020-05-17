#include"SeqQueue.h"

void Menu(){
	printf("**********************************************************\n");
	printf("[1] SeqQueueEnQueue           [2] SeqQueueDeQueue        *\n");
	printf("[3] SeqQueueShow              [4] SeqQueueTop            *\n");
	printf("[5] SeqStackClear             [6] SeqStackDestroy        *\n");
	printf("**********************************************************\n");
}

//�Զ����� ���ݳɹ� true ,����false
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
//˳����еĳ�ʼ��
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
//��ջ
void  SeqQueueEnQueue(SeqQueue* pSQueue, ElemType val){
	assert(pSQueue != NULL);
	if (SeqQueueIsFull(pSQueue) && !IncSeqQueueCapacity(pSQueue)){
		printf("˳������Ѿ�����,����ʧ�ܣ�\n");
		return;
	}
	else{
		pSQueue->base[pSQueue->tail] = val;// ǰ�����仰���Ժϳ�һ�仰��pSQueue->base[pSQueue->top++] = val;
		pSQueue->tail++;
	}
}

//��ջ
void SeqQueueDeQueue(SeqQueue* SeqQueue){
	assert(SeqQueue != NULL);
	if (SeqQueueIsEmpty(SeqQueue)){
		printf("˳�����Ϊ�գ���ջʧ�ܣ�\n");
		return;
	}
	else{
		SeqQueue->front++;
	}
}

//˳��ջ�Ĵ�ӡ
void SeqQueueShow(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	if (SeqQueueIsEmpty(pSQueue)){
		printf("˳�����Ϊ�գ���ӡʧ�ܣ�\n");
		return;
	}
	else{
		for (int i = pSQueue->front; i <pSQueue->tail; ++i){
			printf("%d ", pSQueue->base[i]);
		}
		printf("\n");
	}
}

//ȡ˳����еĶ�Ԫ��
ElemType SeqQueueTop(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	if (SeqQueueIsEmpty(pSQueue)){
		printf("˳��ջΪ�գ��޷�ȡջ����Ԫ�أ�\n");
		return -1;
	}
	else{
		return pSQueue->base[pSQueue->front];
	}
}

//˳����е�����
void SeqQueueClear(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	if (SeqQueueIsEmpty(pSQueue)){
		printf("˳�����Ϊ�գ����������\n");
		return;
	}
	else{
		for (int i = pSQueue->front; i < pSQueue->tail; ++i){
			pSQueue->base[i] = 0;
		}
		printf("\n");
	}
}

//˳����е�����
void SeqQueueDestroy(SeqQueue* pSQueue){
	assert(pSQueue != NULL);
	free(pSQueue->base);
	pSQueue->base = NULL;
	pSQueue->capacity = pSQueue->front = pSQueue->tail = 0;
}