#include"LinkStack.h"

int main(){
	system("title ˳��ջ��ʵ��");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	LinkStack LStack;//����һ��˳��ջ

	LinkStackInit(&LStack);//��ʼ������
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
				LinkStackPush(&LStack, val);
			}
			break;
		case 2:
			LinkStackPop(&LStack);
			break;
		case 3:
			LinkStackShow(&LStack);
			break;
		case 4:
			printf("��Ҫ���ҵ�˳��ջ��ջ��Ԫ��ֵΪ��%d\n", LinkStackTop(&LStack));
			break;
		}
	}
	LinkStackDestory(&LStack);
	return 0;
}