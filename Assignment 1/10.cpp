#include<iostream>
using namespace std;

class Pattern{
	public:
		int n;
		void get(){
			cout<<"Enter number of * = ";
			cin>>n;
		}
		void display_tri(){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n-i;j++){
					cout<<" ";
				}
				for(int k = 1;k<=i;k++){
					cout<<"* ";
				}
				cout<<endl;
			}
		}
		void display_diam(){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n-i;j++){
					cout<<" ";
				}
				for(int k = 1;k<=i;k++){
					cout<<"* ";
				}
				cout<<endl;
			}
			for(int i = n-1; i>=1; i--){
				for(int j = 1;j<=n-i;j++){
					cout<<" ";
				}
				for(int k = 1;k<=i;k++){
					cout<<"* ";
				}
				cout<<endl;
			}
		}
};

int main(){
	Pattern p;
	p.get();
	p.display_tri();
	cout<<"-----------------------------------------------"<<endl;
	p.display_diam();
	cout<<"-----------------------------------------------"<<endl;
	return 0;
}
