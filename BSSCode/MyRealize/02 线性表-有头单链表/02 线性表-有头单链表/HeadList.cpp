#include"HeadList.h"

void Menu(){
	printf("***********************************************\n");
	printf("* [1] EmptyList              [2] InsertList   *\n");
	printf("* [3] TraverseList           [4] SortList     *\n");
	printf("* [5] DeleteList             [6] LengthList   *\n");
	printf("* [7] Destroy                [0] Exit         *\n");
	printf("***********************************************\n");

}
//��������ͷ�ڵ�
//�ȼ��� Node** pMyList�� mylist��һ��ָ�� &mylist�Ƕ���ָ��

//ע�����ͷ������ĳ�ʼ��������
void LinkListInit(LinkList* pMyList){
	(*pMyList) = (PNODE)malloc(sizeof(NODE));
	assert((*pMyList) != NULL);
	(*pMyList)->pNext = NULL;
}


//β�鷨������ͷ������
void LinkListCreateTail(LinkList* pMyList){
	assert(pMyList != NULL);//Ϊʲô����*pMyList
	PNODE p = *pMyList; //����һ��p�ڵ�ָ�� ͷ�ڵ� ��������

	for (int i = 0; i < 10; ++i){
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		assert(pNew != NULL);
		pNew->data = i;
		pNew->pNext = NULL;
		p->pNext = pNew;
		p = pNew;	
	}
}

//ͷ�巨������ͷ������
void LinkListCreateHead(LinkList* pMyList){
	assert(pMyList != NULL);//Ϊʲô����*pMyList ֮�������
	PNODE p = *pMyList; //����һ��p�ڵ�ָ�� ͷ�ڵ� ��������

	for (int i = 0; i < 10; ++i){
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		assert(pNew != NULL);
		pNew->data = i;
		pNew->pNext = p->pNext;
		p->pNext = pNew;
		
	}
}


//��������(��ͷβ�巨)
void TraverseLinkList(LinkList pMyList){
	PNODE p = pMyList;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->pNext;
	}
	printf("over\n");
}

//�ж������Ƿ�Ϊ��(��ͷβ�巨)
bool LinkListIsEmpty(LinkList *pMyList){
	assert(pMyList != NULL);
	if ((*pMyList)->pNext == NULL){
		return true;
	}
	else{
		return false;
	}
}

//���������node(��ͷβ�巨)
void InsertLinkList(LinkList *pMyList, int len, int data){
	assert(*pMyList != NULL);
	if (LinkListIsEmpty(pMyList)){
		printf("����Ϊ�գ�\n");
		exit(-1);
	}
	PNODE p = (*pMyList);
	for (int i = 0; i < len - 1; ++i){
		p = p->pNext;
	}
	PNODE s = (PNODE)malloc(sizeof(NODE));
	assert(s != NULL);

	printf("��������Ҫ�����data��\n");
	scanf("%d", &data);
	s->data = data;
	p->pNext = s;//�����⣿����
	s->pNext = NULL;
	p = s;
}