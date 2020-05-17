#include"SeqStack.h"

int main(){
	system("title 顺序栈的实现");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	SeqStack Stack;//定义一个顺序栈

	SeqStackInit(&Stack);//初始化链表
	while (1){
		Menu();
		printf("请输入您的选择：>");
		scanf("%d", &item);
		if (item == 0){
			printf("程序结束!byebye\n");
			break;
		}
		switch (item){
		case 1:
			printf("请输入要入栈的值[以-1结束]:>");
			while (scanf("%d", &val), val != -1){
				SeqStackPushBack(&Stack, val);
			}
			break;
		case 2:
		    SeqStackPop(&Stack);
			break;
		case 3:
			SeqStackShow(&Stack);
			break;
		case 4:
			printf("您要查找的顺序栈的栈顶元素值为：%d\n", SeqStackTop(&Stack));
			break;
		case 5:
			SeqStackClear(&Stack);
			break;
		case 6:
			//SeqStackDestroy(&Stack);
			break;
		}
	}
	SeqStackDestroy(&Stack);
	return 0;
}