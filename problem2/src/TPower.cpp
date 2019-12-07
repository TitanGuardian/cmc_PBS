#include "TPower.h"
#include <sstream>
#include <iomanip>
#include <cmath>

TPower::TPower(const TOptions &opt){
    if (opt.get().empty()) 
        power = 0;
    else  
        power = opt.get()[0];
}
TPower::TPower(double _power) : power(_power) {}
double TPower::GetDeriv(double x_value) {
    return power*(std::pow(x_value,power-1));
}
double TPower::operator()(double x_value) {
    return std::pow(x_value,power);
}
std::string TPower::ToString() {
    std::ostringstream  oss;
    oss.precision(PRECISION);
    oss<<"x^("<<std::setprecision(PRECISION)<<power<<")";
    return oss.str();
}