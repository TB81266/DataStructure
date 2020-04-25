//	就和递归
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
	cout << "请输入一个有效的数字：";
	cin >> val;
	cout << val << "的总和为：" << Sum(val) << endl;
	return 0;
}