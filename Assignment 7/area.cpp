//Design a base class shape with 2 double type values and member functions to input the data and compute_area() for calculating area of shape. Derive 2 classes: triangle and rectangle. Make compute_area() as an abstract function and redefine this function in the derived class to suit their requirements. Write a program that accepts dimensions of triangle/rectangle and displays calculated area. Implement dynamic binding for given problem statement.
#include <iostream>
using namespace std;

class Shape {
    public:
        double length, breadth;
        void input() {
            cout << "Enter length/height: ";
            cin >> length;
            cout << "Enter breadth: ";
            cin >> breadth;
        }
        virtual double compute_area() = 0;
};

class Triangle : public Shape{
    public:
        double compute_area() override {
            return 0.5 * length * breadth;
        }
};

class Rectangle : public Shape{
    public:
        double compute_area() override {
            return length * breadth;
        }
};

int main(){
    Shape *s;
    int ch;
    cout<<"1. Triangle\n2. Rectangle\nEnter your choice: ";
    cin>>ch;
    if(ch==1){
        s = new Triangle();
        s->input();
        cout<<"Area of Triangle: "<<s->compute_area()<<endl;
        delete s;
    }
    else if(ch==2){
        s = new Rectangle();
        s->input();
        cout<<"Area of Rectangle: "<<s->compute_area()<<endl;
        delete s;
    }
    else{
        cout<<"Invalid choice!"<<endl;
    }
    return 0;
}
