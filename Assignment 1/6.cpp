#include<iostream>
using namespace std;

class A{
	public:
		char c;
		void get(){
			cout<<"Enter a character = "<<endl;
			cin>>c;
		}
		void check(){
			if(c>='A' && c<='Z' || c>= 'a' && c<= 'z'){
				cout<<"It is an alphabet"<<endl;
			}
			else{
				cout<<"It is not an alphabet"<<endl;
			}
		}
};

int main(){
	A obj;
	obj.get();
	obj.check();
	return 0;
}
