//快速排序

#include<iostream>
using namespace std;

int FindPos(int *a, int low, int high){
	int val = a[low];
	while (low < high){
		while (low < high && a[high] >= val){
			--high;
		}
			a[low] = a[high];
			while (low < high && a[low] <= val){
				++low;
			}
				a[high] = a[low];
		
	}
	a[low] = val;
	return low;//low可以改成high 不可以改成 a[low] 
}

void QuickSort(int *a, int low, int high){
	int pos;
	if (low < high){
		     pos = FindPos(a, low, high);//找到 a数组 从low 到high 数组a的位置
			QuickSort(a, low, pos - 1);
			QuickSort(a, pos + 1, high);
	}
}

int main(){
	int a[6] = { 2, 4, 6, 12, 5, 9 };
	QuickSort(a,0,5);//第二个参数表示数组元素第一个元素的下标，第三个参数表示最后一个元素的下标
	for (int i = 0; i < 6; i++){
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}