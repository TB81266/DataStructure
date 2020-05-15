#include"HeadList.h"

void Menu(){
	printf("**********************************************************\n");
	printf("[1] DoubleCyclicListPushBack  [2] DoubleCyclicListShow   *\n");
	printf("[3] DoubleCyclicListPushFront [4] DoubleCyclicListPopBack*\n");
	printf("[5] DoubleCyclicListPopFront  [6] DoubleCyclicListLength *\n");
	printf("[7] DoubleCyclicListByFind    [8] DoubleCyclicLisReverse *\n");
	printf("[9] DoubleCyclicListByVal     [10] DoubleCyclicListByDel *\n");
	printf("[11] DoubleCyclicLisSort      [12] DoubleCyclicListClear *\n");
	printf("[13] NoHeadListRemoveAllSameElement                      *\n");
	printf("**********************************************************\n");
}

//申请节点
static NODE* BuyNode(Elemtype val){
	NODE* pNew = (NODE*)malloc(sizeof(NODE));
	assert(pNew != NULL);
	pNew->data = val;
	pNew->pNext = pNew;
	pNew->pLast = pNew;
	//pNew->pLast = pNew->pNext = pNew; 另外的一种写法
	return pNew;
}

//初始化
void DoubleCyclicListInit(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	pMyList->head = BuyNode(0);
}

//尾插法 插入数据
void DoubleCyclicListPushBack(DoubleCyclicList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* pNew = BuyNode(val);
	
	pNew->pLast = pMyList->head->pLast;
	pNew->pLast->pNext = pNew;
	pNew->pNext = pMyList->head;
	pMyList->head->pLast = pNew;
}

//有头双向循环链表的show
void DoubleCyclicListShow(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	NODE * pNew = pMyList->head->pNext;
	while (pNew != pMyList->head){
		printf("%d->", pNew->data);
		pNew = pNew->pNext;
	}
	printf("over\n");
}

//头插法 插入数据
void DoubleCyclicListPushFront(DoubleCyclicList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* pNew = BuyNode(val);
	pNew->pLast = pMyList->head;
	pNew->pNext = pMyList->head->pNext;
	pMyList->head->pNext = pNew;
	pMyList->head->pNext->pLast = pNew;
}

//有头双向循环链表尾部删除
void DoubleCyclicListPopBack(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	NODE *p = pMyList->head;
	NODE *pNew = NULL;
	if (pMyList->head->pNext == NULL){
		return;
	}
	while (p->pNext != pMyList->head){
		pNew = p;
		p = p->pNext;
	}
	pNew->pNext = NULL;
	pNew->pNext = pMyList->head;
}

//有头双向循环链表头部删除
void DoubleCyclicListPopFront(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	NODE *pNew = pMyList->head->pNext;
	if (pNew == pMyList->head)
		return;
	pMyList->head->pNext = pNew->pNext;
	pNew->pNext->pLast = pMyList->head;
	free(pNew);
}

//按值查找
NODE*  DoubleCyclicListByFind(DoubleCyclicList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* pNew = pMyList->head->pNext;
	while (pNew != pMyList->head && pNew->data != val ){
			pNew = pNew->pNext;
		}
	if (pNew->data == val){
		return pNew;
	}
	else{
		return NULL;
	}
}

//求链表的长度
size_t DoubleCyclicListLength(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	NODE* pNew = pMyList->head->pNext;
	size_t len = 0;
	while (pNew != pMyList->head){
		pNew = pNew->pNext;
		len++;
	}
	return len;
}

//链表的清理
void DoubleCyclicListClear(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	NODE* pNew = pMyList->head->pNext;
	while (pNew != pMyList->head){
		pNew->pNext->pLast = pNew->pLast;
		pNew->pLast->pNext = pNew->pNext;
		free(pNew);
		pNew = pMyList->head->pNext;
	}
}

//链表的销毁
void DoubleCyclicListDestroy(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	DoubleCyclicListClear(pMyList);
	free(pMyList->head);
	pMyList->head =NULL;
}

//按值删除
void DoubleCyclicListByDel(DoubleCyclicList* pMyList, Elemtype val){
	assert(pMyList != nullptr);
	NODE* pNew = DoubleCyclicListByFind(pMyList, val);
	if (pNew == NULL){
		printf("您要删除的元素不存在！\n");
		return;
	}
	while (pNew != pMyList->head && pNew->data != val){
		pNew = pNew->pNext;
	}
	pNew->pLast->pNext = pNew->pNext;
	pNew->pNext->pLast = pNew->pLast;
	free(pNew);
	pNew = NULL;
}

//按值插入
void DoubleCyclicListByVal(DoubleCyclicList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* pNew = pMyList->head->pNext;
	while (pNew != pMyList->head && val > pNew->data){
		pNew = pNew->pNext;
	}
	NODE* q = BuyNode(val);
	q->pLast = pNew->pLast;
	q->pNext = pNew;
	pNew->pLast->pNext = q;
	pNew->pLast = q;
}

//反转链表
void DoubleCyclicLisReverse(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	//定义两个节点
	NODE* pNew = pMyList->head->pNext;
	NODE* s = pNew->pNext;
	//断开链表
	pNew->pNext = pMyList->head;
	pMyList->head->pLast = pNew;
	//头结点之后插入节点
	while (s != pMyList->head ){
		pNew = s;
		s = s->pNext;
		//插入节点
		pNew->pNext = pMyList->head->pNext;
		pNew->pLast = pMyList->head;
		pMyList->head->pNext = pNew;
		pNew->pNext->pLast = pNew;
	}
}

//链表的排序
void DoubleCyclicLisSort(DoubleCyclicList* pMyList){
	assert(pMyList != NULL);
	//定义两个节点
	NODE* pNew = pMyList->head->pNext;
	NODE* s = pNew->pNext;
	//断开链表
	pNew->pNext = pMyList->head;
	pMyList->head->pLast = pNew;
	//头结点之后插入节点
	while (s != pMyList->head){
		pNew = s;
		s = s->pNext;
		//寻找p的插入排序的位置
		NODE* temp = pMyList->head->pNext;
		while (temp != pMyList->head && temp->data < pNew->data){
			temp = temp->pNext;
		}
		    pNew->pNext = temp;
			pNew->pLast = temp->pLast;
			
			pNew->pNext->pLast = pNew;
			pNew->pLast->pNext = pNew;
			pNew = s;
	}
}


