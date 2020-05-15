#include"HeadList.h"

int main(){  
	system("title 无头单链表实现");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	DoubleCyclicList MyList;//定义一个链表

	NODE *p = NULL;//定义一个节点
	DoubleCyclicListInit(&MyList);//初始化链表
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
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &val), val != -1){	
				DoubleCyclicListPushBack(&MyList, val);
			}
			break;
		case 2:
			DoubleCyclicListShow(&MyList);
			break;
		case 3:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &val), val != -1){
				DoubleCyclicListPushFront(&MyList, val);
			}
			break;
		case 4:
			DoubleCyclicListPopBack(&MyList); 
			break;
		case 5:
			DoubleCyclicListPopFront(&MyList); 
			break;
		case 6:
			printf("length = %d\n", DoubleCyclicListLength(&MyList)); 
			break;
		case 7:
		    printf("请输入要查找的值:>");
			scanf("%d", &val);
			p = DoubleCyclicListByFind(&MyList, val);
			if (p != NULL){
				printf("您要查找的元素存在，为：%d\n", p->data);
			}
			else{
				printf("您要查找的元素不存在！\n");
			}
			break;
		case 8:
			DoubleCyclicLisReverse(&MyList); 
			break;
		case 9:
			printf("请输入要插入的值:>");
			scanf("%d", &val);
			DoubleCyclicListByVal(&MyList, val);
			break;
		case 10:
			printf("请输入要删除的值:>");
			scanf("%d", &val);
			DoubleCyclicListByDel(&MyList, val);
			break;
		case 11:
			DoubleCyclicLisSort(&MyList);
			break;
		case 12:
			DoubleCyclicListClear(&MyList); 
			break;
		}
	}
	DoubleCyclicListDestroy(&MyList);
	return 0;
}