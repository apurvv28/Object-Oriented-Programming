#include<iostream>
using namespace std;

class Sum{
	public:
		int n;
		
		void get(){
			cout<<"Enter a number = "<<endl;
			cin>>n;
		}
		int sum(){
			int res = 0;
			for(int i = 0; i<n ;i++){
				res += i;
			}
			cout<<"Sum of "<<n<<" numbers = "<<res<<endl;
			return res;
		}
};

int main(){
	Sum s;
	s.get();
	s.sum();
	return 0;
}
