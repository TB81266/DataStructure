#include<iostream>
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 //�����ϣ��Ϊ����ĳ���
#define NULLKEY -32768

using namespace std;

typedef struct{
	int *elem;//����Ԫ�ش洢��ַ ��̬��������
	int count;//��ǰ����Ԫ�صĸ���
}HashTable;
int m = 0;//��ϣ���	ȫ�ֱ���

//��ʼ����ϣ��
void initHashTable(HashTable* H){
	m = HASHSIZE;
	H->count = 0;
	H->elem = (int*)malloc(m*sizeof(int));
	for (int i = 0; i < m; i++){
		H->elem[i] = NULLKEY;
	}
	return ;
}

//�����ϣ����
int Hash(int key){
	return key%m;
}

//����ؼ��ֽ���ϣ��
void insertHash(HashTable * H, int key){
	int addr = Hash(key); //�����б�ĵ�ַ
	while (H->elem[addr] != NULLKEY){
		addr = (addr + 1) % m;
	}
	H->elem[addr] = key;
}

//��ϣ��ؼ��ֲ���
void  SearchHash(HashTable H, int key, int *addr){
	*addr = Hash(key); //���ϣ��ĵ�ַ
	while (H.elem[*addr] != key){
		*addr = (*addr + 1) % m;
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key){
			return UNSUCCESS;
		}
	}

}


int main(){
	HashTable table1;
	initHashTable(&table1);

	return 0;
}