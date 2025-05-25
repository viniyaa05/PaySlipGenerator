
#ifndef REGULAREMPLOYEE_H
#define REGULAREMPLOYEE_H

#include "Employee.h"

class RegularEmployee : public Employee {
public:
    int hours, rate;

    void get() override;
    int calculateSalary() override;
};

#endif
