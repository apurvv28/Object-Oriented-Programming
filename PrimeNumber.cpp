#include<iostream>
using namespace std;

void prime(int n){
	if(n<=1){
		cout<<n<<" is not a Prime Number"<<endl;
	}
	int count = 0;
	for(int i = 1;i<=n;i++){
		if(n%i==0){
			count++;
		}
	}
	if(count == 2){
		cout<<n<<" is a prime number"<<endl;
	}
	else{
		cout<<n<<" is not a prime number"<<endl;
	}
}

int main(){
	int n;
	cout<<"Enter a number"<<endl;
	cin>>n;
	prime(n);
	return 0;
}
