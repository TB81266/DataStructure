#include"SeqQueue.h"

int main(){
	system("title ˳��ջ��ʵ��");
	system("color 0B");
	system("date/T");
	system("TIME/T");

	int val = 0;
	int pos = 0;
	int item = 0;

	SeqQueue SQueue;//����һ��˳��ջ

	SeqQueueInit(&SQueue);//��ʼ������
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
				SeqQueueEnQueue(&SQueue, val);
			}
			break;
		case 2:
			SeqQueueDeQueue(&SQueue);
			break;
		case 3:
			SeqQueueShow(&SQueue);
			break;
		case 4:
			printf("��Ҫ���ҵ�˳��ջ��ջ��Ԫ��ֵΪ��%d\n", SeqQueueTop(&SQueue));
			break;
		case 5:
			SeqQueueClear(&SQueue);
			break;
		case 6:
			//SeqStackDestroy(&Stack);
			break;
		}
	}
	SeqQueueDestroy(&SQueue);
	return 0;
}