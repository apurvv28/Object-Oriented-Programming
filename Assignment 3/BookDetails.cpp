#include <iostream>
using namespace std;

class Book{
    int book_id;
    string book_name;
    string author;
    float price;
    public:
        void get_details(int i, string n, string a, float p){
            book_id=i;
            book_name=n;
            author=a;
            price=p;
        }
        void print_details(){
            cout<<book_id<<"\t"<<book_name<<"\t\t"<<author<<"\t"<<price<<endl;
        }
        void calculate(Book obj[], int n){
            float total = 0;
            for(int i = 0;i < n;i++){
                total += obj[i].price;
            }
            cout<<"Total price of all books = "<<total<<endl;
        }
};

int main(){
    int n, id;
    string name, author;
    float price;
    cout<<"Enter number of books you want to enter : "<<endl;
    cin>>n;
    Book b[n];
    for(int i = 0;i < n;i++){
        cout<<"Enter book id = "<<endl;
        cin>>id;
        cout<<"Enter book name = "<<endl;
        cin>>name;
        cout<<"Enter book author = "<<endl;
        cin>>author;
        cout<<"Enter book price = "<<endl;
        cin>>price;
        b[i].get_details(id,name,author,price);
    }
    cout<<"Book Details"<<endl;
    cout<<"Book ID"<<"\t"<<"Book Name"<<"\t"<<"Author"<<"\t"<<"Price"<<"\t"<<endl;
    for(int i = 0;i < n;i++){
        b[i].print_details();
    }
    b->calculate(b,n);
    return 0;
}