#include <iostream>
using namespace std;

class StrLen{
	public:
		char str[100];
		
		void input(){
			cout<<"Enter a string = "<<endl;
			cin.getline(str,100);
		}
		
		int len(){
			int c = 0;
			while(str[c]!='\0'){
				c++;
			}
			cout<<"Length of string = "<<c<<endl;
			return c;
		}
};

int main(){
	StrLen a;
	a.input();
	a.len();
	return 0;
}
