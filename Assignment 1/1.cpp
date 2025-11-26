#include <iostream>
using namespace std;

class Calculator{
	public:
		float add(float a, float b){
			return a + b;
		}
		float sub(float a, float b){
			return a - b;
		}
		float mul(float a, float b){
			return a * b;
		}
		float div(float a, float b){
			return a / b;
		}
};

int main(){
	Calculator obj;
	float a,b,res;
	int ch;
	cout<<"Enter first value - "<<endl;
	cin>>a;
	cout<<"Enter second value - "<<endl;
	cin>>b;
	cout << "Choose an operation \n 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n";
	cin>>ch;
	switch(ch){
		case 1:
		res = obj.add(a,b);
		cout<<"Addition = "<<res<<endl;
		break;
		case 2:
		res = obj.sub(a,b);
		cout<<"Subtraction = "<<res<<endl;
		break;
		case 3:
		res = obj.mul(a,b);
		cout<<"Product = "<<res<<endl;
		break;
		case 4:
		res = obj.div(a,b);
		cout<<"Quotient = "<<res<<endl;
		break;
	}
}
