#pragma once

#include "Function.h"

class TConst : public TFunction {
    double value;
public:
    TConst(double _value=0);
    TConst (const TConst& copy_from) = default;
    TConst (TConst&& move_from) = default;
    TConst(const TOptions& opt);


    double operator() (double x_value) override ;
    double GetDeriv (double x_value) override ;
    std::string ToString () override ;
};