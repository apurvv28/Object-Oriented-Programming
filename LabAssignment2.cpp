#include <iostream>
using namespace std;

class Book {
private:
    int bookid;
    string book_name;
    string author;
    double price;

public:
    void get_details() {
        cout << "Enter Book ID: ";
        cin >> bookid;
        
        cout << "Enter Book Name: ";
        cin >> book_name;

        cout << "Enter Author Name: ";
        cin >> author;

        cout << "Enter Price: ";
        cin >> price;
    }

    void print_details() {
        cout << bookid << "\t" << book_name << "\t\t" << author << "\t\t" << price << endl;
    }

    double get_price() {
        return price;
    }
};

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book b[100];
    float total = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of book " << i + 1 << ":\n";
        b[i].get_details();
    }

    cout << "\n--------------------------------------------------------------\n";
    cout << "BookID\tBook Name\tAuthor\t\tPrice\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        b[i].print_details();
        total += b[i].get_price();
    }

    cout << "--------------------------------------------------------------\n";
    cout << "Total Price of all books: " << total << endl;

    return 0;
}

