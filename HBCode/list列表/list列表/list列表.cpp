#include<iostream>
using namespace std;

typedef struct Node{
	int data;
	struct Node* pNext;
}NODE,* PNODE;

PNODE CreatList(){
	int len;
	int val;
	cout << "���������������Ч���ȣ�";
	cin >> len;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL){
		cout << "�����ڴ�ʧ�ܣ�";
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	for (int i = 0; i < len; i++){
		cout << "������" << i << "��ֵΪ��";
		cin >> val;
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL){
			cout << "�����ڴ�ʧ�ܣ�";
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

void TraverseList(PNODE pHead){
	cout << "����������ʵ�֣�" << endl;
	PNODE p = pHead->pNext;
	while (p != NULL){
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}

int LengthList(PNODE pHead){
	PNODE p = pHead->pNext;
	int len = 0;
	while (p != NULL){
		len++;
		p = p->pNext;
	}
	cout << "length = " << len << endl;
	return len;
}

bool EmptyList(PNODE pHead){
	if (pHead->pNext == NULL){
		return true;
	}
	else{
		return false;
	}
}
bool InsertList(PNODE pHead, int pos, int val){
	if (EmptyList(pHead)){
		return false;
	}
	PNODE p = pHead;
	for (int i = 0; i < pos-1; i++){
		p = p->pNext;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL){
		cout << "�����ڴ�ʧ�ܣ�";
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}

void SortList(PNODE pHead){
	int i, j, t;
	PNODE p, q;
	int len = LengthList(pHead);
	for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext){
		for (j = i + 1, q = p->pNext; j < len ; j++, q = q->pNext){
			if (p->data < q->data){
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
}

bool DeleteList(PNODE pHead,int pos,int* pVal){
	if (EmptyList(pHead)){
		return true;
	}
	PNODE p = pHead;
	for (int i = 0; i < pos - 1; i++){
		p = p->pNext;
	}
	PNODE q = p->pNext;
	*pVal = q->data;
	p->pNext = p->pNext->pNext;
	free(q);
	return false;
}

int main(){
	int val;
	PNODE pHead = NULL;
	pHead = CreatList();
	TraverseList(pHead);
	LengthList(pHead);
	InsertList(pHead,2, 9);
	TraverseList(pHead);
	SortList(pHead);
	TraverseList(pHead);
	if (DeleteList(pHead, 3, &val)){
		cout << "ɾ��ʧ�ܣ�" << endl;
	}
	else{
		cout << "ɾ����Ԫ��Ϊ��" << val << endl;

	}
	TraverseList(pHead);
	return 0;
}