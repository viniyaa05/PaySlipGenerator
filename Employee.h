
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <stdexcept>
using namespace std;

class Employee {
public:
    int id;
    string name;
    string designation;
    int baseSalary;

    virtual void get();
    virtual void displayDetails();
    virtual int calculateSalary();
};

#endif
