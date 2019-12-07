#pragma once

#include "Function.h"


class TExp : public TFunction {
    double alpha; // e^(alpha*x)

public:
    explicit TExp (double alpha=1);
    TExp (const TExp& copy_from) = default;
    TExp (TExp&& move_from) = default;
    TExp (const TOptions& opt);


    double operator() (double x_value) override ;
    double GetDeriv (double x_value) override ;
    std::string ToString () override ;
};