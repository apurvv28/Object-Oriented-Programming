//1. Write a C++ program to create class Student with data members as roll no, name and marks. 
//(Use parameterized constructor)
//Display detials using member function.
//Use destructor to display message “Object destroyed”.
#include <iostream>
using namespace std;

class Student{
    public:
        int roll_no;
        string name;
        float marks;
        Student(int r, string n, float m){
            roll_no = r;
            name = n;
            marks = m;
        }
        void display(){
            cout<<"Student Information: "<<endl;
            cout<<"Roll No. "<<roll_no<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Marks: "<<marks<<endl;
        }
        ~Student(){
            cout<<"Object destroyed"<<endl;
        }
};

int main(){
    int r;
    string n;
    float m;
    cout<<"Enter Roll No.: "<<endl;
    cin>>r;
    cout<<"Enter Name: "<<endl;
    cin>>n;
    cout<<"Enter Marks: "<<endl;
    cin>>m;
    Student s1(r,n,m);
    s1.display();
    return 0;
}