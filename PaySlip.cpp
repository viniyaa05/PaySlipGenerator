
#include "PaySlip.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
using namespace std;

void Employee::get() {
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Designation: ";
    cin >> designation;
    cout << "Enter Base Salary: ";
    cin >> baseSalary;
    if (baseSalary < 0)
        throw invalid_argument("Base salary cannot be negative.");
}

void Employee::displayDetails() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Designation: " << designation << endl;
    cout << "Base Salary: " << baseSalary << endl;
}

int Employee::calculateSalary() {
    return baseSalary;
}

void RegularEmployee::get() {
    Employee::get();
    cout << "Enter Extra Hours Worked: ";
    cin >> hours;
    cout << "Enter Rate per Hour: ";
    cin >> rate;
    if (hours < 0 || rate < 0)
        throw invalid_argument("Hours or rate cannot be negative.");
}

int RegularEmployee::calculateSalary() {
    return baseSalary + (hours * rate);
}

void ContractEmployee::get() {
    Employee::get();
    cout << "Enter Contract Duration (in months): ";
    cin >> duration;
    if (duration <= 0)
        throw invalid_argument("Contract duration must be positive.");
}

int ContractEmployee::calculateSalary() {
    return baseSalary;
}

void PaySlip::generate() {
    cout << "\nEnter PaySlip ID: ";
    cin >> paySlipID;

    cout << "Enter Deductions: ";
    cin >> deductions;
    if (deductions < 0) throw invalid_argument("Deductions cannot be negative.");

    cout << "Enter Bonuses: ";
    cin >> bonuses;
    if (bonuses < 0) throw invalid_argument("Bonuses cannot be negative.");

    cout << "Enter Employee Type (REGULAR / CONTRACT): ";
    cin >> type;

    if (type == "REGULAR") {
        regEmp.get();
        finalSalary = regEmp.calculateSalary() + bonuses - deductions;
    } else if (type == "CONTRACT") {
        contEmp.get();
        finalSalary = contEmp.calculateSalary() + bonuses - deductions;
    } else {
        throw runtime_error("Invalid employee type entered.");
    }
}

void PaySlip::display() {
    cout << "\n----- PAYSLIP -----\n";
    cout << "Payslip ID: " << paySlipID << endl;
    if (type == "REGULAR")
        regEmp.displayDetails();
    else
        contEmp.displayDetails();

    cout << "Deductions: " << deductions << endl;
    cout << "Bonuses: " << bonuses << endl;
    cout << "Final Salary: " << finalSalary << endl;
    cout << "-------------------\n";
}

void PaySlip::saveToFile() {
    ofstream fout("payslip_data.txt", ios::app);
    if (!fout)
        throw runtime_error("Failed to open file for writing.");

    fout << "Payslip ID: " << paySlipID << endl;
    fout << "Employee Type: " << type << endl;
    if (type == "REGULAR") {
        fout << "ID: " << regEmp.id << endl;
        fout << "Name: " << regEmp.name << endl;
        fout << "Designation: " << regEmp.designation << endl;
    } else {
        fout << "ID: " << contEmp.id << endl;
        fout << "Name: " << contEmp.name << endl;
        fout << "Designation: " << contEmp.designation << endl;
    }
    fout << "Final Salary: " << finalSalary << endl;
    fout << "Deductions: " << deductions << endl;
    fout << "Bonuses: " << bonuses << endl;
    fout << "---------------------------\n";
    fout.close();
}

void PaySlip::readFromFile() {
    ifstream fin("payslip_data.txt");
    if (!fin)
        throw runtime_error("Failed to open file for reading.");

    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}
