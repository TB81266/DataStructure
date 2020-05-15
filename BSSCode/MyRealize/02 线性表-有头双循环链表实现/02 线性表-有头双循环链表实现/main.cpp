#include"HeadList.h"

int main(){  
	system("title ��ͷ������ʵ��");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	DoubleCyclicList MyList;//����һ������

	NODE *p = NULL;//����һ���ڵ�
	DoubleCyclicListInit(&MyList);//��ʼ������
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
				DoubleCyclicListPushBack(&MyList, val);
			}
			break;
		case 2:
			DoubleCyclicListShow(&MyList);
			break;
		case 3:
			printf("������Ҫ�����ֵ[��-1����]:>");
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
		    printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &val);
			p = DoubleCyclicListByFind(&MyList, val);
			if (p != NULL){
				printf("��Ҫ���ҵ�Ԫ�ش��ڣ�Ϊ��%d\n", p->data);
			}
			else{
				printf("��Ҫ���ҵ�Ԫ�ز����ڣ�\n");
			}
			break;
		case 8:
			DoubleCyclicLisReverse(&MyList); 
			break;
		case 9:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &val);
			DoubleCyclicListByVal(&MyList, val);
			break;
		case 10:
			printf("������Ҫɾ����ֵ:>");
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