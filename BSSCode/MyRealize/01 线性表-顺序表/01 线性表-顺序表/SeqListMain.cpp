#include"SeqList.h"

void Menu(){
	printf("*****             线性表->顺序表           *****\n");
	printf("***********************************************\n");
	printf("* [1] push_back              [2] push_front    *\n");
	printf("* [3] show_list              [0] quit_system   *\n");
	printf("* [4] pop_back               [5] pop_front     *\n");
	printf("* [6] insert_pos             [7] insert_val    *\n");
	printf("* [8] delete_pos             [9] delete_val    *\n");
	printf("* [10] find_val              [11] length       *\n");
	printf("* [12] capacity              [13] sort         *\n");
	printf("* [14] reverse               [15] clear        *\n");
	printf("* [16] remove_all_same                         *\n");
	printf("************************************************\n");
}

int main(){
	int len = 0;
	int pos = 0;
	int size = 0;
	ElemType item,val;
	SeqList mylist;
	SeqListInit(&mylist);
	while (1){
		Menu();
		printf("请选择您的服务：>");
		scanf("%d", &item);
		if (item == 0){
			break;
		}
		switch (item){
		case 1:
			printf("请输入您要从尾部插入的值[以-1结束]:>");
			//逗号 表达式取最后的值为 表达式的值（判断的条件）
			while (scanf("%d", &val), val != -1){
				SeqListPush_back(&mylist, val);
			}
			break;
		case 2:
			printf("请输入您从头部要插入的值[以-1结束]:>");
			while (scanf("%d", &val), val != -1){
				SeqListpush_front(&mylist, val);
			}
			break;
		case 3:
			SeqListshow_list(&mylist);
			break;
		case 4:
			SeqListpop_back(&mylist, val);	
			break;
		case 5:
			SeqListpop_front(&mylist, val);
			break;
		case 6:
			printf("请输入您要插入的位置：>");
			scanf("%d", &pos);
			printf("请输入您要插入的值：>");
			scanf("%d", &val);
			SeqListInsertByPos(&mylist, pos, val);
			break;
		case 7:
			SeqListSort(&mylist);
			printf("请输入您要插入的值:>");
			scanf("%d", &val);
			SeqListInsertByVal(&mylist,val);
			break;
		case 8:
			printf("请输入您要删除的位置：>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入您要删除的值:>");
			scanf("%d", &val);
			SeqListDeleteByVal(&mylist, val);
			break;
		case 10:
			printf("请输入您要查找的值——位于什么位置？:>");
			scanf("%d", &val);
			pos = SeqListfind_val(&mylist, val);
			if (pos == -1){
				printf("要查找的值不存在.\n");
			}
			printf("位置在：%d\n", pos);
			break;
		case 11:
			len = SeqListLength(&mylist);
			printf("顺序表的长度为len = %d\n", len);
			break;
		case 12:
			printf("顺序表的容量capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListSort(&mylist);
			printf("顺序表排序成功！\n");
			break;
		case 14:
			SeqListReverse(&mylist);
			printf("顺序表反转成功！\n");
			break;
		case 15:
			SeqListClear(&mylist);
			printf("清除数据成功！\n");
			break;
		case 16:
			printf("请输入您要删除重复的数字：");
			scanf("%d", &val);
			printf("删除同样的数字有size = %d\n",SeqListRemove_all_same(&mylist, val, size));
			break;
		case 17:
			break;
		case 18:
			break;
		default:
			break;
		}
	}
	return 0;
}