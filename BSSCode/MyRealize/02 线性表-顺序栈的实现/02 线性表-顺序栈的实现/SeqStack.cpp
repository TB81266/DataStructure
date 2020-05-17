#include"SeqStack.h"

void Menu(){
	printf("**********************************************************\n");
	printf("[1] SeqStackPushBack          [2] SeqStackPop            *\n");
	printf("[3] SeqStackShow              [4] SeqStackTop            *\n");
	printf("[5] SeqStackClear             [6] SeqStackDestroy        *\n");
	printf("**********************************************************\n");
}

//自动扩容 扩容成功 true ,否则false
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
//顺序栈的初始化
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
//入栈
void SeqStackPushBack(SeqStack* pStack, ElemType val){
	assert(pStack != NULL);
	if (SeqStackIsFull(pStack) && !IncSeqStackCapacity(pStack)){
		printf("顺序栈已经满了,扩容失败！\n");
		return;
	}
	else{
		pStack->base[pStack->top] = val;// 前面两句话可以合成一句话：pStack->base[pStack->top++] = val;
		pStack->top++;
	}
}

//出栈
void SeqStackPop(SeqStack* pStack){
	assert(pStack != NULL);
	if (SeqStackIsEmpty(pStack)){
		printf("顺序栈为空，出栈失败！\n");
		return;
	}
	else{
		pStack->top--;
	}
}

//顺序栈的打印
void SeqStackShow(SeqStack* pStack){
	assert(pStack != NULL);
	if (SeqStackIsEmpty(pStack)){
		printf("顺序栈为空，打印失败！\n");
		return;
	}
	else{
		for (int i = pStack->top-1; i >= 0; --i){
			printf("%d ", pStack->base[i]);
		}
		printf("\n");
	}
}

//取顺序栈的栈顶元素
ElemType SeqStackTop(SeqStack* pStack){
	assert(pStack != NULL);
	if (SeqStackIsEmpty(pStack)){
		printf("顺序栈为空，无法取栈顶的元素！\n");
		return -1;
	}
	else{
		return pStack->base[pStack->top - 1];
	}
}

//顺序栈的清理
void SeqStackClear(SeqStack* pStack){
	assert(pStack != NULL);
	if (SeqStackIsEmpty(pStack)){
		printf("顺序栈为空，无需清除！\n");
		return;
	}
	else{
		for (int i = pStack->top - 1; i >= 0; --i){
			pStack->base[i] = 0;
		}
		printf("\n");
	}
}

//顺序栈的销毁
void SeqStackDestroy(SeqStack* pStack){
	assert(pStack != NULL);
	free(pStack->base);
	pStack->base = NULL;
}