#include <iostream>
using namespace std;

int fact(int n){
	if(n==0 || n==1){
		return 1;
	}else{
		return n*fact(n-1);
	}
}

int main(){
	int n;
	cout<<"Enter a number : "<<endl;
	cin>>n;
	int res = fact(n);
	cout<<"Factorial : "<<res<<endl;
	return 0;
}
