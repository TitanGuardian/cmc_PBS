#pragma once

#include "Function.h"


class TPower : public TFunction {
    double power;
public:

    explicit TPower (double _power=1);
    TPower (const TPower& copy_from) = default;
    TPower (TPower&& move_from) = default;
    TPower(const TOptions& opt);


    double operator() (double x_value) override ;
    double GetDeriv (double x_value) override ;
    std::string ToString () override ;
};
