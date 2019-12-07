#include "TExp.h"
#include <sstream>
#include <iomanip>
#include <cmath>

TExp::TExp(const TOptions &opt): alpha(opt.get()[0]) {}
TExp::TExp(double _alpha) : alpha(_alpha) {}
double TExp::GetDeriv(double x_value) {
    return alpha*(std::exp(alpha*x_value));
}
double TExp::operator()(double x_value) {
    return std::exp(alpha*x_value);
}
std::string TExp::ToString() {
    std::ostringstream  oss;
    oss.precision(PRECISION);
    oss<<"e^("<<std::setprecision(PRECISION)<<alpha<<"*x)";
    return oss.str();
}
