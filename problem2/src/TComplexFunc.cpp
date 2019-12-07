#include "TComplexFunc.h"

TComplexFunc::TComplexFunc(TFunctionPtr _f, TFunctionPtr _g, Operation _op) {
    f = std::move(_f);
    g = std::move(_g);
    op = _op;
}

double TComplexFunc::operator()(double x_value) {
    switch (op) {
        case plus:
            return (*f)(x_value)+(*g)(x_value);
        case minus:
            return (*f)(x_value)-(*g)(x_value);
        case multiply:
            return (*f)(x_value)*(*g)(x_value);
        case division:
            return (*f)(x_value)/(*g)(x_value);
    }
    throw std::logic_error("TComplexFunc hasn't that operation");
}

double TComplexFunc::GetDeriv(double x_value) {
    switch (op) {
        case plus:
            return (*f).GetDeriv(x_value)+(*g).GetDeriv(x_value);
        case minus:
            return (*f).GetDeriv(x_value)-(*g).GetDeriv(x_value);
        case multiply:
            return (*f).GetDeriv(x_value)*(*g)(x_value)+(*f)(x_value)*(*g).GetDeriv(x_value);
        case division:
            double g_x = (*g)(x_value);
            return ((*f).GetDeriv(x_value)*g_x-(*g).GetDeriv(x_value)*(*f)(x_value))/(g_x*g_x);
    }
    throw std::logic_error("TComplexFunc hasn't that operation");
}

std::string TComplexFunc::ToString() {
    std::string operation;
    switch (op) {
        case plus: operation = " + ";
            break;
        case minus: operation = " - ";
            break;
        case multiply: operation = " * ";
            break;
        case division: operation = " / ";
            break;
        default:
            throw std::logic_error("TComplexFunc hasn't that operation");
    }
    return "("+f->ToString()+")"+operation+"("+g->ToString()+")";
}
