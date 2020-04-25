#include<iostream>
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 //定义哈希长为数组的长度
#define NULLKEY -32768

using namespace std;

typedef struct{
	int *elem;//数据元素存储基址 动态分配数组
	int count;//当前数据元素的个数
}HashTable;
int m = 0;//哈希表表长	全局变量

//初始化哈希表
void initHashTable(HashTable* H){
	m = HASHSIZE;
	H->count = 0;
	H->elem = (int*)malloc(m*sizeof(int));
	for (int i = 0; i < m; i++){
		H->elem[i] = NULLKEY;
	}
	return ;
}

//定义哈希表函数
int Hash(int key){
	return key%m;
}

//插入关键字进哈希表
void insertHash(HashTable * H, int key){
	int addr = Hash(key); //求算列表的地址
	while (H->elem[addr] != NULLKEY){
		addr = (addr + 1) % m;
	}
	H->elem[addr] = key;
}

//哈希表关键字查找
void  SearchHash(HashTable H, int key, int *addr){
	*addr = Hash(key); //求哈希表的地址
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