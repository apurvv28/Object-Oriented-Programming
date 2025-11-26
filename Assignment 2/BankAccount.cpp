//Create a class BankAccount with data members : account number, account holder name and balance.
//Initialize details using constructor.
//Write member functions to deposit and withdraw amount and display balance.
//Use destructor to display message “Account closed for <account holder name>”.

#include <iostream>
using namespace std;

class BankAccount{
    public:
        int acc_no;
        string acc_holder_name;
        float bal;
        BankAccount(int a, string n, float b){
            acc_no = a;
            acc_holder_name = n;
            bal = b;
        }
        void deposit(float a){
            bal += a;
            cout<<"Amount deposited successfully"<<endl;
            cout<<"Current Balance : "<<bal<<endl;
        }
        void withdraw(float a){
            if(a > bal){
                cout<<"Insufficient Balance"<<endl;
            }
            else{
                bal -= a;
                cout<<"Amount withdrawn successfully"<<endl;
                cout<<"Current Balance : "<<bal<<endl;
            }
        }
        void display(){
            cout<<"Account Details: "<<endl;
            cout<<"Account Number: "<<acc_no<<endl;
            cout<<"Account Holder Name: "<<acc_holder_name<<endl;
            cout<<"Balance: "<<bal<<endl;
        }
        ~BankAccount(){
            cout<<"Account closed for "<<acc_holder_name<<endl;
        }
};

int main(){
    int a;
    string n;
    float b;
    cout<<"Enter Account Number: "<<endl;
    cin>>a;
    cout<<"Enter Account Holder Name: "<<endl;
    cin>>n;
    cout<<"Enter Initial Balance: "<<endl;
    cin>>b;
    BankAccount ba1(a,n,b);
    ba1.display();
    int ch;
    float amt;
    do{
        cout<<"Choose an option \n 1. Deposit \n 2. Withdraw \n 3. Display Details \n 4. Exit "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"Enter amount to deposit: "<<endl;
            cin>>amt;
            ba1.deposit(amt);
            break;
            case 2:
            cout<<"Enter amount to withdraw: "<<endl;
            cin>>amt;
            ba1.withdraw(amt);
            break;
            case 3:
            ba1.display();
            break;
            case 4:
            cout<<"Exitting..."<<endl;
            break;
            default:
            cout<<"Invalid Choice"<<endl;
        }    
    }while(ch != 4);
    return 0;
}

