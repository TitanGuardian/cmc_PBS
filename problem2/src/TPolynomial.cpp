//
// Created by davo1 on 04.12.2019.
//

#include "TPolynomial.h"
#include <cmath>
#include <sstream>
#include <iomanip>

TPolynomial::TPolynomial() {
    polynom_coefficents.push_back(0);
}
TPolynomial::TPolynomial(const TOptions &opt): polynom_coefficents(opt.get()) {
    if(polynom_coefficents.empty()) polynom_coefficents.push_back(0);
}
TPolynomial::TPolynomial(std::vector<double> _polynom_coefficents)
        : polynom_coefficents(std::move(_polynom_coefficents)) {}
TPolynomial::TPolynomial(std::vector<double>&& _polynom_coefficents)
        : polynom_coefficents(std::move(_polynom_coefficents)) {}
double TPolynomial::GetDeriv(double x_value) {
    double result=0;
    for (size_t itr  = 1 ; itr < polynom_coefficents.size() ;  ++itr)  {
        result += polynom_coefficents[itr]*(itr)*std::pow(x_value, itr-1);
    }
    return result;
}
double TPolynomial::operator()(double x_value) {
    double result=0;
    for (size_t itr  = 0 ; itr < polynom_coefficents.size() ;  ++itr)  {
        result += polynom_coefficents[itr]*std::pow(x_value, itr);
    }
    return result;
}
std::string TPolynomial::ToString() {
    std::ostringstream oss;

    oss << std::setprecision(PRECISION) <<polynom_coefficents[0];
    for (size_t itr  = 1 ; itr < polynom_coefficents.size() ;  ++itr)  {
        oss << " + " << std::setprecision(PRECISION) <<polynom_coefficents[itr]<<"*"<<
            "x^" + std::to_string(itr);
    }
    return oss.str();
}