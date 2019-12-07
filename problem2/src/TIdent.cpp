

#include "TIdent.h"
#include <cmath>

TIdent::TIdent(const TOptions &opt) {}
double TIdent::GetDeriv(double x_value) {
    return 1;
}
double TIdent::operator()(double x_value) {
    return x_value;
}
std::string TIdent::ToString() {
    return "x";
}