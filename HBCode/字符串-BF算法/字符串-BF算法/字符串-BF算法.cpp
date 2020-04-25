#include<iostream>
#include<string>
using namespace std;

int BF(string s,string t){
	int i = 0, j = 0;
	while (i < s.size() && j < t.size()){
		if (s[i] == s[j]){
			j++;
			i++;
		}
		else{
			i = i-j + 1; 
			j = 0;
		}
	}
	if (j > t.size()){
		return (i-t.size());
	}
	else{
		return (-1);
	}
}


int main(){
	string s("shangxiaofeng");
	string t("xiao");
	int m = BF(s, t);
	cout << m << endl;
	return 0;
}
