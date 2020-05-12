#include"HeadList.h"

int main(){  
	system("title ��ͷ������ʵ��");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	NoHeadList MyList;//����һ������

	NODE *p = NULL;//����һ���ڵ�

	NoHeadListInit(&MyList);//��ʼ������
	while (1){
		Menu();
		printf("����������ѡ��>");
		scanf("%d", &item);
		if (item == 0){
			printf("�������!byebye\n");
			break;
		}
		switch (item){
		case 1:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &val), val != -1){
				NoHeadListPushBack(&MyList, val);
			}	
			break;
		case 2:
			printf("������Ҫ�����ֵ[��-1����]:>");
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
		    printf("������Ҫ�����ֵ:>");
			scanf("%d", &val);
			p = NoHeadListByFind(&MyList, val);
			if (p != NULL){
				printf("��Ҫ���ҵ�Ԫ�ش��ڣ�Ϊ��%d\n", p->data);
			}
			else{
				printf("��Ҫ���ҵ�Ԫ�ز����ڣ�\n");
			}
			break;
		case 8:
			NoHeadListReverse(&MyList);
			break;
		case 9:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &val);
			NoHeadListInsertByVal(&MyList, val);
			break;
		case 10:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &val);
			NoHeadListByDel(&MyList, val);
			break;
		case 11:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &val);
			NoHeadListRemoveAllSameElement(&MyList, val);
			break;
		}
	}
	NoHeadListDestroy(&MyList);
	return 0;
}