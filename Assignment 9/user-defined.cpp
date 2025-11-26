#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;

class DivisionByZeroException : public exception
{
    string msg;

public:
    DivisionByZeroException(const string &m = "Division by zero") : msg(m) {}
    const char *what() const noexcept override { 
        return msg.c_str(); 
    }
};

class ArrayOutOfBoundsException : public exception
{
    string msg;

public:
    ArrayOutOfBoundsException(const string &m = "Array index out of bounds") : msg(m) {}
    const char *what() const noexcept override {
         return msg.c_str(); 
        }
};

int divide(int a, int b)
{
    if (b == 0)
        throw DivisionByZeroException();
    return a / b;
}

int accessAt(const vector<int> &arr, int idx)
{
    if (idx < 0 || idx >= static_cast<int>(arr.size()))
        throw ArrayOutOfBoundsException();
    return arr[idx];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int choice = 0;
    while (true)
    {
        cout << "\nChoose an option:\n1. Division\n2. Array access\n3. Exit\nChoice: ";
        if (!(cin >> choice))
        {
            cout << "Invalid input. Exiting.\n";
            return 1;
        }
        if (choice == 1)
        {
            int a, b;
            cout << "Enter numerator and denominator: ";
            cin >> a >> b;
            try
            {
                int res = divide(a, b);
                cout << "Result: " << res << endl;
            }
            catch (const DivisionByZeroException &e)
            {
                cout << "Division Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            int idx;
            cout << "Enter index to access (0 to " << arr.size() - 1 << "): ";
            cin >> idx;
            try
            {
                int val = accessAt(arr, idx);
                cout << "Element at index " << idx << " is " << val << endl;
            }
            catch (const ArrayOutOfBoundsException &e)
            {
                cout << "Array Error: " << e.what() << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}