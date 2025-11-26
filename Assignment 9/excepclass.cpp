#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <string>
using namespace std;

class DivisionByZero : public runtime_error {
public:
    DivisionByZero(const string& msg = "Division by 0 is not allowed")
        : runtime_error(msg) {}
};

class ArrayOutOfBounds : public out_of_range {
public:
    ArrayOutOfBounds(const string& msg = "Accessed element of array which is out of bounds")
        : out_of_range(msg) {}
};

int divide(int a, int b){
    if (b == 0) {
        throw DivisionByZero();
    }
    return a / b;
}

void arrOutOfBound(vector<int> arr){
    try {
        arr.at(10);
    }
    catch (const out_of_range &e) {
        throw ArrayOutOfBounds(e.what());
    }
}

int main(){
    int ch;
    vector<int> arr = {1,2,3,4,5};
    int a,b,res;
    while(true){
        cout<<"Choose an option!"<<endl;
        cout<<"1.Division\n2.Array\n3.Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter numerator and denominator: "<<endl;
            cin>>a>>b;
            try {
                res = divide(a,b);
                cout<<"Result: "<<res<<endl;
            }
            catch (const DivisionByZero &d) {
                cout<<"Division Error: "<<d.what()<<endl;
            }
            break;
        case 2:
            try {
                arrOutOfBound(arr);
                cout<<"Array access succeeded."<<endl;
            }
            catch (const ArrayOutOfBounds &r) {
                cout<<"Array Error: "<<r.what()<<endl;
            }
            break;
        case 3:
            cout<<"Exitting...."<<endl;
            return 0;
        default:
            cout<<"Invalid Choice!"<<endl;
            break;
        }
    }
    return 0;
}