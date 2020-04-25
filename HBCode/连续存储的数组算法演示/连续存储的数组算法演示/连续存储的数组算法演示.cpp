#include<iostream>
#include"stdlib.h"
using namespace std;

class Array{
public:
	int *pBase;
	int len;
	int cnt;
protected:
private:
};

void init_arr(Array* arr,int length){
	arr->pBase = (int*)malloc(sizeof(int) * length);
	if (arr->pBase == NULL){
		cout << "分派内存失败！" << endl;
		exit(-1);
	}
	else{
		arr->len = length;
		arr->cnt = 0;
	}
}

bool Is_empty(Array* arr){
	if (arr->cnt == 0){
		return true;
	}
	else{
		return false;
	}
}
void show_arr(Array * arr){
	if (Is_empty(arr)){
		cout << "数组为空！" << endl;
	}
	else{
		for (int i = 0; i < arr->cnt; i++){
			cout << arr->pBase[i] << "  ";
		}
		cout << endl;
	}
}

bool Is_full(Array* arr){
	if (arr->cnt == arr->len){
		return true;
	}
	else{
		return false;
	}
}
bool append_arr(Array * arr,int val){
	if (Is_full(arr)){
		return false;
	}
	else{
		arr->pBase[arr->cnt] = val;
		(arr->cnt)++;
		return true;
	}
}
int main(){
	Array arr;
	init_arr(&arr,6);
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	show_arr(&arr);
	return 0;
}