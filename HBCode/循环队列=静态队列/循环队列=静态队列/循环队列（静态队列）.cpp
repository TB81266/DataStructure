#include<iostream>
#include"malloc.h"
using namespace std;

typedef struct	Queue{
	int *pBase;
	int front;
	int rear;
}QUEUE;

void InitQueue(QUEUE* pQ){
	pQ->pBase = (int*)malloc(sizeof(int) * 6);	//pQ所指向的主函数中的Q对象的pBase成员，指向了24个字节 
	pQ->front = 0;
	pQ->rear = 0;
}

//如何判断队列满了？
bool FullQueue(QUEUE* pQ){
	if ((pQ->rear+1)%6  == pQ->front){
		return true;
	}
	else{
		return false;
	}
}

//入队（放在哪一个对象，放的值是多少）
bool EnQueue(QUEUE* pQ,int val){
	if (FullQueue(pQ)){
		cout << "入队失败！";
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

//出队
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
		cout << "出队成功,出队的元素为：" << val << " ";
	}
	else{
		cout << "出队失败！" << endl;
	}
	cout << endl;
	TraverseQueue(&Q);

	return 0;
}
