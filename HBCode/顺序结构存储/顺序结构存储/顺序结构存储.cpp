#include<iostream>
using namespace std;

struct Array
{
	int * pBase; //存储的是数组第一个元素的地址
	int len; //数组所能容纳的最大元素的个数
	int cnt; //当前数组有效元素的个数
};

void InitArray(Array* arr,int length){
	arr->pBase = (int*)malloc(sizeof(int)* length);
	if (arr->pBase == NULL){
		cout << "分配内存失败！" << endl;
		exit(-1);
	}
	else{
		arr->len = length;
		arr->cnt = 0;
	}
}
bool Empty(Array * arr){
	if (arr->cnt == 0){
		return true;
	}
	else{
		return false;
	}
}
bool ShowArray(Array* arr){
	if (Empty(arr)){
		return false;
	}
	else{
		for (int i = 0; i < arr->cnt; i++){
			cout << arr->pBase[i] << " ";
		}
		cout << endl;
	}
	return true;
}
bool FullArray(Array* arr){
	if (arr->cnt == arr->len){
		return true;
	}
	else{
		return false;
	}
}
bool AppendArray(Array* arr, int val){
	if (FullArray(arr)){
		return false;
	}
	else{
		arr->pBase[arr->cnt] = val;
		arr->cnt++;
	}
	return true;
}

bool DeleteArray(Array* arr, int pos, int *pVal){
	//处理特殊情况
	if (Empty(arr)){
		return false;
	}
	if (pos<1 || pos>arr->cnt){
		return false;
	}

	*pVal = arr->pBase[pos-1];
	for (int i = pos; i < arr->cnt; i++){
		arr->pBase[i-1] = arr->pBase[i];
	}
	arr->cnt--;
	return true;
}
bool InsertArray(Array * arr,int pos,int val){
	if (FullArray(arr)){
		return false;
	}
	if (pos<1 || pos>arr->cnt + 1){
		return false;
	}
	for (int i = arr->cnt-1; i >=pos-1; i--){
		arr->pBase[i+1] = arr->pBase[i ];
	}
	arr->pBase[pos - 1] = val;
	arr->cnt++;
	return true;
}
int main(){
	struct Array arr;
	int val;
	InitArray(&arr,6);
	ShowArray(&arr);
	AppendArray(&arr, 11);
	AppendArray(&arr, 22);
	AppendArray(&arr, 33);
	AppendArray(&arr, 44);
	AppendArray(&arr, 55);
	AppendArray(&arr, 66);
	ShowArray(&arr);
	if (DeleteArray(&arr, 3, &val)){
		cout << "删除成功，删除的元素为：" << val << endl;
	}
	else{
		cout << "删除失败！" << endl;
	}

	ShowArray(&arr);
	InsertArray(&arr, 2, 100);
	ShowArray(&arr);

	return 0;
}