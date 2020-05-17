#include"SeqStack.h"

void Menu(){
	printf("**********************************************************\n");
	printf("[1] SeqStackPushBack          [2] SeqStackPop            *\n");
	printf("[3] SeqStackShow              [4] SeqStackTop            *\n");
	printf("[5] SeqStackClear             [6] SeqStackDestroy        *\n");
	printf("**********************************************************\n");
}

//�Զ����� ���ݳɹ� true ,����false
static bool IncSeqStackCapacity(SeqStack* pStack){
	assert(pStack != NULL);
	ElemType* NewBase = (ElemType*)realloc(pStack->base,sizeof(ElemType)*pStack->capacity * 2);
	if (NewBase == NULL){
		return false;
	}
	else{
		pStack->base = NewBase;
		pStack->capacity = pStack->capacity * 2;
		return true;
	}

}
//˳��ջ�ĳ�ʼ��
void SeqStackInit(SeqStack* pStack){
	assert(pStack != NULL);
	pStack->base = (ElemType*)malloc(sizeof(ElemType)*SEQSTACK_DEFAULT_SZIE);
	assert(pStack->base != NULL);
	pStack->capacity = SEQSTACK_DEFAULT_SZIE;
	pStack->top = 0;
}

bool SeqStackIsFull(SeqStack* pStack){
	assert(pStack != NULL);
	if (pStack->top >= SEQSTACK_DEFAULT_SZIE){
		return true;
	}
	else{
		return false;
	}
}
bool SeqStackIsEmpty(SeqStack* pStack){
	assert(pStack != NULL);
	if (pStack->top ==0){
		return true;
	}
	else{
		return false;
	}
}
//��ջ
void SeqStackPushBack(SeqStack* pStack, ElemType val){
	assert(pStack != NULL);
	if (SeqStackIsFull(pStack) && !IncSeqStackCapacity(pStack)){
		printf("˳��ջ�Ѿ�����,����ʧ�ܣ�\n");
		return;
	}
	else{
		pStack->base[pStack->top] = val;// ǰ�����仰���Ժϳ�һ�仰��pStack->base[pStack->top++] = val;
		pStack->top++;
	}
}

//��ջ
void SeqStackPop(SeqStack* pStack){
	assert(pStack != NULL);
	if (SeqStackIsEmpty(pStack)){
		printf("˳��ջΪ�գ���ջʧ�ܣ�\n");
		return;
	}
	else{
		pStack->top--;
	}
}

//˳��ջ�Ĵ�ӡ
void SeqStackShow(SeqStack* pStack){
	assert(pStack != NULL);
	if (SeqStackIsEmpty(pStack)){
		printf("˳��ջΪ�գ���ӡʧ�ܣ�\n");
		return;
	}
	else{
		for (int i = pStack->top-1; i >= 0; --i){
			printf("%d ", pStack->base[i]);
		}
		printf("\n");
	}
}

//ȡ˳��ջ��ջ��Ԫ��
ElemType SeqStackTop(SeqStack* pStack){
	assert(pStack != NULL);
	if (SeqStackIsEmpty(pStack)){
		printf("˳��ջΪ�գ��޷�ȡջ����Ԫ�أ�\n");
		return -1;
	}
	else{
		return pStack->base[pStack->top - 1];
	}
}

//˳��ջ������
void SeqStackClear(SeqStack* pStack){
	assert(pStack != NULL);
	if (SeqStackIsEmpty(pStack)){
		printf("˳��ջΪ�գ����������\n");
		return;
	}
	else{
		for (int i = pStack->top - 1; i >= 0; --i){
			pStack->base[i] = 0;
		}
		printf("\n");
	}
}

//˳��ջ������
void SeqStackDestroy(SeqStack* pStack){
	assert(pStack != NULL);
	free(pStack->base);
	pStack->base = NULL;
}