#pragma once

#include "Function.h"

class TComplexFunc : public TFunction {

private:
    TFunctionPtr f;
    TFunctionPtr g;
    Operation op;
public:
    TComplexFunc (TFunctionPtr _f, TFunctionPtr _g, Operation _op);
    double operator() (double x_value) override ;
    double GetDeriv (double x_value) override ;
    std::string ToString () override ;

};