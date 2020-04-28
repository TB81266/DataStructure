#include"SeqList.h"

void Menu(){
	printf("*****             ���Ա�->˳���           *****\n");
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
		printf("��ѡ�����ķ���>");
		scanf("%d", &item);
		if (item == 0){
			break;
		}
		switch (item){
		case 1:
			printf("��������Ҫ��β�������ֵ[��-1����]:>");
			//���� ���ʽȡ����ֵΪ ���ʽ��ֵ���жϵ�������
			while (scanf("%d", &val), val != -1){
				SeqListPush_back(&mylist, val);
			}
			break;
		case 2:
			printf("����������ͷ��Ҫ�����ֵ[��-1����]:>");
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
			printf("��������Ҫ�����λ�ã�>");
			scanf("%d", &pos);
			printf("��������Ҫ�����ֵ��>");
			scanf("%d", &val);
			SeqListInsertByPos(&mylist, pos, val);
			break;
		case 7:
			SeqListSort(&mylist);
			printf("��������Ҫ�����ֵ:>");
			scanf("%d", &val);
			SeqListInsertByVal(&mylist,val);
			break;
		case 8:
			printf("��������Ҫɾ����λ�ã�>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("��������Ҫɾ����ֵ:>");
			scanf("%d", &val);
			SeqListDeleteByVal(&mylist, val);
			break;
		case 10:
			printf("��������Ҫ���ҵ�ֵ����λ��ʲôλ�ã�:>");
			scanf("%d", &val);
			pos = SeqListfind_val(&mylist, val);
			if (pos == -1){
				printf("Ҫ���ҵ�ֵ������.\n");
			}
			printf("λ���ڣ�%d\n", pos);
			break;
		case 11:
			len = SeqListLength(&mylist);
			printf("˳���ĳ���Ϊlen = %d\n", len);
			break;
		case 12:
			printf("˳��������capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListSort(&mylist);
			printf("˳�������ɹ���\n");
			break;
		case 14:
			SeqListReverse(&mylist);
			printf("˳���ת�ɹ���\n");
			break;
		case 15:
			SeqListClear(&mylist);
			printf("������ݳɹ���\n");
			break;
		case 16:
			printf("��������Ҫɾ���ظ������֣�");
			scanf("%d", &val);
			printf("ɾ��ͬ����������size = %d\n",SeqListRemove_all_same(&mylist, val, size));
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