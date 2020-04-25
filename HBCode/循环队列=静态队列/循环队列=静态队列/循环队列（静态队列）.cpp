#include<iostream>
#include"malloc.h"
using namespace std;

typedef struct	Queue{
	int *pBase;
	int front;
	int rear;
}QUEUE;

void InitQueue(QUEUE* pQ){
	pQ->pBase = (int*)malloc(sizeof(int) * 6);	//pQ��ָ����������е�Q�����pBase��Ա��ָ����24���ֽ� 
	pQ->front = 0;
	pQ->rear = 0;
}

//����ж϶������ˣ�
bool FullQueue(QUEUE* pQ){
	if ((pQ->rear+1)%6  == pQ->front){
		return true;
	}
	else{
		return false;
	}
}

//��ӣ�������һ�����󣬷ŵ�ֵ�Ƕ��٣�
bool EnQueue(QUEUE* pQ,int val){
	if (FullQueue(pQ)){
		cout << "���ʧ�ܣ�";
		return false;
	}
	else{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}
}

void TraverseQueue(QUEUE* pQ){
	int i = pQ->front;
	while (i != pQ->rear){
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	cout << endl;
}

bool EmptyQueue(QUEUE* pQ){
	if (pQ->front == pQ->rear){
		return true;
	}
	else{
		return false;
	}
}

//����
bool OutQueue(QUEUE* pQ,int * pVal){
	if (EmptyQueue(pQ)){
		return false;
	}
	else{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}

int main(){
	Queue Q;
	int val;
	InitQueue(&Q);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	EnQueue(&Q, 4);
	EnQueue(&Q, 5); 
	TraverseQueue(&Q);
	if (OutQueue(&Q, &val)){
		cout << "���ӳɹ�,���ӵ�Ԫ��Ϊ��" << val << " ";
	}
	else{
		cout << "����ʧ�ܣ�" << endl;
	}
	cout << endl;
	TraverseQueue(&Q);

	return 0;
}
