#include"list.h"

int main(){
	system("title 无头单链表");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;
	printf("请输入您的链表的长度：");
	scanf("%d", &pos);
	LinkList MyList;//定义一个链表

	NODE *p;//定义一个节点

	LinkListInit(&MyList);//初始化链表
	LinkListCreate(&MyList,pos);//创建链表
    //LinkListCreateTail(&MyList);//尾插法创建无头单链表
	//LinkListCreateHead(&MyList);//头插法创建无头单链表
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
			if (!LinkListIsEmpty(&MyList)){
				printf("LinkList不为空：\n");
				TraverseLinkList(MyList);
			}
			else{
				printf("LinkList为空！\n");
			}
			break;
		case 2:
			InsertLinkList(&MyList, pos, val);
			break;
		case 3:
			TraverseLinkList(MyList);
			break;
		case 4:
		/*	DCListPopBack(&mylist);*/
			break;
		case 5:
			/*DCListPopFront(&mylist);*/
			break;
		case 6:
			/*printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);*/
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			//DCListSort(&mylist);
		/*	printf("请输入要插入的数据:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);*/
			break;
		case 8:
			/*printf("请输入要删除的位置:>");
			scanf("%d", &pos);*/
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			/*printf("请输入要删除的值:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);*/
			break;
		case 10:
			/*printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if (p == NULL)
				printf("要查找的值不存在.\n");
			else
				printf("要查找的值为:> %d\n", p->data);*/
			break;
		case 11:
			/*printf("seqlist len = %d\n", DCListLength(&mylist));*/
			break;
		case 12:
			//printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			/*DCListSort(&mylist);
			printf("顺序表排序成功......\n");*/
			break;
		case 14:
			/*DCListReverse(&mylist);*/
			break;
		case 15:
			/*DCListClear(&mylist);
			printf("清除数据表成功......\n");*/
			break;
		case 16:
			/*printf("请输入要删除的值:>");
			scanf("%d", &key);*/
			//SeqListRemoveAll(&mylist, key);
			break;
		}
	}
	
	return 0;
}