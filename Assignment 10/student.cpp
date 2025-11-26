#include<iostream>
#include<fstream>
using namespace std;

class Student {
    public:
        string name;
        int roll;
        int marks;
        string division;
        void displayInfo() {
            cout<<name<<" "<<roll<<" "<<marks<<" "<<division<<endl;
        }
        void getInfo() {
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter Marks: ";
            cin >> marks;
            cout << "Enter Division: ";
            cin >> division;
        }
        void insertNewRecord(){
            fstream fout("students.txt", ios::app);
            fout << name << " " << roll << " " << marks << " " << division << endl;
            fout.close();
        }
        void displayAllRecords(){
            fstream fin("students.txt", ios::in);
            string n, d;
            int r, m;
            cout << "\n--- Student Records ---" << endl;
            while(fin >> n >> r >> m >> d){
                cout << n << " " << r << " " << m << " " << d << endl;
            }
            fin.close();
        }
        void searchRecord(int sroll){
            cout << "\nSearching for Roll Number: " << sroll << endl;
            fstream fin("students.txt", ios::in);
            string n, d;
            int r, m;
            while(fin >> n >> r >> m >> d){
                if(r==sroll){
                    cout << "Record Found: " << n << " " << r << " " << m << " " << d << endl;
                    fin.close();
                    return;
                }else{
                    cout << "Record Not Found" << endl;
                }
            }
        }
        void deleteRecord(int sroll){
            fstream fin("students.txt", ios::in);
            fstream fout("temp.txt", ios::out);
            string n, d;
            int r, m;
            while(fin >> n >> r >> m >> d){
                if(r!=sroll){
                    fout << n << " " << r << " " << m << " " << d << endl;
                }
            }
            
            fin.close();
            fout.close();
            remove("students.txt");
            rename("temp.txt", "students.txt");
            cout << "Record with Roll Number " << sroll << " deleted." << endl;
        }
        void updateRecord(int sroll){
            fstream fin("students.txt", ios::in);
            fstream fout("temp.txt", ios::out);
            string n, d;
            int r, m;
            while(fin >> n >> r >> m >> d){
                if(r==sroll){
                    cout << "Enter New Details for Roll Number " << sroll << ":\n";
                    getInfo();
                    fout << name << " " << roll << " " << marks << " " << division << endl;
                }else{
                    fout << n << " " << r << " " << m << " " << d << endl;
                }
            }
            fin.close();
            fout.close();
            remove("students.txt");
            rename("temp.txt", "students.txt");
            cout << "Record with Roll Number " << sroll << " updated." << endl;
        }
};

int main() {
    Student student;
    int ch, rollNo;
    while(true){
        cout << "\n1. Insert New Record\n2. Display All Records\n3. Search Record\n4. Delete Record\n5. Update Record\n6. Exit\nEnter your choice: ";
        cin >> ch;
        if(ch==6) break;
        switch(ch){
            case 1:
                student.getInfo();
                student.insertNewRecord();
                break;
            case 2:
                student.displayAllRecords();
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                cin >> rollNo;
                student.searchRecord(rollNo);
                break;
            case 4:
                cout << "Enter Roll Number to Delete: ";
                cin >> rollNo;
                student.deleteRecord(rollNo);
                break;
            case 5:
                cout << "Enter Roll Number to Update: ";
                cin >> rollNo;
                student.updateRecord(rollNo);
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}