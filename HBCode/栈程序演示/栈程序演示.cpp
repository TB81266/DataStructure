#include<iostream>
#include"stdlib.h"
using namespace std;

//定义一个结构体 有数据域和指针域 即为节点的数据类型
typedef struct Node{
public:
	int data;//数据域
	Node *pNext;//指针域 指向一个数据类型一样的内存单元，指向下一个地址
}NODE, *PNODE;

typedef struct Stack{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

//初始化需要几个参数呢？
void InitStack(PSTACK pS){
	pS->pTop = (PNODE)malloc(sizeof(NODE));//pS->pTop 指向分配节点的内存空间  而ptOp 指向pBottom 所以pBottom指向了新分配的内存空间
	//判断分配空间是否成功
	if (pS->pTop == NULL){
		cout << "分配内存失败！" << endl;
		exit(-1);
	}
	else{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL; //pS->Bottom->pNext = NULL;
	}
}

//压栈需要几个参数呢？ 是否需要返回值？不需要返回值因为 压栈在没有限制大小的情况下是不存在满的，一定会成功！所以不需要返回值
//压栈需要，总共4步
void push(PSTACK pS, int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));   //（1）分配空间,建立新的节点
	pNew->data = val;//（2） 将新节点的数据域变成val 也就是将值val付给pNew->data
	pNew->pNext = pS->pTop;//（3）将pS的旧的节点地址付给 新节点pNew的指针域
	pS->pTop = pNew;//（4）将pS->pTop 指向新的节点的顶部 也就是将新的节点的地址赋值给pS->pTop
}

//遍历需要几个参数呢？ 需要两个顶部和底部 由于顶部和底部都在S里面 因此需要一个参数pS
void TraverseStack(PSTACK pS){
	PNODE p = pS->pTop;//定义一个指针指向栈的顶部
	//当栈的顶部不等于栈的底部的值时，就执行 不停的输出
	while (p!= pS->pBottom){
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}

//判断出栈是否成功需要判断栈是否是空的
bool empty(PSTACK pS){
	if (pS->pBottom == pS->pTop){
		return true;
	}
	else{
		return false;
	}
}
//出栈需要几个参数呢？ 一般情况下需要一个，出哪一个栈即可，最好是能够加一个出栈的元素的返回值 便于后续的使用
//是否需要返回值呢？需要返回值，出栈可能有失败的情况 需要判断是否成功！
//把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中，如果出栈失败，返回false,否则返回true
bool pop(PSTACK pS, int* pVal){
	if (empty(pS)){//空了，显示 false
		return false;
	}
	else{//不空的话，删除栈中的元素
		PNODE r = pS->pTop; //定义一个指针r r指向栈顶
		*pVal = r->data;
		pS->pTop = r->pNext;//然后将r的地址付给pS->pTop 
		free(r);//释放r指向的空间
		r == NULL;
		return true;
	}
}

//清空 是指框架还在 里面没有元素了 
void clear(PSTACK pS){
	if (empty(pS)){
		return;
	}
	else{
		PNODE p = pS->pTop;
		PNODE q = NULL;
	
	while (p != pS->pBottom){
		q = p->pNext;
		free(p);
		p = q;
	   }
	pS->pTop = pS->pBottom;
	}
}

//销毁 是把所有的东西都清除 
void destory(PSTACK pS){

}
int main(){
	STACK S;//定义一个栈的变量S 里面存放了垃圾值
	int val;
	InitStack(&S);//初始化操作，建立一个空的栈
	push(&S, 1); //压栈
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	push(&S, 6);
	TraverseStack(&S);//遍历
	//出栈 首先判断一下 出栈是否成功  
	if (pop(&S, &val)){
		cout << "出栈成功,出栈的元素：" ;
		cout << val << " ";
	}
	else{
		cout << "出栈失败！" << endl;
	}
	cout << endl;
	TraverseStack(&S);//遍历
	cout << "clear 清空！" << endl;
	clear(&S);
	TraverseStack(&S);//遍历
	return 0;
}