#include"HeadList.h"

void Menu(){
	printf("********************************************************\n");
	printf("* [1] NoHeadListPushBack     [2] NoHeadListPushFront   *\n");
	printf("* [3] NoHeadListTraverse     [4] NoHeadListPopBack     *\n");
	printf("* [5] NoHeadListPopFront     [6] NoHeadListLength      *\n");
	printf("* [7] NoHeadListByFind       [8] NoHeadListReverse     *\n");
	printf("* [9] NoHeadListInsertByVal  [10] NoHeadListByDel      *\n");
	printf("* [11] NoHeadListRemoveAllSameElement                  *\n");
	printf("********************************************************\n");

}

//初始化
void NoHeadListInit(NoHeadList* pMyList){
	pMyList->head = NULL;
}

//申请节点
static NODE* BuyNode(Elemtype val){
	NODE* pNew = (NODE*)malloc(sizeof(NODE));
	assert(pNew != NULL);
	pNew->data = val;
	pNew->pNext = NULL;
	return pNew;
}


//无头结点单链表的尾部插入数据
void NoHeadListPushBack(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* pNew = BuyNode(val);
	
	if (pMyList->head == NULL){
		pMyList->head = pNew;
		return;
	}
	NODE *p = pMyList->head;

	while (p->pNext != NULL){
		p = p->pNext;
	}
	p->pNext = pNew;
}

//遍历链表
void NoHeadListTraverse(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE* pNew = pMyList->head;
	while (pNew != NULL){
		printf("%d->", pNew->data);
		pNew = pNew->pNext;
	}
	printf("OVER!\n");
}

//头插法创建有头结点单链表
void NoHeadListPushFront(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* pNew = BuyNode(val);
	pNew->pNext = pMyList->head;
	pMyList->head = pNew;
}

//尾部删除
void NoHeadListPopBack(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE * pNew01, *pNew02 = NULL;//申请两个节点 第一个是为了保护链表 第二个是为了删除尾节点
	if (pMyList->head == NULL){
		return;
	}
	pNew01 = pMyList->head;
	if (pNew01->pNext == NULL){
		pMyList->head = NULL;
		return;
	}
	else{
		while (pNew01->pNext != NULL){
			pNew02 = pNew01;
			pNew01 = pNew01->pNext;
		}
		pNew02->pNext = NULL;//删除最后一个节点 指向空  然后free掉
	}
	free(pNew01);
}

//头部删
void NoHeadListPopFront(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE* p = pMyList->head;
	if (pMyList->head == NULL){
		return;
	}
	else{
			pMyList->head = p->pNext;
			free(p);
	}
}

//按值查找
NODE*  NoHeadListByFind(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* p = pMyList->head;
	//初学者常用的写法
	/*while (p != NULL){
		if (p->data != val){
			p = p->pNext;
		}
		else{
			return p;
		}
	}
	return NULL;*/

	while (p != NULL && p->data != val){
		p = p->pNext;
	}
	return p;
}

//按值插入
void NoHeadListInsertByVal(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* p = pMyList->head;
	NODE* pre = NULL;
	NODE* pNew = BuyNode(val);
	//将要要插入的值移动要要插入的位置
	while (p != NULL && val > p->data){
		pre = p;
		p = p->pNext;
	}
	//要插入的位置是第一个节点的前面
	if (pre == NULL){
		pNew->pNext = p;
		pMyList->head = pNew;
	}
	//插入到链表的里面的位置
	else{
		pNew->pNext = pre->pNext;
		pre->pNext = pNew;
	}
}

//按值删除
void NoHeadListByDel(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != nullptr);
	NODE* pre = NULL;
	NODE* p = NoHeadListByFind(pMyList, val);
	if (p == NULL){
		printf("您要删除的元素不存在！\n");
	}
	if (p == pMyList->head){
		pMyList->head = p->pNext;
	}
	else{
		pre = pMyList->head;
		while (pre->pNext != p){
			pre = pre->pNext;
		}
		//删除节点
		pre->pNext = p->pNext;
	 }
	free(p);//避免内存泄漏
}
//自己写的
	/*NODE* pre = NULL; 
	NODE *temp = NULL;
	while (p != NULL && p->data != val){
		pre = p;
		p = p->pNext;
	}
	temp = pre->pNext;
	pre->pNext = pre->pNext->pNext;
	free(temp);*/

//求链表的长度
size_t NoHeadListLength(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE * p = pMyList->head;
	size_t len = 0;
	while (p != NULL){
		len++;
		p = p->pNext;
	}
	return len;
}


//反转链表
void NoHeadListReverse(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE* pNew = NULL;
	NODE* p = pMyList->head->pNext;
	if (p == NULL){
		return;
	}
	pMyList->head->pNext = NULL;
	while (p != NULL){
		pNew = p->pNext;
		p->pNext = pMyList->head;
		pMyList->head = p;
		p = pNew;
	}

}

//链表的排序
void NoHeadListSort(NoHeadList* pMyList){
	assert(pMyList != NULL);
}

//按值删除所有相同的元素
void NoHeadListRemoveAllSameElement(NoHeadList* pMyList, Elemtype val){

}

//链表的清理
void NoHeadListClear(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE* p = pMyList->head;
	while (p != NULL){
		pMyList->head = p->pNext;
		free(p);
		p = pMyList->head;
	}
}

//整个链表摧毁
void NoHeadListDestroy(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NoHeadListClear(pMyList);
	pMyList->head = NULL;
}