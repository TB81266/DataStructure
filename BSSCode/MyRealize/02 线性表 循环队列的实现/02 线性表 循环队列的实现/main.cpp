#include"CycleQueue.h"

int main(){
	system("title 顺序栈的实现");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	CycleQueue CQueue;//定义一个顺序栈

	CycleQueueInit(&CQueue);//初始化链表
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
			printf("请输入要入对的值[以-1结束]:>");
			while (scanf("%d", &val), val != -1){
				CycleQueueEnQueue(&CQueue, val);
			}
			break;
		case 2:
			CycleQueueDeQueue(&CQueue);
			break;
		case 3:
			CycleQueueShow(&CQueue);
			break;
		case 4:
			printf("您要查找的顺序栈的栈顶元素值为：%d\n", CycleQueueTop(&CQueue));
			break;
		case 5:
			CycleQueueClear(&CQueue);
			break;
		case 6:
			//CycleQueueDestroy(&CQueue);
			break;
		}
	}
	CycleQueueDestroy(&CQueue);
	return 0;
}