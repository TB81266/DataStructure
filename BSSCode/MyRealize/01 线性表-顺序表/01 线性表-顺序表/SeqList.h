#ifndef SEQLIST_H_
#define SEQLIST_H_

#include"Common.h"

#define MAX_CAPACITY 10

typedef int ElemType;

typedef struct SeqList{
	ElemType* data;//˳���洢����Ԫ�� ���ֵΪMAX_CAPACITY
	int length;//˳���ĳ���Ҳ��������capacity
	int count;//��ЧԪ�صĸ��� size  count
}SeqList;

////////////////////////////////////////////////////////
//��������
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


//����ʵ�ֽӿ�
/////////////////////////////////////////////////////////////
//��ʼ��˳���
void SeqListInit(SeqList* SList){
	assert(SList != NULL);
	SList->data = (ElemType*)malloc(sizeof(ElemType)*MAX_CAPACITY);
	assert(SList->data != NULL);
	memset(SList->data, 0, sizeof(ElemType)*MAX_CAPACITY);
	SList->count = 0;
	SList->length = MAX_CAPACITY;
}

//�ж�˳����Ƿ�����
bool IsFull(SeqList* SList){
	assert(SList->data != NULL);
	if (SList->count >= MAX_CAPACITY){
		return true;
	}
	else{
		return false;
	}
}

//�ж�˳����Ƿ��ǿյ�
bool IsEmpty(SeqList* SList){
	assert(SList->data != NULL);
	if (SList->count == 0){
		return true;
	}
	else{
		return false;
	}
}
//β����������
void SeqListPush_back(SeqList* SList,ElemType val){
	int i = 0;
	assert(SList->data != NULL);
	if (IsFull(SList)){
		printf("˳������ˣ��޷����룡\n");
		return;
	}
	SList->data[SList->count++] = val;
}

//ͷ����������
void SeqListpush_front(SeqList* SList, ElemType val){
	int i = 0;
	assert(SList->data != NULL);
	if (IsFull(SList)){
		printf("˳������ˣ��޷����룡\n");
		return;
	}
	for (i = SList->count; i > 0; --i){
		SList->data[i] = SList->data[i-1];//SList->data[i+1] = SList->data[i];��ʲô����?z��ϸ�����±� 
	}
	SList->data[0] = val;
	SList->count++;
}

//���ݵ���ʾ
void SeqListshow_list(SeqList* SList){
	assert(SList->count != NULL);
	int i = 0;
	for (i = 0; i < SList->count; ++i){
		printf("%d ", SList->data[i]);
	}
	printf("\n");
}

//˳����β��ɾ��
void SeqListpop_back(SeqList* SList, ElemType val){
	assert(SList->data != NULL);
	if (IsEmpty(SList)){
		printf("˳���Ϊ�գ�ɾ��ʧ�ܣ�\n");
		return;
	}
	SList->data[SList->count] = 0;
	SList->count--;
}

//˳����ͷ��ɾ��
void SeqListpop_front(SeqList* SList, ElemType val){
	int pos = 0;
	assert(SList->data != NULL);
	if (IsEmpty(SList)){
		printf("˳���Ϊ�գ�ɾ��ʧ�ܣ�\n");
		return;
	}
	for (pos =0; pos <SList->count; ++pos){
		SList->data[pos] = SList->data[pos + 1];
	}
	SList->count--;;
}

//˳������λ�ò���Ԫ��
void SeqListInsertByPos(SeqList* SList, int pos, ElemType val){
	assert(SList->data != NULL);
	if (IsFull(SList) || pos < 1||pos > SList->length){
		printf("�������������������ʧ�ܣ�\n");
		return;
	}
	for (int i = SList->count; i>pos; --i){
		SList->data[i] = SList->data[i - 1];
	}
	SList->data[pos] = val;
	SList->count++;
}


//˳������ֵ����Ԫ��(******��Ҫ��ǿ���****)
void SeqListInsertByVal(SeqList* SList, ElemType val){
	//�Ӻ���ǰ�Ƚ�
	assert(SList != NULL);
	if (IsFull(SList)){
		printf("˳���ռ�����,���ܰ�ֵ��������!\n");
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

	//һ�·���Ҳ�ǿ��е�
	/*int end = SList->count;
	while (end>0 && val < SList->data[end - 1]){
		SList->data[end] = SList->data[end - 1];
		end--;
	}
	SList->data[end] = val;
	SList->count++;*/
}

//˳������λ��ɾ����ֵ
void SeqListDeleteByPos(SeqList *SList, int pos){
	assert(SList->data != NULL);
	if (IsEmpty(SList)){
		printf("˳���Ϊ�գ��޷�����λ��ɾ����\n");
		return;
	}
	if (pos < 0 || pos >= SList->count){
		printf("Ҫɾ�����ݵ�λ�÷Ƿ������ܰ�λ��ɾ������.\n");
		return;
	}
	for (int i = pos; i<SList->count; ++i){
		SList->data[i] = SList->data[i + 1];
	}
	SList->count--;
}

//˳��������ֵɾ����ֵ
void SeqListDeleteByVal(SeqList *SList, ElemType val){
	assert(SList != NULL);
	if (IsEmpty(SList)){
		printf("˳���Ϊ�գ��޷�������ֵ����ɾ����\n");
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

//��˳���������ֵ ������
int SeqListfind_val(SeqList* SList, ElemType val){
	assert(SList != NULL);
	if (IsEmpty(SList)){
		printf("˳���Ϊ�գ�������ֵʧ�ܣ�\n");
		return -1;
	}
	for (int i = 0; i < SList->count; ++i){
		if (val == SList->data[i]){
			return i;
		}
	}
	return -1;
}

//˳���ĳ���
int SeqListLength(SeqList *SList){
	assert(SList != NULL);
	return SList->count;
}

//˳��������
int SeqListCapacity(SeqList *SList){
	assert(SList != NULL);
	return SList->length;
}

//˳��������Ԫ�ؽ���λ��
void SeqListSwap(ElemType* a, ElemType* b){
	if (*a > *b){
		ElemType temp = *a;
		*a = *b;
		*b = temp;
	}
}
//˳��������Ԫ������(ð������)
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

//˳���ת 
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

//���˳��������
void  SeqListClear(SeqList *SList){
	assert(SList->data != NULL);
	 SList->count = 0;
}

//ɾ�����е�����
int SeqListRemove_all_same(SeqList *SList,ElemType val,int size){

	assert(SList->data != NULL);
	if (IsEmpty(SList)){
		printf("˳���Ϊ�գ����ظ������ֿ�ɾ����\n");
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