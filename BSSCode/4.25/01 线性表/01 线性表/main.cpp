#include"Seqlist.h"
void Menu(){
	printf("******************************************\n");
	printf("***[0]  EXIT                  [1] PushBack ***\n");
	printf("***[2]  DELETE                [3] MODIFY   ***\n");
	printf("***[4]  SHOW                  [5] CLEAR    ***\n");
}
int main(){
	ElemType item;
	SeqList MyList;
	SeqListInit(&MyList);
	int select = 1;
	while (select){
		Menu();
		int select;
		printf("请选择您的服务：>");
		scanf("%d", &select);
		if (select == 0){
			break;
		}
		switch (select){
		case 1:	
			printf("请输入您要插入的数据(以 -1 结束)：>");
			while (scanf("%d", &item), item != -1){
				SeqListPush_back(&MyList, item);
			}
			break;
		case 2:
			break;
		case 3:
			printf("请输入您要插入的数据(以 -1 结束)：>");
			while (scanf("%d", &item), item != -1){
				SeqListPush_front(&MyList, item);
			}
			break;
		case 4:
			SeqListShow(&MyList);
			break;
		case 5:
			SeqListDestroy(&MyList);
			break;
		default:
			break;
		}
	}
	printf("ByeBye...\n");
	return 0;
}