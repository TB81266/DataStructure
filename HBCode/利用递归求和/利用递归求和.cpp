//	�ͺ͵ݹ�
#include<iostream>
using namespace std;

int  Sum(int n){
	if (n == 1){
		return 1;
	}
	else{
		return Sum(n - 1) + n;
	}
}
int main(){
	int val;
	cout << "������һ����Ч�����֣�";
	cin >> val;
	cout << val << "���ܺ�Ϊ��" << Sum(val) << endl;
	return 0;
}