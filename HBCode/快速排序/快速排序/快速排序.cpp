//��������

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
	return low;//low���Ըĳ�high �����Ըĳ� a[low] 
}

void QuickSort(int *a, int low, int high){
	int pos;
	if (low < high){
		     pos = FindPos(a, low, high);//�ҵ� a���� ��low ��high ����a��λ��
			QuickSort(a, low, pos - 1);
			QuickSort(a, pos + 1, high);
	}
}

int main(){
	int a[6] = { 2, 4, 6, 12, 5, 9 };
	QuickSort(a,0,5);//�ڶ���������ʾ����Ԫ�ص�һ��Ԫ�ص��±꣬������������ʾ���һ��Ԫ�ص��±�
	for (int i = 0; i < 6; i++){
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}