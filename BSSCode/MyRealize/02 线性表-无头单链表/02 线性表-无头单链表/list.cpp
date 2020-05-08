#include"list.h"

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
//ע�����ͷ���ĵ������ʼ��������
void LinkListInit(LinkList* pMyList){
	*pMyList == NULL;
}

//��������
PNODE LinkListCreate(LinkList* pMyList,int len){
	assert(*pMyList != NULL);
	*pMyList = (PNODE)malloc(sizeof(NODE));
	assert(*pMyList != NULL);
	(*pMyList)->data = 100;
	(*pMyList)->pNext = NULL;

	PNODE p = (*pMyList);//����һ���ڵ㱣��ԭ��������ĵ�ַ

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


//β�鷨��������
void LinkListCreateTail(LinkList* pMyList){
	//��ͷ�ڵ�Ĵ���
	*pMyList = (PNODE)malloc(sizeof(NODE));
	assert(*pMyList != NULL);
	(*pMyList)->data = 1;
	(*pMyList)->pNext = NULL;

	PNODE p = (*pMyList);//����һ���ڵ� �������ĵ�ַ�����µĽڵ�
	for (int i = 2; i <= 10; ++i){
		PNODE s = (PNODE)malloc(sizeof(NODE));
		assert(s != NULL);
		s->data = i;
		s->pNext = NULL;
		//���ӽ��
		p->pNext = s;
		p = s;
	}
}

//ͷ�巨����������
void LinkListCreateHead(LinkList* pMyList){
	//��ͷ���Ĵ���
	*pMyList = (PNODE)malloc(sizeof(NODE));
	assert(*pMyList != NULL);
	(*pMyList)->data = 1;
	(*pMyList)->pNext = NULL;

	for (int i = 2; i <= 10; ++i){
		PNODE s = (PNODE)malloc(sizeof(NODE));
		assert(s != NULL);
		s->data = i;
		//���ӽ��
		s->pNext = *pMyList;
		(*pMyList) = s;
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
			p= p->pNext;
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