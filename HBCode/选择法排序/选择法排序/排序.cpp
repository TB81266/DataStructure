#include<iostream>
using namespace std;

//ѡ�� ����
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

//���뷨ʵ������
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

//ð������ (�Ӻ���ǰ ð�� ��С���������)
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

//ð������ (��ǰ���� ��С����)
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

//ϣ������
void shellSort(int *a, int len){

}

//��������
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
	QuickSort(a, 0, 7);//�ڶ���������ʾ����Ԫ�ص�һ��Ԫ�ص��±꣬������������ʾ���һ��Ԫ�ص��±�
	

	return 0;
}


