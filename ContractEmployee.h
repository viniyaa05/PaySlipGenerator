
#ifndef CONTRACTEMPLOYEE_H
#define CONTRACTEMPLOYEE_H

#include "Employee.h"

class ContractEmployee : public Employee {
public:
    int duration;

    void get() override;
    int calculateSalary() override;
};

#endif
