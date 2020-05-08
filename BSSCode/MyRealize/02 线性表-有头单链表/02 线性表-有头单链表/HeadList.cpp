#include"HeadList.h"

void Menu(){
	printf("***********************************************\n");
	printf("* [1] EmptyList              [2] InsertList   *\n");
	printf("* [3] TraverseList           [4] SortList     *\n");
	printf("* [5] DeleteList             [6] LengthList   *\n");
	printf("* [7] Destroy                [0] Exit         *\n");
	printf("***********************************************\n");

}
//单链表有头节点
//等价于 Node** pMyList， mylist是一个指针 &mylist是二级指针

//注意和无头单链表的初始化的区别
void LinkListInit(LinkList* pMyList){
	(*pMyList) = (PNODE)malloc(sizeof(NODE));
	assert((*pMyList) != NULL);
	(*pMyList)->pNext = NULL;
}


//尾查法创建有头单链表
void LinkListCreateTail(LinkList* pMyList){
	assert(pMyList != NULL);//为什么不是*pMyList
	PNODE p = *pMyList; //定义一个p节点指向 头节点 保护链表

	for (int i = 0; i < 10; ++i){
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		assert(pNew != NULL);
		pNew->data = i;
		pNew->pNext = NULL;
		p->pNext = pNew;
		p = pNew;	
	}
}

//头插法创建带头单链表
void LinkListCreateHead(LinkList* pMyList){
	assert(pMyList != NULL);//为什么不是*pMyList 之间的区别
	PNODE p = *pMyList; //定义一个p节点指向 头节点 保护链表

	for (int i = 0; i < 10; ++i){
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		assert(pNew != NULL);
		pNew->data = i;
		pNew->pNext = p->pNext;
		p->pNext = pNew;
		
	}
}


//遍历链表(无头尾插法)
void TraverseLinkList(LinkList pMyList){
	PNODE p = pMyList;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->pNext;
	}
	printf("over\n");
}

//判断链表是否为空(无头尾插法)
bool LinkListIsEmpty(LinkList *pMyList){
	assert(pMyList != NULL);
	if ((*pMyList)->pNext == NULL){
		return true;
	}
	else{
		return false;
	}
}

//插入链表的node(无头尾插法)
void InsertLinkList(LinkList *pMyList, int len, int data){
	assert(*pMyList != NULL);
	if (LinkListIsEmpty(pMyList)){
		printf("链表为空！\n");
		exit(-1);
	}
	PNODE p = (*pMyList);
	for (int i = 0; i < len - 1; ++i){
		p = p->pNext;
	}
	PNODE s = (PNODE)malloc(sizeof(NODE));
	assert(s != NULL);

	printf("请输入您要插入的data：\n");
	scanf("%d", &data);
	s->data = data;
	p->pNext = s;//有问题？？？
	s->pNext = NULL;
	p = s;
}