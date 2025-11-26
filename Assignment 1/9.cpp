#include<iostream>
#include<algorithm>
using namespace std;

void palindrome(string n){
	string temp = n;
	reverse(temp.begin(),temp.end());
	if(temp == n){
		cout<<"It is a palindrome"<<endl;
	}
	else{
		cout<<"It is not a palindrome"<<endl;
	}
}

int main(){
	string s;
	cout<<"Insert a string"<<endl;
	cin>>s;
	palindrome(s);
	return 0;
}
