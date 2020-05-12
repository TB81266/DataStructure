#include"HeadList.h"

int main(){  
	system("title 无头单链表实现");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	NoHeadList MyList;//定义一个链表

	NODE *p = NULL;//定义一个节点

	NoHeadListInit(&MyList);//初始化链表
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
				NoHeadListPushBack(&MyList, val);
			}	
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &val), val != -1){
				NoHeadListPushFront(&MyList, val);
			}
			break;
		case 3:
			NoHeadListTraverse(&MyList);
			break;
		case 4:
			NoHeadListPopBack(&MyList);
			break;
		case 5:
			NoHeadListPopFront(&MyList);
			break;
		case 6:
			printf("length = %d\n", NoHeadListLength(&MyList));
			break;
		case 7:
		    printf("请输入要插入的值:>");
			scanf("%d", &val);
			p = NoHeadListByFind(&MyList, val);
			if (p != NULL){
				printf("您要查找的元素存在，为：%d\n", p->data);
			}
			else{
				printf("您要查找的元素不存在！\n");
			}
			break;
		case 8:
			NoHeadListReverse(&MyList);
			break;
		case 9:
			printf("请输入要插入的值:>");
			scanf("%d", &val);
			NoHeadListInsertByVal(&MyList, val);
			break;
		case 10:
			printf("请输入要删除的值:>");
			scanf("%d", &val);
			NoHeadListByDel(&MyList, val);
			break;
		case 11:
			printf("请输入要删除的值:>");
			scanf("%d", &val);
			NoHeadListRemoveAllSameElement(&MyList, val);
			break;
		}
	}
	NoHeadListDestroy(&MyList);
	return 0;
}