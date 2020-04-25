#include<iostream>
using namespace std;

//选择法 排序
void selectSort(int* s, int len){
	
	for (int i = 0; i <len; i++){
		for (int j = i + 1; j < len; j++){
			if (s[i] < s[j]){
				int t = 0;
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
		}
		cout << s[i] << " ";
	}
}

//插入法实现排序
void insertSort(int *s, int len){
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	for (i = 1; i < len; i++){
		k = i;
		temp = s[k];
		for (j = i - 1; (j >= 0) && (s[j] > temp); j--){
			s[j + 1] = s[j];	
			k = j;
		}
		s[k] = temp;
	}
}

//冒泡排序 (从后往前 冒泡 从小到大的排序)
void bubbleSort01(int* s, int len){
	int i = 0;
	int j = 0;
	for ( i = 0; i < len;i++){
		for (int j = len - 1; j > 0; j--){
			if (s[j] > s[j - 1]){
				int temp = 0;
				temp = s[j];
				s[j] = s[j - 1];
				s[j - 1] = temp;
			}
		}
		cout << s[i] << " ";
	}
}

//冒泡排序 (从前往后 从小到大)
void bubbleSort02(int* s, int len){
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++){
		for (j = 0; j < len-1-i; j++){
			if (s[j] > s[j+1]){
				int t = 0;
				t = s[j];
				s[j] = s[j+1];
				s[j+1] = t;
			}
		}
		cout << s[i] << " ";
	}
}

//希尔排序
void shellSort(int *a, int len){

}

//快速排序
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
	for (int i = 0; i < 6; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	int a[] = { 19, 30, 90, 67, 54, 32, 46, 78 };
	int length = sizeof(a) / sizeof(int);
	//selectSort(a, length);
	//insertSort(a, length);
	//bubbleSort01(a, length);
	//bubbleSort02(a, length);
	//shellSort(a, length);
	QuickSort(a, 0, 7);//第二个参数表示数组元素第一个元素的下标，第三个参数表示最后一个元素的下标
	

	return 0;
}


