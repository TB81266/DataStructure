//����ѭ���͵ݹ���׳�
#include <iostream>
using namespace std;

//��ѭ��ʵ��
int main01(){
	int val;
	int i, mult = 1, s;
	cout << "������һ����Ч�����֣�";
	cin >> val;
	for (i = 1; i <= val; i++){
		mult = mult*i;
	}
	s = mult;
	cout <<val<< "�Ľ׳�Ϊ�� " << s << endl;
	return 0;
}

long f(long n){
	if (n == 1){
		return 1;
	}
	else{
		return f(n - 1)*n;
	}
}
int main(){
	int val;
	cout << "������һ����Ч�����֣�";
	cin >> val;
	cout << val << "�ĵݹ����Ľ׳�Ϊ��" << f(val) << endl;
}