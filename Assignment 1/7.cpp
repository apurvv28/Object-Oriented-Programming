#include<iostream>
using namespace std;

class A{
	public:
		char c[100];
		void get(){
			cout<<"Enter a string = "<<endl;
			cin.getline(c,100);
		}
		void check(){
			int count=0;
			for(int i = 0;i < c[i]!='\0';i++){
				char ch = c[i];
				if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
					count++;
				}
			}
			cout<<"No. of vowels in string = "<<count<<endl;
		}
};

int main(){
	A a;
	a.get();
	a.check();
	return 0;
}
