#include "TConst.h"
#include <sstream>
#include <iomanip>

TConst::TConst(const TOptions &opt) {
    if (opt.get().empty()) 
        value = 0;
    else  
        value = opt.get()[0];
}
TConst::TConst(double _value): value(_value) {}
double TConst::GetDeriv(double x_value) {
    return 0;
}
double TConst::operator()(double x_value) {
    return value;
}
std::string TConst::ToString() {
    std::ostringstream  oss;
    oss<<std::setprecision(PRECISION)<<value;
    return oss.str();
}
