#pragma once


#include "Function.h"

class TPolynomial : public TFunction {
    std::vector<double> polynom_coefficents;
public:
    TPolynomial();
    explicit TPolynomial(std::vector<double> _polynom_coefficents);
    explicit TPolynomial(std::vector<double>&& _polynom_coefficents);
    TPolynomial (const TPolynomial& copy_from) = default;
    TPolynomial (TPolynomial&& move_from) = default;
    TPolynomial (const TOptions& opt);

    double operator() (double x_value) override ;
    double GetDeriv (double x_value) override ;
    std::string ToString () override ;
};
