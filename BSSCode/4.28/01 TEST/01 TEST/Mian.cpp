#include"seqlist.h"
#include"list.h"

int main()
{
	SList mylist;
	SListInit(&mylist);

	SListNode *p;
	ElemType item, key;
	int select = 1;
	int pos = 0;
	while (select)
	{
		printf("***********************************************\n");
		printf("* [1] push_back              [2] push_front   *\n");
		printf("* [3] show_list              [0] quit_system  *\n");
		printf("* [4] pop_back               [5] pop_front    *\n");
		printf("* [*6] insert_pos            [7] insert_val   *\n");
		printf("* [*8] delete_pos            [9] delete_val   *\n");
		printf("* [10] find_val              [11] length      *\n");
		printf("* [*12] capacity             [13] sort        *\n");
		printf("* [14] reverse               [15] clear       *\n");
		printf("* [16] remove_all  �Լ�ʵ��                   *\n");
		printf("***********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			//SeqListSort(&mylist);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = SListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ������.\n");
			else
				printf("Ҫ���ҵ�ֵΪ:> %d\n", p->data);
			break;
		case 11:
			printf("seqlist len = %d\n", SListLength(&mylist));
			break;
		case 12:
			//printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SListSort(&mylist);
			printf("˳�������ɹ�......\n");
			break;
		case 14:
			SListReverse(&mylist);
			break;
		case 15:
			SListClear(&mylist);
			printf("������ݱ��ɹ�......\n");
			break;
		case 16:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			break;
		}
	}
	SListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}

/*
void main()
{
int a = 0;
int b = 2;
//int value = ++a && ++b;
int value = a++ || ++b;  //��·��ֵ
printf("a = %d\n", a); //1

printf("b = %d\n", b); //
}
void Test_List()
{
List mylist; //
ListInit(&mylist);
//ListCreate_Tail(&mylist);
ListCreate_Head(&mylist);
ListShow(mylist);
}
void main()
{
Test_List();
}
/*
int main()
{
SeqList mylist;
SeqListInit(&mylist);
ElemType item, key;
int select = 1;
int pos = 0;
while(select)
{
printf("***********************************************\n");
printf("* [1] push_back              [2] push_front   *\n");
printf("* [3] show_list              [0] quit_system  *\n");
printf("* [4] pop_back               [5] pop_front    *\n");
printf("* [6] insert_pos             [7] insert_val   *\n");
printf("* [8] delete_pos             [9] delete_val   *\n");
printf("* [10] find_val              [11] length      *\n");
printf("* [12] capacity              [13] sort        *\n");
printf("* [14] reverse               [15] clear       *\n");
printf("* [16] remove_all  �Լ�ʵ��                   *\n");
printf("***********************************************\n");
printf("��ѡ��:>");
scanf("%d", &select);
if(select == 0)
break;
switch(select)
{
case 1:
printf("������Ҫ�����ֵ[��-1����]:>");
while(scanf("%d", &item), item!=-1)
{
SeqListPushBack(&mylist, item);
}
break;
case 2:
printf("������Ҫ�����ֵ[��-1����]:>");
while(scanf("%d", &item), item!=-1)
{
SeqListPushFront(&mylist, item);
}
break;
case 3:
SeqListShow(&mylist);
break;
case 4:
SeqListPopBack(&mylist);
break;
case 5:
SeqListPopFront(&mylist);
break;
case 6:
printf("������Ҫ�����λ��:>");
scanf("%d", &pos);
printf("������Ҫ���������:>");
scanf("%d", &item);
SeqListInsertByPos(&mylist, pos, item);
break;
case 7:
SeqListSort(&mylist);
printf("������Ҫ���������:>");
scanf("%d", &item);
SeqListInsertByVal(&mylist, item);
break;
case 8:
printf("������Ҫɾ����λ��:>");
scanf("%d", &pos);
SeqListDeleteByPos(&mylist, pos);
break;
case 9:
printf("������Ҫɾ����ֵ:>");
scanf("%d", &key);
SeqListDeleteByVal(&mylist, key);
break;
case 10:
printf("������Ҫ���ҵ�ֵ:>");
scanf("%d", &key);
pos = SeqListFind(&mylist, key);
if(pos == -1)
printf("Ҫ���ҵ�ֵ������.\n");
else
printf("Ҫ���ҵ�ֵ��λ��Ϊ:> %d\n", pos);
break;
case 11:
printf("seqlist len = %d\n", SeqListLength(&mylist));
break;
case 12:
printf("seqlist capacity = %d\n", SeqListCapacity(&mylist));
break;
case 13:
SeqListSort(&mylist);
printf("˳�������ɹ�......\n");
break;
case 14:
SeqListReverse(&mylist);
break;
case 15:
SeqListClear(&mylist);
printf("������ݱ��ɹ�......\n");
break;
case 16:
printf("������Ҫɾ����ֵ:>");
scanf("%d", &key);
SeqListRemoveAll(&mylist, key);
break;
}
}
SeqListDestroy(&mylist);
printf("GoodBye......\n");
return 0;
}
*/	