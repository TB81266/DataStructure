#include"SeqStack.h"

int main(){
	system("title ˳��ջ��ʵ��");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	SeqStack Stack;//����һ��˳��ջ

	SeqStackInit(&Stack);//��ʼ������
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
			printf("������Ҫ��ջ��ֵ[��-1����]:>");
			while (scanf("%d", &val), val != -1){
				SeqStackPushBack(&Stack, val);
			}
			break;
		case 2:
		    SeqStackPop(&Stack);
			break;
		case 3:
			SeqStackShow(&Stack);
			break;
		case 4:
			printf("��Ҫ���ҵ�˳��ջ��ջ��Ԫ��ֵΪ��%d\n", SeqStackTop(&Stack));
			break;
		case 5:
			SeqStackClear(&Stack);
			break;
		case 6:
			//SeqStackDestroy(&Stack);
			break;
		}
	}
	SeqStackDestroy(&Stack);
	return 0;
}