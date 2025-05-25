
#ifndef PAYSLIP_H
#define PAYSLIP_H

#include "RegularEmployee.h"
#include "ContractEmployee.h"

class PaySlip {
public:
    int paySlipID;
    float deductions;
    int bonuses;
    int finalSalary;
    string type;

    RegularEmployee regEmp;
    ContractEmployee contEmp;

    void generate();
    void display();
    void saveToFile();
    void readFromFile();
};

#endif
