#include"list.h"

void Menu(){
	printf("***********************************************\n");
	printf("* [1] EmptyList              [2] InsertList   *\n");
	printf("* [3] TraverseList           [4] SortList     *\n");
	printf("* [5] DeleteList             [6] LengthList   *\n");
	printf("* [7] Destroy                [0] Exit         *\n");
	printf("***********************************************\n");

}
//单链表不带头节点
//等价于 Node** pMyList， mylist是一个指针 &mylist是二级指针
//注意和有头结点的单链表初始化的区别
void LinkListInit(LinkList* pMyList){
	*pMyList == NULL;
}

//创建链表
PNODE LinkListCreate(LinkList* pMyList,int len){
	assert(*pMyList != NULL);
	*pMyList = (PNODE)malloc(sizeof(NODE));
	assert(*pMyList != NULL);
	(*pMyList)->data = 100;
	(*pMyList)->pNext = NULL;

	PNODE p = (*pMyList);//定义一个节点保护原来的链表的地址

	for (int i = 2; i < len; ++i){
		PNODE s = (PNODE)malloc(sizeof(NODE));
		assert(s != NULL);
		s->data = i;
		s->pNext = NULL;

		p->pNext = s;
		p = s;
	}
	return (*pMyList);
}


//尾查法创建链表
void LinkListCreateTail(LinkList* pMyList){
	//对头节点的处理
	*pMyList = (PNODE)malloc(sizeof(NODE));
	assert(*pMyList != NULL);
	(*pMyList)->data = 1;
	(*pMyList)->pNext = NULL;

	PNODE p = (*pMyList);//定义一个节点 将创建的地址赋给新的节点
	for (int i = 2; i <= 10; ++i){
		PNODE s = (PNODE)malloc(sizeof(NODE));
		assert(s != NULL);
		s->data = i;
		s->pNext = NULL;
		//连接结点
		p->pNext = s;
		p = s;
	}
}

//头插法创建单链表
void LinkListCreateHead(LinkList* pMyList){
	//对头结点的处理
	*pMyList = (PNODE)malloc(sizeof(NODE));
	assert(*pMyList != NULL);
	(*pMyList)->data = 1;
	(*pMyList)->pNext = NULL;

	for (int i = 2; i <= 10; ++i){
		PNODE s = (PNODE)malloc(sizeof(NODE));
		assert(s != NULL);
		s->data = i;
		//连接结点
		s->pNext = *pMyList;
		(*pMyList) = s;
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
			p= p->pNext;
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