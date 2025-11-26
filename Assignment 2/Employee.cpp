//Develop a class Employee with data members : employee ID, name and salary.
//Use a default and parameterized constructor for initialization.
//Use a destructor to display message "Employee record removed" when object is destroyed.

#include<iostream>
using namespace std;
class Employee{
    public:
        int emp_id;
        string name;
        float salary;
        Employee(){
            default_data();
        }
        void default_data(){
            emp_id = 100;
            name = "John Cena";
            salary = 20000.0;
            display();
            calculate();
        }
        Employee(int id, string n, float s){
            emp_id = id;
            name = n;
            salary = s;
            display();
            calculate();
        }
        void display(){
            cout<<"Employee Details: "<<endl;
            cout<<"Employee ID: "<<emp_id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Salary: "<<salary<<endl;
        }
        void calculate(){
            float annual = salary * 12;
            cout<<"Annual Salary: "<<annual<<endl;
        }
        ~Employee(){
            cout<<"Employee record removed"<<endl;
        }
};

int main(){
    int id, ch;
    string n;
    float sal;
    do{
        cout<<"Choose an option \n 1. Default Employee Constructor \n 2. Parameterized Employee Constructor \n 3. Exit"<<endl;
        cin>>ch;
        if(ch == 1){
            Employee e1;
        }else if(ch == 2){
            cout<<"Enter employe id: "<<endl;
            cin>>id;
            cout<<"Enter employee name: "<<endl;
            cin>>n;
            cout<<"Enter employee monthly salary: "<<endl;
            cin>>sal;
            Employee e2(id,n,sal);
        }else if(ch == 3){
            cout<<"Exiting..."<<endl;
        }else{
            cout<<"Invalid choice"<<endl;
        }
    }while(ch != 3);
    return 0;
}