#include"CycleQueue.h"

int main(){
	system("title ˳��ջ��ʵ��");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	CycleQueue CQueue;//����һ��˳��ջ

	CycleQueueInit(&CQueue);//��ʼ������
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
			printf("������Ҫ��Ե�ֵ[��-1����]:>");
			while (scanf("%d", &val), val != -1){
				CycleQueueEnQueue(&CQueue, val);
			}
			break;
		case 2:
			CycleQueueDeQueue(&CQueue);
			break;
		case 3:
			CycleQueueShow(&CQueue);
			break;
		case 4:
			printf("��Ҫ���ҵ�˳��ջ��ջ��Ԫ��ֵΪ��%d\n", CycleQueueTop(&CQueue));
			break;
		case 5:
			CycleQueueClear(&CQueue);
			break;
		case 6:
			//CycleQueueDestroy(&CQueue);
			break;
		}
	}
	CycleQueueDestroy(&CQueue);
	return 0;
}