#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
using namespace std;

void divByZero(int a, int b){
    if (b == 0){
        throw runtime_error("Division by zero");
    }
    int res = a / b;
    cout << "The quotient is " << res << endl;
}

void accessArrayAt(int idx){
    vector<int> arr = {10, 20, 30};
    cout << "Element at index " << idx << " is " << arr.at(idx) << endl;
}

int main(){
    try {
        divByZero(10, 0);
    }
    catch (const runtime_error &e) {
        cout << "Division error: " << e.what() << endl;
    }

    try {
        accessArrayAt(5); 
    }
    catch (const out_of_range &e) {
        cout << "Array access error: " << e.what() << endl;
    }
    return 0;
}