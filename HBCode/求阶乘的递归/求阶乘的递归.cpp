//利用循环和递归求阶乘
#include <iostream>
using namespace std;

//用循环实现
int main01(){
	int val;
	int i, mult = 1, s;
	cout << "请输入一个有效的数字：";
	cin >> val;
	for (i = 1; i <= val; i++){
		mult = mult*i;
	}
	s = mult;
	cout <<val<< "的阶乘为： " << s << endl;
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
	cout << "请输入一个有效的数字：";
	cin >> val;
	cout << val << "的递归求解的阶乘为：" << f(val) << endl;
}