#ifndef SEQLIST_H_
#define SEQLIST_H_
#define SEQLIST_DEFAULT_SIZE 8
#include"common.h"

//定义顺序表结构
typedef struct SeqList{
	ElemType* base;  //整形指针  宏定义
	size_t  capacity;//容量的大小
	size_t  size;//元素的个数
}SeqList;

/////////////////////////////////
//声明接口

void SeqListInit(SeqList * pst);
bool IsFull(SeqList * pst);
bool IsEmpty(SeqList * pst);
void SeqListPush_back(SeqList * pst,ElemType x);
void SeqListPush_front(SeqList * pst, ElemType x);
void SeqListShow(SeqList * pst);
void SeqListDestroy(SeqList *pst);

///////////////////////////////////////////
//函数接口
void SeqListInit(SeqList * pst){
	assert(pst != NULL);
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	// 第一个参数是要初始化的地址，第二个参数是数值位0  第三个是要初始化的空间大小
	memset(pst->base, 0, sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
}


bool IsFull(SeqList * pst){
	assert(pst != NULL);
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList * pst){
	assert(pst != NULL);
	return pst->size == 0;
}

void SeqListPush_back(SeqList * pst, ElemType x){
	assert(pst != NULL);
	if (IsFull(pst)){
		printf("顺序表空间已满，无法插入！\n");
		return;
	}
	else{
		pst->base[pst->size++] = x;
	}
	
}

void SeqListShow(SeqList * pst){
	assert(pst != NULL);
	int i = 0;
	for (i = 0; i < pst->size; ++i){
		printf("%d", pst->base[i]);
	}
	printf("\n");
}
void SeqListPush_front(SeqList * pst, ElemType x){
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满,不能插入数据 %d\n", x);
		return;
	}
	for (size_t pos = pst->size; pos>0; --pos)
		pst->base[pos] = pst->base[pos - 1];
	pst->base[0] = x;
	pst->size++;
}

void SeqListDestroy(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->base)
		free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}

#endif