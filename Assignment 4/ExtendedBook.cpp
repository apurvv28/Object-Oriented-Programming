#include<iostream>
using namespace std;
class Book{
    int book_id;
    string name;
    float price;
    public:
    Book(int id, string n, float p){
        book_id = id;
        name = n;
        price = p;
    }
    ~Book(){
        cout<<"Destroyed Memory"<<endl;
    }
    void display(){
        cout<<"Book Details "<<endl;
        cout<<"Book ID = "<<book_id<<endl;
        cout<<"Book Name = "<<name<<endl;
        cout<<"Book Price = "<<price<<endl;
    }
};

int main(){
    Book *ptr = nullptr;
    ptr = new Book(101, "OOP", 299);
    cout<<"Pointer is accessing members of class = "<<endl;
    ptr->display();
    delete ptr;
    ptr = nullptr;
    if(ptr == nullptr){
        cout<<"Pointer is deleted successfully"<<endl;
    }
    return 0;
}