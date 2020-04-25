#include<iostream>
using namespace std;

void f();
void g();
void k();

void f(){
	cout << "FFFF" << endl;
	g();
	cout << "1111111" << endl;
}

void g(){
	cout << "GGGG" << endl;
	k();
	cout << "2222222" << endl;
}

void k(){
	cout << "KKKK" << endl;
	cout << "333333" << endl;
}

int main(){
	f();

	return 0;
}