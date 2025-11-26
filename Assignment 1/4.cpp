#include <iostream>
using namespace std;

class Area{
	public:
		float calculate_rect(float l, float b){
			return l * b;
		}
		float calculate_cir(float r){
			return 3.142 * r * r;
		}
		float calculate_tri(float b, float h){
			return 0.5 * b * h;
		}
		void display_rect(float res){
			cout<<"Area of rectangle = "<<res<<endl;
		}
		void display_cir(float res){
			cout<<"Area of Circle = "<<res<<endl;
		}
		void display_tri(float res){
			cout<<"Area of Triangle = "<<res<<endl;
		}
};

int main(){
	Area a;
	float length, breadth, radius, base, height;
	float res;
	int ch;
	cout<<"Choose an option: \n 1. Rectangle\n 2. Circle\n 3. Triangle\n";
	cin>>ch;
	switch(ch){
		case 1:
		cout<<"Enter length of rectangle = "<<endl;
		cin>>length;
		cout<<"Enter breadth of rectangle = "<<endl;
		cin>>breadth;
		res = a.calculate_rect(length, breadth);
		a.display_rect(res);
		break;
		
		case 2:
		cout<<"Enter radius of circle = "<<endl;
		cin>>radius;
		res = a.calculate_cir(radius);
		a.display_cir(res);
		break;
		
		case 3:
		cout<<"Enter height of triangle = "<<endl;
		cin>>height;
		cout<<"Enter base of triangle = "<<endl;
		cin>>base;
		res = a.calculate_tri(base, height);
		a.display_tri(res);
		break;
	}
	return 0;
}
