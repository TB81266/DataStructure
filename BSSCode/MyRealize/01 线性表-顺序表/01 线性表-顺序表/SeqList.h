#ifndef SEQLIST_H_
#define SEQLIST_H_

#include"Common.h"

#define MAX_CAPACITY 10

typedef int ElemType;

typedef struct SeqList{
	ElemType* data;//顺序表存储数据元素 最大值为MAX_CAPACITY
	int length;//顺序表的长度也就是容量capacity
	int count;//有效元素的个数 size  count
}SeqList;

////////////////////////////////////////////////////////
//函数声明
void SeqListInit(SeqList* SList);
bool IsFull(SeqList* SList);
bool IsEmpty(SeqList* SList);
void SeqListPush_back(SeqList* SList, ElemType val);
void SeqListpush_front(SeqList* SList, ElemType val);
void SeqListshow_list(SeqList* SList);
void SeqListpop_back(SeqList* SList, ElemType val);
void SeqListpop_front(SeqList* SList, ElemType val);
void SeqListInsertByPos(SeqList* SList, int pos, ElemType val);
void SeqListInsertByVal(SeqList* SList, ElemType val);
void SeqListDeleteByPos(SeqList *SList, int pos);
void SeqListDeleteByVal(SeqList *SList, ElemType val);
void SeqListSort(SeqList *SList);
void SeqListSwap(ElemType a,ElemType b);
int SeqListfind_val(SeqList* SList, ElemType val);
int SeqListLength(SeqList *SList);
int SeqListCapacity(SeqList *SList);
void SeqListReverse(SeqList *SList);
void SeqListClear(SeqList *SList);
int SeqListRemove_all_same(SeqList *SList, ElemType val,int size);


//函数实现接口
/////////////////////////////////////////////////////////////
//初始化顺序表
void SeqListInit(SeqList* SList){
	assert(SList != NULL);
	SList->data = (ElemType*)malloc(sizeof(ElemType)*MAX_CAPACITY);
	assert(SList->data != NULL);
	memset(SList->data, 0, sizeof(ElemType)*MAX_CAPACITY);
	SList->count = 0;
	SList->length = MAX_CAPACITY;
}

//判断顺序表是否满了
bool IsFull(SeqList* SList){
	assert(SList->data != NULL);
	if (SList->count >= MAX_CAPACITY){
		return true;
	}
	else{
		return false;
	}
}

//判断顺序表是否是空的
bool IsEmpty(SeqList* SList){
	assert(SList->data != NULL);
	if (SList->count == 0){
		return true;
	}
	else{
		return false;
	}
}
//尾部插入数据
void SeqListPush_back(SeqList* SList,ElemType val){
	int i = 0;
	assert(SList->data != NULL);
	if (IsFull(SList)){
		printf("顺序表满了，无法插入！\n");
		return;
	}
	SList->data[SList->count++] = val;
}

//头部插入数据
void SeqListpush_front(SeqList* SList, ElemType val){
	int i = 0;
	assert(SList->data != NULL);
	if (IsFull(SList)){
		printf("顺序表满了，无法插入！\n");
		return;
	}
	for (i = SList->count; i > 0; --i){
		SList->data[i] = SList->data[i-1];//SList->data[i+1] = SList->data[i];有什么区别?z仔细考虑下标 
	}
	SList->data[0] = val;
	SList->count++;
}

//内容的显示
void SeqListshow_list(SeqList* SList){
	assert(SList->count != NULL);
	int i = 0;
	for (i = 0; i < SList->count; ++i){
		printf("%d ", SList->data[i]);
	}
	printf("\n");
}

//顺序表从尾部删除
void SeqListpop_back(SeqList* SList, ElemType val){
	assert(SList->data != NULL);
	if (IsEmpty(SList)){
		printf("顺序表为空，删除失败！\n");
		return;
	}
	SList->data[SList->count] = 0;
	SList->count--;
}

//顺序表从头部删除
void SeqListpop_front(SeqList* SList, ElemType val){
	int pos = 0;
	assert(SList->data != NULL);
	if (IsEmpty(SList)){
		printf("顺序表为空，删除失败！\n");
		return;
	}
	for (pos =0; pos <SList->count; ++pos){
		SList->data[pos] = SList->data[pos + 1];
	}
	SList->count--;;
}

