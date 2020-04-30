#ifndef _LIST_H_
#define _LIST_H_

#include"common.h"

typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *head;
}SList;

///////////////////////////////////////////////////////////////////////////////////
//������ĺ����ӿ�����
static SListNode* _Buynode(ElemType x);
void SListInit(SList *plist);
void SListPushBack(SList *plist, ElemType x);
void SListPushFront(SList *plist, ElemType x);
void SListPopBack(SList *plist);
void SListPopFront(SList *plist);
void SListDestroy(SList *plist);

void SListInsertByVal(SList *plist, ElemType x);

SListNode* SListFind(SList *plist, ElemType key);
void SListDeleteByVal(SList *plist, ElemType key);

void SListClear(SList *plist);
size_t SListLength(SList *plist);

void SListReverse(SList *plist);
void SListSort(SList *plist);

void SListShow(SList *plist);

//////////////////////////////////////////////////////////////////////////////////
//������ĺ����ӿ�ʵ��

static SListNode* _Buynode(ElemType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SListInit(SList *plist)
{
	plist->head = NULL;
}

void SListPushBack(SList *plist, ElemType x)
{
	assert(plist != NULL);

	SListNode *s = _Buynode(x);

	//����Ľڵ�Ϊ��һ���ڵ�
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}

	//O(n)
	SListNode *p = plist->head;
	//���������β���ڵ� 
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}

void SListPushFront(SList *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);

	//O(1)
	s->next = plist->head;
	plist->head = s;
}

void SListPopBack(SList *plist)
{
	assert(plist != NULL);
	SListNode *p =nullptr, *prev =nullptr;
	if (plist->head == NULL)
		return;
	p = plist->head;
	//����ֻ��һ���ڵ�
	if (p->next == NULL)
		plist->head = NULL;
	else
	{
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
		prev->next = NULL;
	}
	free(p);
}

void SListPopFront(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	if (plist->head == NULL)
		return;

	plist->head = p->next;
	free(p);
}

SListNode* SListFind(SList *plist, ElemType key)
{
	assert(plist != NULL);
	SListNode *p = plist->head;

	//������ NULL
	//����   P
	//������ NULL

	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}

void SListDeleteByVal(SList *plist, ElemType key)
{
	assert(plist != NULL);
	SListNode *prev = NULL;
	SListNode *p = SListFind(plist, key);
	if (p == NULL)
	{
		printf("Ҫɾ���Ľڵ㲻����.\n");
		return;
	}

	if (p == plist->head)
		plist->head = p->next;
	else
	{
		prev = plist->head;
		while (prev->next != p)
			prev = prev->next;

		//ɾ���ڵ�
		prev->next = p->next;
	}
	free(p);
}


size_t SListLength(SList *plist)
{
	assert(plist != NULL);
	size_t len = 0;
	SListNode *p = plist->head;

	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void SListShow(SList *plist)
{
	assert(plist != NULL);
	SListNode * p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void SListDestroy(SList *plist)
{
	SListClear(plist);
	plist->head = NULL;
}

void SListClear(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}


void SListReverse(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q;
	if (p->next == NULL)
		return;

	//�Ͽ���һ���ڵ�
	plist->head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}

void SListInsertByVal(SList *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *prev = NULL;
	SListNode *p = plist->head;

	SListNode *s = _Buynode(x);

	while (p != NULL && x>p->data)
	{
		prev = p;
		p = p->next;
	}

	if (prev == NULL) //��Ҫ����ͷ��
	{
		s->next = p;
		plist->head = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}

void SListSort(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q, *t, *prev = NULL;

	plist->head->next = NULL; //�Ͽ�����

	t = plist->head;
	while (p != NULL)
	{
		q = p->next;
		//��p�ڵ�ժ�����а�ֵ���룬����
		while (t != NULL && p->data > t->data)
		{
			prev = t;
			t = t->next;
		}
		if (prev == NULL)
		{
			p->next = plist->head;
			plist->head = p;
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
		p = q;
		t = plist->head;
	}
}


///////////////////////////////////////////////////////////////////////////////////
/*
SListNode* SListFind(SList *plist, ElemType key)
{
assert(plist != NULL);
SListNode *p = plist->head;
while(p != NULL)
{
if(p->data == key)
return p;
p = p->next;
}
return NULL;
}
/*
//��������ڵ�
typedef struct ListNode
{
int data;
struct ListNode *next;
}ListNode;
typedef ListNode* List;
//�������ͷ���
void ListInit(List *plist)  //ListNode **plist
{
*plist = (ListNode*)malloc(sizeof(ListNode));
assert(*plist != NULL);
(*plist)->next = NULL;
}
//β�巨����������
void ListCreate_Tail(List *plist)
{
assert(plist != NULL);
ListNode *p = *plist;
for(int i=1; i<=10; ++i)
{
ListNode *s = (ListNode *)malloc(sizeof(ListNode));
assert(s != NULL);
s->data = i;
s->next = NULL;
p->next = s;
p = s;
}
}
//ͷ�巨����������
void ListCreate_Head(List *plist)
{
assert(plist != NULL);
for(int i=1; i<=10; ++i)
{
ListNode *s = (ListNode*)malloc(sizeof(ListNode));
assert(s != NULL);
s->data = i;

s->next = (*plist)->next;
(*plist)->next = s;
}
}
void ListShow(List plist)
{
ListNode *p = plist->next;
while(p != NULL)
{
printf("%d->", p->data);
p = p->next;
}
printf("Over.\n");
}
/*
//��������ͷ���
void ListInit(List *plist)  //ListNode **plist
{
*plist = NULL;
}
//β�巨����������
void ListCreate_Tail(List *plist)
{
*plist = (ListNode*)malloc(sizeof(ListNode));
assert(*plist != NULL);
(*plist)->data = 1;
(*plist)->next= NULL;
ListNode *p = *plist;
for(int i=2; i<=10; ++i)
{
ListNode *s = (ListNode*)malloc(sizeof(ListNode));
assert(s != NULL);
s->data = i;
s->next = NULL;
//���ӽڵ�
p->next = s;
p = s;
}
}
//ͷ�巨����������
void ListCreate_Head(List *plist)
{
(*plist) = (ListNode*)malloc(sizeof(ListNode));
assert(*plist != NULL);
(*plist)->data = 1;
(*plist)->next = NULL;
for(int i=2; i<=10; ++i)
{
ListNode *s = (ListNode*)malloc(sizeof(ListNode));
assert(s != NULL);
s->data = i;

//���ӽڵ�
s->next = (*plist);
(*plist) = s;
}
}
void ListShow(List plist)
{
ListNode *p = plist;
while(p != NULL)
{
printf("%d->", p->data);
p = p->next;
}
printf("Over.\n");
}
*/

#endif /* _LIST_H_ */