# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

//ÿһ�������������ͣ�����ָ�����������
typedef struct Node
{
	int data; //������
	struct Node * pNext; //ָ����
}NODE, *PNODE; //NODE�ȼ���struct Node    PNODE�ȼ���struct Node *

//��������
PNODE create_list(void);  //��������
void traverse_list(PNODE pHead);  //��������
bool is_empty(PNODE pHead);  //�ж������Ƿ�Ϊ��
int length_list(PNODE);  //����������
bool insert_list(PNODE pHead, int pos, int val);  //��pHead��ָ�������ĵ�pos���ڵ��ǰ�����һ���µĽ�㣬�ýڵ��ֵ��val�� ����pos��ֵ�Ǵ�1��ʼ
bool delete_list(PNODE pHead, int pos, int * pVal);  //ɾ��������pos���ڵ㣬����ɾ���Ľ���ֵ����pVal��ָ��ı�����,  ����pos��ֵ�Ǵ�1��ʼ
void sort_list(PNODE);  //��������������


int main(void)
{
	PNODE pHead = NULL; //�ȼ��� struct Node * pHead = NULL;
	int val;
	pHead = create_list();  //create_list()���ܣ�����һ����ѭ����������������������ͷ���ĵ�ַ����pHead
	traverse_list(pHead);

	//insert_list(pHead, -4, 33);
	if (delete_list(pHead, 4, &val))
	{
		printf("ɾ���ɹ�����ɾ����Ԫ����: %d\n", val);
	}
	else
	{
		printf("ɾ��ʧ��!��ɾ����Ԫ�ز�����!\n");
	}

	traverse_list(pHead);

	//int len = length_list(pHead);
	//printf("�����ĳ�����%d\n", len);

	//sort_list(pHead);
	//traverse_list(pHead);

	/*	if ( is_empty(pHead) )
	printf("����Ϊ��!\n");
	else
	printf("��������!\n");
	*/
	return 0;
}

PNODE create_list()
{
	int len;//���������Ч�ڵ�ĸ���
	int i;
	int val;//������ʱ����û�����Ľ���ֵ
	//������һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("����ʧ��, ������ֹ!\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("����������Ҫ���ɵ������ڵ�ĸ���: len = ");
	scanf("%d", &len);

	for (i = 0; i<len; ++i)
	{
		printf("�������%d���ڵ��ֵ: ", i + 1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("����ʧ��, ������ֹ!\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}

	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while (NULL != p)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;
	while (NULL != p){
		++len;
		p = p->pNext;
	}
	return len;
}

void sort_list(PNODE pHead){
	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;

	for (i = 0, p = pHead->pNext; i<len - 1; ++i, p = p->pNext){
		for (j = i + 1, q = p->pNext; j<len; ++j, q = q->pNext){
			if (p->data > q->data){  //�����������е�:  a[i] > a[j]
				t = p->data;//�����������е�:  t = a[i];
				p->data = q->data; //�����������е�:  a[i] = a[j];
				q->data = t; //�����������е�:  a[j] = t;
			}
		}
	}
	return;
}

//��pHead��ָ�������ĵ�pos���ڵ��ǰ�����һ���µĽ�㣬�ýڵ��ֵ��val�� ����pos��ֵ�Ǵ�1��ʼ
bool insert_list(PNODE pHead, int pos, int val){
	int i = 0;
	PNODE p = pHead;
	while (NULL != p && i<pos - 1){
		p = p->pNext;
		++i;
	}
	if (i>pos - 1 || NULL == p)
		return false;

	//���������ִ�е���һ��˵��p�Ѿ�ָ���˵�pos-1�����,����pos-1���ڵ��Ƿ��������ν
	//�����µĽ��
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew){
		printf("��̬�����ڴ�ʧ��!\n");
		exit(-1);
	}
	pNew->data = val;

	//���µĽ�����p�ڵ�ĺ���
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;
}


bool delete_list(PNODE pHead, int pos, int * pVal){
	int i = 0;
	PNODE p = pHead;

	while (NULL != p->pNext && i<pos - 1){
		p = p->pNext;
		++i;
	}

	if (i>pos - 1 || NULL == p->pNext)
		return false;

	//���������ִ�е���һ��˵��p�Ѿ�ָ���˵�pos-1����㣬���ҵ�pos���ڵ��Ǵ��ڵ�
	PNODE q = p->pNext;  //qָ���ɾ���Ľ��
	*pVal = q->data;

	//ɾ��p�ڵ����Ľ��
	p->pNext = p->pNext->pNext;

	//�ͷ�q��ָ��Ľڵ���ռ���ڴ�
	free(q);
	q = NULL;
	return true;

}