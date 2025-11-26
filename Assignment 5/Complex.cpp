#include<iostream>
using namespace std;

class Complex{
    private: 
        float real;
        float imag;
    public:
        Complex(){
            real = 0.0f;
            imag = 0.0f;
        }
        Complex(float r, float i){
            real = r;
            imag = i;
        }
        Complex add(const Complex& other) {
            Complex temp(0,0);
            temp.real = this->real + other.real;
            temp.imag = this->imag + other.imag;
            return temp;
        }
        Complex subtract(const Complex& other){
            Complex temp(0,0);
            temp.real = this->real - other.real;
            temp.imag = this->imag - other.imag;
            return temp;
        }
        Complex multiply(const Complex& other){
            Complex temp(0,0);
            temp.real = (this->real * other.real) - (this->imag * other.imag);
            temp.imag = (this->imag * other.imag) + (this->real * other.real);
            return temp;
        }
        Complex divide(const Complex& other){
            Complex temp(0,0);
            float denominator = (other.real * other.real) + (other.imag * other.imag);
            temp.real = ((this->real * other.real) + (this->imag * other.imag)) / denominator;
            temp.imag = ((this->imag * other.real) - (this->real * other.imag)) / denominator;
            return temp;
        }
        void display(){
            if(imag < 0){
                cout<<real<<"-"<<-imag<<"i"<<endl;
            }
            else{
                cout<<real<<"+"<<imag<<"i"<<endl;
            }
        }
};

int main(){
    Complex c1(3.0, 4.0);
    Complex c2(2.0, 5.0);
    cout << "Complex Number 1: ";
    c1.display();
    cout << "Complex Number 2: ";
    c2.display();
    
    cout << "\n--- Arithmetic Operations ---" << std::endl;
    Complex sum = c1.add(c2);
    cout << "Addition Result: ";
    sum.display();

    Complex diff = c1.subtract(c2);
    cout << "Subtraction Result: ";
    diff.display();
    
    Complex prod = c1.multiply(c2);
    cout << "Multiplication Result: ";
    prod.display();

    Complex quot = c1.divide(c2);
    cout << "Division Result: ";
    quot.display();
    return 0;
}