#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int emp_id;
    string emp_name, emp_addr, emp_mail;
    long long emp_phone;

    void getDetails() {
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, emp_name);
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cin.ignore();
        cout << "Enter Address: ";
        getline(cin, emp_addr);
        cout << "Enter Mail ID: ";
        getline(cin, emp_mail);
        cout << "Enter Mobile Number: ";
        cin >> emp_phone;
    }

    void displayDetails() {
        cout << "\nEmployee Details:\n";
        cout << "Name: " << emp_name << endl;
        cout << "ID: " << emp_id << endl;
        cout << "Address: " << emp_addr << endl;
        cout << "Mail ID: " << emp_mail << endl;
        cout << "Mobile Number: " << emp_phone << endl;
    }
};

class Salary : public Employee {
public:
    float BasicPay, DA, HRA, PF, StaffClubFund, GrossSalary, NetSalary;

    virtual void getSalary() {
        cout << "Enter Basic Pay Salary: ";
        cin >> BasicPay;
    }

    virtual void calculate() {
        DA = 0.52 * BasicPay;
        HRA = 0.27 * BasicPay;
        PF = 0.12 * BasicPay;
        StaffClubFund = 0.001 * BasicPay;
        GrossSalary = BasicPay + DA + HRA;
        NetSalary = GrossSalary - (PF + StaffClubFund);
    }

    virtual void generatePaySlip() {
        displayDetails();
        cout << "Basic Pay: " << BasicPay << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "PF: " << PF << endl;
        cout << "Staff Club Fund: " << StaffClubFund << endl;
        cout << "Gross Salary: " << GrossSalary << endl;
        cout << "Net Salary: " << NetSalary << endl;
    }
};

class Programmer : public Salary {
public:
    void calculate() override {
        DA = 0.40 * BasicPay;
        HRA = 0.20 * BasicPay;
        PF = 0.10 * BasicPay;
        StaffClubFund = 0.001 * BasicPay;
        GrossSalary = BasicPay + DA + HRA;
        NetSalary = GrossSalary - (PF + StaffClubFund);
    }
    void generatePaySlip() override {
        cout << "\nPay Slip: Programmer\n";
        Salary::generatePaySlip();
    }
};

class TeamLead : public Salary {
public:
    void calculate() override {
        DA = 0.45 * BasicPay;
        HRA = 0.22 * BasicPay;
        PF = 0.11 * BasicPay;
        StaffClubFund = 0.001 * BasicPay;
        GrossSalary = BasicPay + DA + HRA;
        NetSalary = GrossSalary - (PF + StaffClubFund);
    }
    void generatePaySlip() override {
        cout << "\nPay Slip: Team Lead\n";
        Salary::generatePaySlip();
    }
};

class AsstProjectManager : public Salary {
public:
    void generatePaySlip() override {
        cout << "\nPay Slip: Assistant Project Manager\n";
        Salary::generatePaySlip();
    }
};

class ProjectManager : public Salary {
public:
    void calculate() override {
        DA = 0.55 * BasicPay;
        HRA = 0.30 * BasicPay;
        PF = 0.12 * BasicPay;
        StaffClubFund = 0.001 * BasicPay;
        GrossSalary = BasicPay + DA + HRA;
        NetSalary = GrossSalary - (PF + StaffClubFund);
    }
    void generatePaySlip() override {
        cout << "\nPay Slip: Project Manager\n";
        Salary::generatePaySlip();
    }
};

int main() {
    int choice;
    cout << "Select Employee Type: \n1. Programmer\n2. Team Lead\n3. Assistant Project Manager\n4. Project Manager\n";
    cin >> choice;

    Salary* emp = nullptr;

    switch (choice) {
        case 1: emp = new Programmer(); break;
        case 2: emp = new TeamLead(); break;
        case 3: emp = new AsstProjectManager(); break;
        case 4: emp = new ProjectManager(); break;
        default: cout << "Invalid choice!" << endl; return 0;
    }

    emp->getDetails();
    
    emp->getSalary();
    emp->calculate();
    emp->generatePaySlip();

    delete emp;
    return 0;
}
