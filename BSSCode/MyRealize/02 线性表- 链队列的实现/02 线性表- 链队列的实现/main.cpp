#include"LinkQueue.h"

int main(){
	system("title ˳��ջ��ʵ��");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	LinkQueue LQueue;//����һ��˳��ջ

	LinkQueueInit(&LQueue);//��ʼ������
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
				LinkQueueEnQueue(&LQueue, val);
			}
			break;
		case 2:
			LinkQueueDeQueue(&LQueue);
			break;
		case 3:
			LinkQueueShow(&LQueue);
			break;
		case 4:
			printf("��Ҫ���ҵ�˳��ջ��ջ��Ԫ��ֵΪ��%d\n", LinkQueueTop(&LQueue));
			break;
		}
	}
	LinkQueueDestory(&LQueue);
	return 0;
}