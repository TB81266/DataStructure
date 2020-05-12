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

//��ʼ��
void NoHeadListInit(NoHeadList* pMyList){
	pMyList->head = NULL;
}

//����ڵ�
static NODE* BuyNode(Elemtype val){
	NODE* pNew = (NODE*)malloc(sizeof(NODE));
	assert(pNew != NULL);
	pNew->data = val;
	pNew->pNext = NULL;
	return pNew;
}


//��ͷ��㵥�����β����������
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

//��������
void NoHeadListTraverse(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE* pNew = pMyList->head;
	while (pNew != NULL){
		printf("%d->", pNew->data);
		pNew = pNew->pNext;
	}
	printf("OVER!\n");
}

//ͷ�巨������ͷ��㵥����
void NoHeadListPushFront(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* pNew = BuyNode(val);
	pNew->pNext = pMyList->head;
	pMyList->head = pNew;
}

//β��ɾ��
void NoHeadListPopBack(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE * pNew01, *pNew02 = NULL;//���������ڵ� ��һ����Ϊ�˱������� �ڶ�����Ϊ��ɾ��β�ڵ�
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
		pNew02->pNext = NULL;//ɾ�����һ���ڵ� ָ���  Ȼ��free��
	}
	free(pNew01);
}

//ͷ��ɾ
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

//��ֵ����
NODE*  NoHeadListByFind(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* p = pMyList->head;
	//��ѧ�߳��õ�д��
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

//��ֵ����
void NoHeadListInsertByVal(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != NULL);
	NODE* p = pMyList->head;
	NODE* pre = NULL;
	NODE* pNew = BuyNode(val);
	//��ҪҪ�����ֵ�ƶ�ҪҪ�����λ��
	while (p != NULL && val > p->data){
		pre = p;
		p = p->pNext;
	}
	//Ҫ�����λ���ǵ�һ���ڵ��ǰ��
	if (pre == NULL){
		pNew->pNext = p;
		pMyList->head = pNew;
	}
	//���뵽����������λ��
	else{
		pNew->pNext = pre->pNext;
		pre->pNext = pNew;
	}
}

//��ֵɾ��
void NoHeadListByDel(NoHeadList* pMyList, Elemtype val){
	assert(pMyList != nullptr);
	NODE* pre = NULL;
	NODE* p = NoHeadListByFind(pMyList, val);
	if (p == NULL){
		printf("��Ҫɾ����Ԫ�ز����ڣ�\n");
	}
	if (p == pMyList->head){
		pMyList->head = p->pNext;
	}
	else{
		pre = pMyList->head;
		while (pre->pNext != p){
			pre = pre->pNext;
		}
		//ɾ���ڵ�
		pre->pNext = p->pNext;
	 }
	free(p);//�����ڴ�й©
}
//�Լ�д��
	/*NODE* pre = NULL; 
	NODE *temp = NULL;
	while (p != NULL && p->data != val){
		pre = p;
		p = p->pNext;
	}
	temp = pre->pNext;
	pre->pNext = pre->pNext->pNext;
	free(temp);*/

//������ĳ���
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


//��ת����
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

//���������
void NoHeadListSort(NoHeadList* pMyList){
	assert(pMyList != NULL);
}

//��ֵɾ��������ͬ��Ԫ��
void NoHeadListRemoveAllSameElement(NoHeadList* pMyList, Elemtype val){

}

//���������
void NoHeadListClear(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NODE* p = pMyList->head;
	while (p != NULL){
		pMyList->head = p->pNext;
		free(p);
		p = pMyList->head;
	}
}

//��������ݻ�
void NoHeadListDestroy(NoHeadList* pMyList){
	assert(pMyList != NULL);
	NoHeadListClear(pMyList);
	pMyList->head = NULL;
}