//顺序表根据位置插入元素
void SeqListInsertByPos(SeqList* SList, int pos, ElemType val){
	assert(SList->data != NULL);
	if (IsFull(SList) || pos < 1||pos > SList->length){
		printf("不满足插入条件，插入失败！\n");
		return;
	}
	for (int i = SList->count; i>pos; --i){
		SList->data[i] = SList->data[i - 1];
	}
	SList->data[pos] = val;
	SList->count++;
}


//顺序表根据值插入元素(******需要加强理解****)
void SeqListInsertByVal(SeqList* SList, ElemType val){
	//从后往前比较
	assert(SList != NULL);
	if (IsFull(SList)){
		printf("顺序表空间已满,不能按值插入数据!\n");
		return;
	}
	int pos = 0;
	int i;
	for (i = 0; i < SList->count; ++i){
		if (val < SList->data[i]){
			pos = i;
			break;
		}
	}
	if (i >= SList->count){
		pos = SList->count;
	}
	SeqListInsertByPos(SList, pos, val);

	//一下方法也是可行的
	/*int end = SList->count;
	while (end>0 && val < SList->data[end - 1]){
		SList->data[end] = SList->data[end - 1];
		end--;
	}
	SList->data[end] = val;
	SList->count++;*/
}

//顺序表根据位置删除数值
void SeqListDeleteByPos(SeqList *SList, int pos){
	assert(SList->data != NULL);
	if (IsEmpty(SList)){
		printf("顺序表为空，无法根据位置删除！\n");
		return;
	}
	if (pos < 0 || pos >= SList->count){
		printf("要删除数据的位置非法，不能按位置删除数据.\n");
		return;
	}
	for (int i = pos; i<SList->count; ++i){
		SList->data[i] = SList->data[i + 1];
	}
	SList->count--;
}

//顺序表根据数值删除数值
void SeqListDeleteByVal(SeqList *SList, ElemType val){
	assert(SList != NULL);
	if (IsEmpty(SList)){
		printf("顺序表为空，无法根据数值进行删除！\n");
		return;
	}
	int pos = 0;
	int i;
	for (i = 0; i < SList->count; ++i){
		if (val == SList->data[i]){
			pos = i;
			break;
		}
	}
	SeqListDeleteByPos(SList, pos);
}

//在顺序表中找数值 并返回
int SeqListfind_val(SeqList* SList, ElemType val){
	assert(SList != NULL);
	if (IsEmpty(SList)){
		printf("顺序表为空，查找数值失败！\n");
		return -1;
	}
	for (int i = 0; i < SList->count; ++i){
		if (val == SList->data[i]){
			return i;
		}
	}
	return -1;
}

//顺序表的长度
int SeqListLength(SeqList *SList){
	assert(SList != NULL);
	return SList->count;
}

//顺序表的容量
int SeqListCapacity(SeqList *SList){
	assert(SList != NULL);
	return SList->length;
}

//顺序表里面的元素交换位置
void SeqListSwap(ElemType* a, ElemType* b){
	if (*a > *b){
		ElemType temp = *a;
		*a = *b;
		*b = temp;
	}
}
//顺序表里面的元素排序(冒泡排序)
void SeqListSort(SeqList *SList){
	assert(SList->data != NULL);
	int i = 0, j = 0;
	for (i = 0; i < SList->count - 1; ++i){
		for (j = 0; j < SList->count - i - 1; ++j){
			SeqListSwap(&SList->data[j], &SList->data[j + 1]);
		}
	}
}

void Swap(ElemType *a, ElemType *b){
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

//顺序表反转 
void SeqListReverse(SeqList *SList){
	assert(SList->data != NULL);
	if (SList->count < 2){
		return;
	}	
	int left = 0;
	int right = SList->count - 1;
	while (left < right){
		Swap(&SList->data[left], &SList->data[right]);
		left++;
		right--;
	}
}

//清楚顺序表的数据
void  SeqListClear(SeqList *SList){
	assert(SList->data != NULL);
	 SList->count = 0;
}

//删除所有的数据
int SeqListRemove_all_same(SeqList *SList,ElemType val,int size){

	assert(SList->data != NULL);
	if (IsEmpty(SList)){
		printf("顺序表为空，无重复的数字可删除！\n");
		return -1;
	}
	for (int i = 0; i < SList->count; ++i){
		if (val == SList->data[i]){
			SList->data[i] = SList->data[i + 1];
			size++;
			SList->count--;
		}
	}
	return size;
}



#endif 