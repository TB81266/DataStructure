#include"list.h"

int main(){
	system("title ��ͷ������");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;
	printf("��������������ĳ��ȣ�");
	scanf("%d", &pos);
	LinkList MyList;//����һ������

	NODE *p;//����һ���ڵ�

	LinkListInit(&MyList);//��ʼ������
	LinkListCreate(&MyList,pos);//��������
    //LinkListCreateTail(&MyList);//β�巨������ͷ������
	//LinkListCreateHead(&MyList);//ͷ�巨������ͷ������
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
			if (!LinkListIsEmpty(&MyList)){
				printf("LinkList��Ϊ�գ�\n");
				TraverseLinkList(MyList);
			}
			else{
				printf("LinkListΪ�գ�\n");
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
			/*printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &item);*/
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			//DCListSort(&mylist);
		/*	printf("������Ҫ���������:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);*/
			break;
		case 8:
			/*printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);*/
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			/*printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);*/
			break;
		case 10:
			/*printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ������.\n");
			else
				printf("Ҫ���ҵ�ֵΪ:> %d\n", p->data);*/
			break;
		case 11:
			/*printf("seqlist len = %d\n", DCListLength(&mylist));*/
			break;
		case 12:
			//printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			/*DCListSort(&mylist);
			printf("˳�������ɹ�......\n");*/
			break;
		case 14:
			/*DCListReverse(&mylist);*/
			break;
		case 15:
			/*DCListClear(&mylist);
			printf("������ݱ�ɹ�......\n");*/
			break;
		case 16:
			/*printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);*/
			//SeqListRemoveAll(&mylist, key);
			break;
		}
	}
	
	return 0;
}