#include<iostream>
#include<cmath>
using namespace std;

float squareroot(float n){
	if(n<0){
		cout<<"Negative number"<<endl;
	}
	float i = 1;
	while(i*i<=n){
		i++;
	}
	i--;
	cout<<"Square root of "<<n<<" is "<<i<<endl;
	
}
int main(){
	float n;
	cout<<"Enter a value"<<endl;
	cin>>n;
	squareroot(n);
	return 0;
}
